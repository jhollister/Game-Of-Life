#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>

const int RECT_SIZE = 30;
const int NUM_RECTANGLES = 16;
const int GRID_SIZE = RECT_SIZE*NUM_RECTANGLES;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGraphicsScene scene(0, 0, GRID_SIZE, GRID_SIZE);
    scene.setBackgroundBrush(Qt::white);


    return app.exec();
}
