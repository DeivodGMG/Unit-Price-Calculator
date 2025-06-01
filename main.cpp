#include <QApplication>
#include <QTextStream>
#include "calculator.h" //llamar mi archivo de cabezera .h

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);
//Creando mi objeto ventana
  Calculator window;
//asignar titulo
  window.setWindowTitle("QLabel");
  //mostrar ventana
  window.show();
//Iniciar los loops de eventos o de slot de Qt
  return app.exec();
}
