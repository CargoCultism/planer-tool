#include <QApplication>

#include "WrapperWindow.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  WrapperWindow wrapper;
  wrapper.show();
  app.exec();
}
