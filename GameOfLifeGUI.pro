#-------------------------------------------------
#
# Project created by QtCreator 2014-01-12T13:18:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameOfLifeGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    CellGrid.cpp \
    src/Cell.cpp \
    src/CellGrid.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS  += mainwindow.h \
    Cell.h \
    CellGrid.h \
    src/Cell.h \
    src/CellGrid.h \
    src/mainwindow.h

FORMS    += mainwindow.ui
