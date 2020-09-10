#include "widget.h"

Widget::Widget()
{
    int sizeBlock = 30;
    this->setFixedSize(sizeBlock * 13, sizeBlock * 24);

    mTank = new Tank(this->width(), this->height(), sizeBlock);
    mTarget = new Target(this->width(), this->height(), sizeBlock);

    mTimerTargetMove = new QTimer(this);
    connect(mTimerTargetMove, &QTimer::timeout, this, &Widget::onTimeOutTargetMove);
    mTimerTargetMove->start(2000);
}

Widget::~Widget()
{
    delete mTank;
    delete mTarget;
    delete mTimerTargetMove;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setBrush(QBrush(Qt::gray));
    for (int i = 0; i < mTank->countBlock(); ++i)
    {
        painter.drawRect(mTank->at(i).x(), mTank->at(i).y(), mTank->sizeBlock(), mTank->sizeBlock());
    }

    painter.setBrush(QBrush(Qt::blue));
    for (int i = 0; i < mTarget->countBlock(); ++i)
    {
        painter.drawRect(mTarget->at(i).x(), mTarget->at(i).y(),
                         mTarget->sizeBlock(), mTarget->sizeBlock());
    }
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_4)
    {
        mTank->moveLeft();
    }else
    if (event->key() == Qt::Key_6)
    {
        mTank->moveRight();
    }else
    if (event->key() == Qt::Key_5)
    {
        mTarget->addBlock(mTank->headX());
    }else
    if (event->key() == Qt::Key_2)
    {
        mTarget->addRow();
    }

    this->update();
}

void Widget::onTimeOutTargetMove()
{
    if (mTarget->isGameOver())
    {
        this->close();
    }
    mTarget->addRow();

    this->update();
}
