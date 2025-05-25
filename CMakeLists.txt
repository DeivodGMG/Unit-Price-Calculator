cmake_minimum_required(VERSION 3.14)

project(miApp)

add_executable(miApp main.cpp)

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

target_link_libraries(miApp PUBLIC
Qt6::Core
Qt6::Gui
Qt6::Widgets
)