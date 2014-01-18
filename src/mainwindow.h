#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "cellgrid.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //void on_pushButton_clicked();

    void on_actionStart_triggered();

private:
    void addGrid(QGraphicsScene &scene, CellGrid &grid);
    void setupGrid(int, int);
    Ui::MainWindow *ui;
    QStringListModel model;
    QGraphicsScene* scene;
    QGraphicsView* view;
    CellGrid* grid;
    const int RECT_SIZE = 15; // rectangle pixel size
    int rectInRow = 16;  // Number of rectangles in a row
};

#endif // MAINWINDOW_H
