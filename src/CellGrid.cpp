/**
	Author: James Hollister
**/

#include "CellGrid.h"
#include <QtCore>
#include <QWidget>

// Initial board of all alive cells
CellGrid::CellGrid(int width, int height, int cell_size) {
    this->width = width;
    this->height = height;
    this->numCells = width * height;
    for(int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            cells.append(Cell(i, j, true, cell_size));
        }
    }
}

// Updates the grid all at once by storing results in a copy.
void CellGrid::update() {
    QList<Cell> new_cells{ cells };
	for (int i = 0; i < numCells; i++) {
		new_cells[i].updateCell(numNeighbors(cells[i]));
	}
	cells = new_cells;
}

// Gets the number of neighboring cells alive
int CellGrid::numNeighbors(Cell cell) {
	// Eight possible neighbors
	int row = cell.getRow();
	int col = cell.getColumn();
	int total = 0;
	if (row > 0) {
		//check cells above
		if (cells[fromRowCol(row - 1, col)].isAlive())
			total++;
		if (col > 0) {
			if (cells[fromRowCol(row - 1, col - 1)].isAlive())
				total++;
		}
		if (col < (width - 1)) {
			if (cells[fromRowCol(row - 1, col + 1)].isAlive())
				total++;
		}
	}
	if (row < (height - 1)) {
		// check cells below
		if (cells[fromRowCol(row + 1, col)].isAlive())
			total++;
		if (col > 0) {
			if (cells[fromRowCol(row + 1, col - 1)].isAlive())
				total++;
		}
		if (col < (width - 1)) {
			if (cells[fromRowCol(row + 1, col + 1)].isAlive())
				total++;
		}
	}
	// check cells horizontal
	if (col > 0) {
		if (cells[fromRowCol(row, col - 1)].isAlive())
			total++;
	}
	if (col < (width - 1)) {
		if (cells[fromRowCol(row, col + 1)].isAlive())
			total++;
	}
	return total;
}

int CellGrid::fromRowCol(int row, int col) {
	return (row * width ) + col;
}
