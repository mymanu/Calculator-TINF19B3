cmake_minimum_required(VERSION 3.16)
project(Calculator-TINF19B3)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.9.9\\5.9.9\\mingw53_32\\")

find_package(Qt5Widgets REQUIRED)

add_executable(
        Calculator-TINF19B3
        main.cpp
        app/classes/Calculation.cpp
        app/classes/Calculation.h
        app/classes/Logic.cpp
        app/classes/Logic.h)

target_link_libraries(Calculator-TINF19B3 Qt5::Widgets)