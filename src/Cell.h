/**
	Author: James Hollister
**/

// Cell class to represent a cell that is either alive or dead on a grid
#pragma once

#include <QtCore>
#include <QtWidgets>

class Cell : public QGraphicsWidget {


private:
    Q_OBJECT

	int row;
	int column;
	bool status;
    int cell_size;
	const int MIN_NEIGHBORS = 1;
	const int MAX_NEIGHBORS = 4;
    const int NEW_CELL = 3;
public:
    Cell(int row, int column, bool status, int size);
    Cell();
    int getRow() const { return row; }
    int getColumn() const { return column; }
    bool isAlive() const { return status; }
    bool isAlive(int numNeighbors) const;
    void updateCell(bool status);
    void copy(const Cell&);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};
