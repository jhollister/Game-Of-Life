/**
	Author: James Hollister
**/

#include "CellGrid.h"
#include <iostream>
#include <vector>
#include <string>

// Default setup for testing.
CellGrid::CellGrid() {
	std::string cell_setup =
		"XXXXXX\nXXOOOX\nXOOOXX\nXXXXXX";
	int row = 0;
	int col = 0;

	for (char& c : cell_setup) {
		if (c == 'O') {
			cells.push_back(Cell(row, col, true));
			col++;
		}
		if (c == 'X') {
			cells.push_back(Cell(row, col, false));
			col++;	
		}
		if (c == '\n') {
			row++;
			col = 0;
		}
	}
	row++;
	this->width = col;
	this->height = row;
	this->numCells = row * col;
}

// Updates the grid all at once by storing results in a copy.
void CellGrid::update() {
	std::vector<Cell> new_cells{ cells };
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

void CellGrid::printGrid() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (cells[fromRowCol(i, j)].isAlive()) {
				std::cout << "X";
			}
			else {
				std::cout << "O";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}