cmake_minimum_required(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
#find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/..")

set(PROJECT_SOURCES
        main.cpp
        ${CMAKE_SOURCE_DIR}/mathengine.cpp
        ${CMAKE_SOURCE_DIR}/mathengine.h
        MathEngineTest.cpp
)


add_executable(CalculatorTest ${PROJECT_SOURCES})

target_link_libraries(CalculatorTest PUBLIC gtest gtest_main pthread)

enable_testing()
add_test(CalculatorUnitTests CalculatorTests)
#target_link_libraries(CalculatorTest PUBLIC gtest gtest_main pthread PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

