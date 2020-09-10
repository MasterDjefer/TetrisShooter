#ifndef TANK_H
#define TANK_H
#include <QVector>
#include <QPoint>

class Tank
{
private:
    QVector<QPoint*> mVectorPoint;
    int mX;
    int mY;
    const int mFormWidth;
    const int mFormHeight;
    const int mSizeBlock;
public:
    Tank(int formWidth, int formHeight, int sizeBlock);
    ~Tank();
    int sizeBlock() const;
    QPoint at(int index) const;
    int countBlock() const;
    int headX() const;
    void moveLeft();
    void moveRight();
};

#endif // TANK_H
