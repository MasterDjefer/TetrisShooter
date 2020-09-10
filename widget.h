#ifndef WIDGET_H
#define WIDGET_H
#include "tank.h"
#include "target.h"
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget();
    ~Widget();

private:
    Tank *mTank;
    Target *mTarget;
    QTimer *mTimerTargetMove;

private:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

private slots:
    void onTimeOutTargetMove();
};

#endif // WIDGET_H
