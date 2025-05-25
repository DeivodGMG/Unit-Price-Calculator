#include <QApplication>
#include "MainWindow.h"

int main(int argc, char **argv){

    QApplication app(argc, argv);
    auto *mainWindow = new  MainWindow(1600, 900);
    return app.exec();
}