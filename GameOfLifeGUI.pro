#-------------------------------------------------
#
# Project created by QtCreator 2014-01-12T13:18:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameOfLifeGUI
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11


SOURCES += src/main.cpp\
    src/cell.cpp \
    src/cellgrid.cpp \
    src/mainwindow.cpp

HEADERS  += \
    src/cell.h \
    src/cellgrid.h \
    src/mainwindow.h

FORMS += \
    mainwindow.ui

