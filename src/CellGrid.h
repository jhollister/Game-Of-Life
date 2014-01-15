/**
	Author: James Hollister
**/
#pragma once
#include "Cell.h"
#include <QtCore>


class CellGrid {
private:
	int width;
	int height;
    QList<Cell> cells;
	int numCells;
	int fromRowCol(int, int);

public:
    CellGrid(int, int, int);
	void update();
	int numNeighbors(Cell cell);
	void printGrid();
    QList<Cell> getList() { return cells; }
};
