#include "WrapperWindow.h"

#include <QVBoxLayout>

WrapperWindow::WrapperWindow(QWidget *parent) : QMainWindow(parent) {
  auto centralWidget = new QWidget(this);

  this->m_table = new QTableWidget(4, 3, centralWidget);
  m_table->setHorizontalHeaderLabels({"#", "Wer", "Was"});
  m_table->insertRow(0);
  m_table->setItem(0, 0, new QTableWidgetItem("0"));
  m_table->setItem(0, 1, new QTableWidgetItem("Boden KG"));
  m_table->setItem(0, 2, new QTableWidgetItem("Torf"));

  auto mainLayout = new QVBoxLayout();
  mainLayout->addWidget(this->m_table);
  centralWidget->setLayout(mainLayout);
  this->setCentralWidget(centralWidget);
}
