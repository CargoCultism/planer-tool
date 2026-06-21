#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>

class WrapperWindow : public QMainWindow {
  Q_OBJECT

  QTableWidget *m_table;
  QPushButton *m_buttonExit;

public:
  WrapperWindow(QWidget *parent = nullptr);
  ~WrapperWindow() = default;
};
