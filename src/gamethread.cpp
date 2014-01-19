#include "gamethread.h"

GameThread::GameThread(CellGrid* grid, QObject *parent) :
    QThread(parent) {

    this->grid = grid;
}

void GameThread::run() {
    while(true) {
        grid->update();
        msleep(250);
    }
}
