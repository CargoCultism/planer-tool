#include <QApplication>

#include "WrapperWindow.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  WrapperWindow wrapper;
  wrapper.resize(500, 500);
  wrapper.show();
  app.exec();
}
