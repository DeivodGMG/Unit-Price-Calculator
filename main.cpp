#include <QApplication>
#include <QMainWindow>
#include <iostream>

int main(int argc, char **argv){
    //Instanciar el objeto
    QApplication app (argc, argv);
    // Crea un nuevo objeto
    auto *mainWindow = new QMainWindow();
    //Configura la resolucion de la ventana
    mainWindow->setMinimumSize(1600, 900);
    //Muestra la interfaz principal
    mainWindow->show();
    //Devuelve el valor de la ejecucion de la aplicacion
    return app.exec();
}