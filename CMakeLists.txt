cmake_minimum_required(VERSION 3.16)
project(Calculator-TINF19B3)

set(CMAKE_CXX_STANDARD 14)

find_package(Qt5Widgets REQUIRED)

set(CMAKE_PREFIX_PATH "/usr/bin/qmake")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(
        Calculator-TINF19B3
        main.cpp
        app/classes/Calculation.cpp
        app/classes/Calculation.h
        app/classes/Logic.cpp
        app/classes/Logic.h
        app/classes/CalculatorGUI.cpp
        app/classes/CalculatorGUI.h
)

target_link_libraries(Calculator-TINF19B3 Qt5::Widgets)