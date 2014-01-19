#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupGrid(rectInRow, RECT_SIZE);
    thread = new GameThread(grid);
    isRunning = false;

}

MainWindow::~MainWindow()
{
    delete thread;
    delete ui;

}

void MainWindow::setupGrid(int rectInRow, int rectSize) {
    int width = rectInRow*rectSize;
    int height = width;
    scene = new QGraphicsScene(0, 0, width, height);
    grid = new CellGrid(rectInRow, rectInRow, rectSize);
    addGrid(*scene, *grid);
    view = new QGraphicsView(scene);
    ui->horizontalLayout->addWidget(view);
    setFixedSize(sizeHint());
}

// Adds a list of cells from grid to scene
void MainWindow::addGrid(QGraphicsScene &scene, CellGrid &grid) {
    QList<Cell*>* cell_list = grid.getList();
    for(int i = 0; i < cell_list->length(); i++) {
        scene.addItem(cell_list->at(i));
    }
}

void MainWindow::on_actionStart_triggered()
{
    //update grid life
    if (!isRunning) {
        thread->start();
        isRunning = true;
        //QString stop = "Stop";
        ui->actionStart->setText("Stop");
    }
    else {
        thread->exit(0);
        isRunning = false;
        ui->actionStart->setText("Start");
    }
}


void MainWindow::on_actionSmall_triggered()
{
    //small grid
}

void MainWindow::on_actionLarge_triggered()
{
    rectInRow = 32;
    delete view;
    setupGrid(rectInRow, RECT_SIZE);
}
