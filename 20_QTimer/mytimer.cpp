#include "mytimer.h"
#include <QDebug>

MyTimer::MyTimer(QObject *parent) : QObject(parent)
{
    // Create a timer
    timer = new QTimer(this);

    // Setup signal and slot
    connect(timer, SIGNAL(timeout()), this, SLOT(MyTimerSlot()));

    // msec
    timer->start(1000);
}

void MyTimer::MyTimerSlot()
{
    qDebug()<<"Timer...";
}
