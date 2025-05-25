#ifndef MAIN_WINDOW_H //Si no se ha definido
#define MAIN_WINDOW_H // Define el MAIN_WINDOW.h
//Las librerias que vamos a utilizar para desarrollar la app
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <iostream>
class MainWindow : public QMainWindow{
    private:
        int width, heigth, counter;
    public:
    //Generar el constructor cada vez que se instancia el objeto
        MainWindow(int w, int h): width(w), heigth(h), counter(0){;
        //Setea los valores de la resolucion
            this->setMinimumSize(this->width, this->heigth);
            this->setMaximumSize(this->width, this->heigth);
        //Muestra la ventana
            this->show();
            std::cout << "\n\t Ventana creada" << std::endl;
}
//Aqui declaramos los metodos
void setupComponent();
};
#endif //Cerrar el if