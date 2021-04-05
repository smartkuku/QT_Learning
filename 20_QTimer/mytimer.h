#ifndef MYTIMER_H
#define MYTIMER_H
#include <QTimer>

class MyTimer : public QObject
{
    Q_OBJECT
public:
    explicit MyTimer(QObject *parent);// = nullptr);
    QTimer *timer;

public slots:
    void MyTimerSlot();

signals:

};

#endif // MYTIMER_H
