/**
	Author: James Hollister
**/

#include "CellGrid.h"

// Initial board of all alive cells
CellGrid::CellGrid(int width, int height, int cell_size) {
    this->width = width;
    this->height = height;
    this->numCells = width * height;
    for(int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            Cell* cell = new Cell(i, j, true, cell_size);
            cells << cell;
        }
    }
}

// Updates the grid all at once by storing the status of each cell in a separate list.
void CellGrid::update() {
    QList<bool> status; // stores the new status of each cell
    for (int i = 0; i < numCells; i++) {
        status.append(cells[i]->isAlive(numNeighbors(*cells[i])));
    }
    for (int i = 0; i < numCells; i++) {
        cells[i]->updateCell(status[i]);
    }

}

// Gets the number of neighboring cells alive
int CellGrid::numNeighbors(const Cell& cell) {
	// Eight possible neighbors
	int row = cell.getRow();
	int col = cell.getColumn();
	int total = 0;
	if (row > 0) {
		//check cells above
        if (cells[fromRowCol(row - 1, col)]->isAlive())
			total++;
		if (col > 0) {
            if (cells[fromRowCol(row - 1, col - 1)]->isAlive())
				total++;
		}
		if (col < (width - 1)) {
            if (cells[fromRowCol(row - 1, col + 1)]->isAlive())
				total++;
		}
	}
	if (row < (height - 1)) {
		// check cells below
        if (cells[fromRowCol(row + 1, col)]->isAlive())
			total++;
		if (col > 0) {
            if (cells[fromRowCol(row + 1, col - 1)]->isAlive())
				total++;
		}
		if (col < (width - 1)) {
            if (cells[fromRowCol(row + 1, col + 1)]->isAlive())
				total++;
		}
	}
	// check cells horizontal
	if (col > 0) {
        if (cells[fromRowCol(row, col - 1)]->isAlive())
			total++;
	}
	if (col < (width - 1)) {
        if (cells[fromRowCol(row, col + 1)]->isAlive())
			total++;
	}
	return total;
}

int CellGrid::fromRowCol(int row, int col) {
	return (row * width ) + col;
}

QList<Cell *>* CellGrid::getList() {
    return &cells;
}

CellGrid::~CellGrid() {
    for (int i = 0; i < cells.length(); i++) {
        delete cells[i];
    }
}
