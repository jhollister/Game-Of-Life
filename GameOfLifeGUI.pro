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
        src/CellGrid.cpp \
        src/Cell.cpp \

HEADERS  += src/Cell.h \
            src/CellGrid.h \
FORMS    #+= mainwindow.ui
