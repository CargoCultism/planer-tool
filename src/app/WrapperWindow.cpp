#include "WrapperWindow.h"

#include <QApplication>
#include <QVBoxLayout>

#include "DatabaseManager.h"

WrapperWindow::WrapperWindow(QWidget *parent) : QMainWindow(parent) {
  auto centralWidget = new QWidget(this);

  this->m_table = new QTableWidget(4, 4, centralWidget);
  m_table->setHorizontalHeaderLabels({"#", "Auftragsnummer", "uuid", "Client"});

  this->m_buttonExit = new QPushButton("&exit", this);
  connect(m_buttonExit, &QPushButton::clicked, qApp, &QApplication::quit);

  auto mainLayout = new QVBoxLayout();
  mainLayout->addWidget(this->m_table);
  mainLayout->addWidget(this->m_buttonExit);
  centralWidget->setLayout(mainLayout);
  this->setCentralWidget(centralWidget);

  DatabaseManager dbm;
  dbm.open("/home/lr/.local/share/planer-tool/db1.sqlite");
  auto t1 = dbm.loadAll();
  for (int row = 0; const auto &r : t1) {
    QString tmp = QString::number(r.id);
    m_table->setItem(row, 0, new QTableWidgetItem(tmp));
    tmp = QString::number(r.internal_id);
    m_table->setItem(row, 1, new QTableWidgetItem(tmp));
    m_table->setItem(row, 2, new QTableWidgetItem(r.uuid));
    m_table->setItem(row, 3, new QTableWidgetItem(r.client));
    row++;
  }
}
