#ifndef TARGET_H
#define TARGET_H
#include <QVector>
#include <QPoint>
#include <cstdlib>
#include <ctime>
#include <QDebug>

class Target
{
private:
    const int mFormWidth;
    const int mFormHeight;
    const int mSizeBlock;
    QVector<QPoint*> mVectorPoint;

public:
    Target(int formWidth, int formHeight, int sizeBlock);
    ~Target();
    void addRow();
    void addBlock(int tankX);
    void deleteRow();
    bool isGameOver();
    QPoint at(int index) const;
    int sizeBlock() const;
    int countBlock() const;
};

#endif // TARGET_H
