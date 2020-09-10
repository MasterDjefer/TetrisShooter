#include "tank.h"

Tank::Tank(int formWidth, int formHeight, int sizeBlock) :
    mFormWidth(formWidth), mFormHeight(formHeight), mSizeBlock(sizeBlock)
{
    mX = ((mFormWidth / 2) / mSizeBlock) * mSizeBlock - mSizeBlock;
    mY = mFormHeight - mSizeBlock * 2;

    mVectorPoint.push_back(new QPoint(mX + mSizeBlock, mY));
    mVectorPoint.push_back(new QPoint(mX, mY + mSizeBlock));
    mVectorPoint.push_back(new QPoint(mX + mSizeBlock, mY + mSizeBlock));
    mVectorPoint.push_back(new QPoint(mX + mSizeBlock * 2, mY + mSizeBlock));
}

Tank::~Tank()
{
    while (mVectorPoint.size() > 0)
    {
        QPoint *p = mVectorPoint.back();
        delete p;
        mVectorPoint.pop_back();
    }
}

int Tank::sizeBlock() const
{
    return mSizeBlock;
}

QPoint Tank::at(int index) const
{
    return *mVectorPoint.at(index);
}

int Tank::countBlock() const
{
    return mVectorPoint.size();
}

int Tank::headX() const
{
    return mVectorPoint.front()->x();
}

void Tank::moveLeft()
{
    if (mX + mSizeBlock > 0)
    {
        mX -= mSizeBlock;
        for (int i = 0; i < mVectorPoint.size(); ++i)
        {
            mVectorPoint.at(i)->setX(mVectorPoint.at(i)->x() - mSizeBlock);
        }
    }
}

void Tank::moveRight()
{
    if (mX + mSizeBlock * 2 < mFormWidth)
    {
        mX += mSizeBlock;
        for (int i = 0; i < mVectorPoint.size(); ++i)
        {
            mVectorPoint.at(i)->setX(mVectorPoint.at(i)->x() + mSizeBlock);
        }
    }
}
