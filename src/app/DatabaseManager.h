#pragma once
#include <QSqlDatabase>
#include <QString>
#include <QUuid>
#include <QList>

struct PlanerRecord {
    int id;
    int internal_id;
    QString uuid;
    QString client;
    // QString origin;
    // QString destination;
    // QString freight;
    // QString type;
    // int FE;
    // QString Compensation;
    // bool isCompleted;
    // QString days;
    // QString hour;
    // bool isExpress;
};

class DatabaseManager {
public:
    bool open(const QString &path);
    void close();

    bool createSchema();
    QList<PlanerRecord> loadAll();
    bool saveAll(const QList<PlanerRecord>& records);
    bool upsert(const PlanerRecord &record);

private:
    QSqlDatabase m_db;
};
