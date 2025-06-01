#include <QApplication>
#include <QTextStream>
#include "calculator.h"

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  Calculator window;

  window.setWindowTitle("QLabel");
  window.show();

  return app.exec();
}
