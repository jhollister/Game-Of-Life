#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include "cell.h"
#include "cellgrid.h"

const int RECT_SIZE = 15;
const int NUM_RECTANGLES = 16;
const int GRID_SIZE = RECT_SIZE*NUM_RECTANGLES;

void addGrid(QGraphicsScene &scene, CellGrid &grid) {
    QList<Cell*>* cell_list = grid.getList();
    for(int i = 0; i < cell_list->length(); i++) {
        scene.addItem(cell_list->at(i));
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
//    QGraphicsScene scene(0, 0, GRID_SIZE, GRID_SIZE);
//    scene.setBackgroundBrush(Qt::white);
//    CellGrid grid(NUM_RECTANGLES, NUM_RECTANGLES, RECT_SIZE);
//    addGrid(scene, grid);
//    QGraphicsView window(&scene);
    MainWindow window;
    window.show();

    return app.exec();
}
