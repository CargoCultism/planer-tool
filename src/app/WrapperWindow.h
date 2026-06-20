#pragma once

#include <QMainWindow>
#include <QTableWidget>

class WrapperWindow : public QMainWindow {
  Q_OBJECT

  QTableWidget *m_table;

public:
  WrapperWindow(QWidget *parent = nullptr);
  ~WrapperWindow() = default;
};
