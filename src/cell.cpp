/**
	Author: James Hollister
**/
#include "cell.h"
#include <QtWidgets>

Cell::Cell(int row, int column, bool status, int size) {
    this->row = row;
    this->column = column;
    this->status = status;
    this->cell_size = size;
    this->cell_color = Qt::lightGray;
    setAcceptedMouseButtons(Qt::LeftButton);
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
    painter->drawRect(boundingRect());
    painter->fillRect(boundingRect(), cell_color);
}


QRectF Cell::boundingRect() const {
    return QRectF(cell_size * row, cell_size * column, cell_size, cell_size);
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);
    if(status) {
        cell_color = Qt::lightGray;
        status = false;
    }
    else {
        cell_color = Qt::darkGray;
        status = true;
    }
    update();
}
