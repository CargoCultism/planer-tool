#include <QApplication>

#include "WrapperWindow.h"

#include <spdlog/spdlog.h>

int main(int argc, char *argv[]) {
  spdlog::info("Init");
  QApplication app(argc, argv);

  WrapperWindow wrapper;
  wrapper.resize(500, 500);
  wrapper.show();
  app.exec();
}
