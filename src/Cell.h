/**
	Author: James Hollister
**/

// Cell class to represent a cell that is either alive or dead on a grid
#pragma once

#include <QtCore>
#include <QtWidgets>

class Cell : public QGraphicsWidget {

  // Q_OBJECT
private:
	int row;
	int column;
	bool status;
    int cell_size;
	const int MIN_NEIGHBORS = 1;
	const int MAX_NEIGHBORS = 4;
	const int REPRODUCTION = 3;
public:
    Cell(int row, int column, bool status, int size);
	int getRow() { return row; }
	int getColumn() { return column; }
	bool isAlive() { return status; }
	void updateCell(int numNeighbors);
	Cell& operator=(const Cell&);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};
