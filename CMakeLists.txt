cmake_minimum_required(VERSION 3.14) #La version del cmake
# Nombre del proyecto y el lenguaje de programacion que utilizara
project(UnitPriceCalculator LANGUAGES CXX)
#Incluye automaticamente archivos de cabecera (.h)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#Procesa archivos UI
#Genera el codigo necesario para los eventos y slots
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
#Procesa imagenes o sonidos embebidos
set(CMAKE_AUTORCC ON)

#La version estandar minima para ejecutar C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#Agregando paquetes al Qt
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
#Nombre del binario y los archivos que compilara
add_executable(UnitPriceCalculator
    main.cpp
    calculator.cpp
)
#Enlazando las librerias de Qt
target_link_libraries(UnitPriceCalculator PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
