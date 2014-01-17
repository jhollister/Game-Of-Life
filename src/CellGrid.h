/**
	Author: James Hollister
**/
#pragma once
#include "Cell.h"
#include <QList>


class CellGrid {
private:
	int width;
	int height;
    QList<Cell *> cells;
	int numCells;
	int fromRowCol(int, int);

public:
    CellGrid(int, int, int);
    ~CellGrid();
	void update();
    int numNeighbors(const Cell& cell);
	void printGrid();
    QList<Cell *>* getList();
};
