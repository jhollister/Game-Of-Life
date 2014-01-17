/**
	Author: James Hollister
**/
#include "Cell.h"
#include <QWidget>
#include <QtCore>

Cell::Cell(int row, int column, bool status, int size) {
    this->row = row;
    this->column = column;
    this->status = status;
    this->cell_size = size;
    this->setGeometry(size * row, size * column, size, size);
}

Cell::Cell() {
    this->row = 0;
    this->column = 0;
    this->status = false;
    this->cell_size = 0;
    this->setGeometry(0, 0, 0,  0);
}

// Determines if a cell is alive given the amount of neighbors it has.
bool Cell::isAlive(int numNeighbors) const {
	if (numNeighbors <= MIN_NEIGHBORS) {
        return false;
	}
	if (numNeighbors >= MAX_NEIGHBORS) {
        return false;
	}
    if (!this->status && numNeighbors == NEW_CELL) {
        return true;
	}
    return false;
}

void Cell::updateCell(bool status) {
    this->status = status;
    // to-do: graphic stuff here(call paint?)
}

void Cell::copy(const Cell &copy_cell) {
	row = copy_cell.row;
	column = copy_cell.column;
	status = copy_cell.status;
    cell_size = copy_cell.cell_size;
}

void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    QPen pen(Qt::black, 3);
    painter->setPen(pen);
    painter->drawRect(rect());
    painter->fillRect(rect(), Qt::gray);
}

