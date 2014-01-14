/**
	Author: James Hollister
**/
#include "Cell.h"
#include <QWidget>
#include <QtCore>

// Determines if a cell is alive given the amount of neighbors it has.
void Cell::updateCell(int numNeighbors) {
	if (numNeighbors <= MIN_NEIGHBORS) {
		this->status = false;
	}
	if (numNeighbors >= MAX_NEIGHBORS) {
		this->status = false;
	}
	if (!this->status && numNeighbors == REPRODUCTION) {
		this->status = true;
	}
}

Cell& Cell::operator=(const Cell &copy_cell) {
	row = copy_cell.row;
	column = copy_cell.column;
	status = copy_cell.status;
	return *this;
}

void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    QPen pen(Qt::black, 3);
    painter->setPen(pen);
    painter->drawRect(rect());
    painter->fillRect(rect(), Qt::gray);
}
