#ifndef GAMETHREAD_H
#define GAMETHREAD_H

#include <QThread>
#include "cellgrid.h"

class GameThread : public QThread
{
    Q_OBJECT
private:
    CellGrid* grid;
    void run();

public:
    explicit GameThread(CellGrid* grid, QObject *parent = 0);

signals:

public slots:

};

#endif // GAMETHREAD_H
