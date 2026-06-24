#include "DatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool DatabaseManager::open(const QString &path) {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);
    if(!m_db.open()) {
        qWarning() << "Could not open DB:" << m_db.lastError().text();
        qWarning() << "Path: "<<path;
        return false;
    }
    return createSchema();
}

void DatabaseManager::close() {
    m_db.close();
}

bool DatabaseManager::createSchema() {
    QSqlQuery q(m_db);
    return q.exec(R"(
        CREATE TABLE IF NOT EXISTS records (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            internal_id INTEGER,
            uuid TEXT,
            client TEXT))");
}

QList<PlanerRecord> DatabaseManager::loadAll() {
    QList<PlanerRecord> result;
    QSqlQuery q("SELECT id, internal_id, uuid, client FROM records", m_db);
    while (q.next()) {
        result.append({ q.value(0).toInt(),
            q.value(1).toInt(),
                      q.value(2).toString(),
                      q.value(3).toString()
        });
    }
    return result;
}

bool DatabaseManager::saveAll(const QList<PlanerRecord> &records) {

    QSqlQuery q(m_db);
    m_db.transaction();
    q.exec("DELETE FROM records");
    q.prepare("INSERT INTO records (id, internal_id, uuid, client) VALUES (:id, :internal_id, :uuid, :client)");
    for (const auto  &r: records) {
        q.bindValue((":id"), r.id);
        q.bindValue((":internal_id"), r.internal_id);
        q.bindValue((":uuid"), r.uuid);
        q.bindValue((":client"), r.client);
        if(!q.exec()) {
            m_db.rollback();
            return false;
        }
    }
    return m_db.commit();
}
