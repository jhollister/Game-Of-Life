/**
	Author: James Hollister
**/
#pragma once
#include "Cell.h"
#include <vector>


class CellGrid {
private:
	int width;
	int height;
	std::vector<Cell> cells;
	int numCells;
	int fromRowCol(int, int);

public:
	CellGrid();
	void update();
	int numNeighbors(Cell cell);
	void printGrid();
};
