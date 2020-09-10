#include "target.h"

Target::Target(int formWidth, int formHeight, int sizeBlock) :
    mFormWidth(formWidth), mFormHeight(formHeight), mSizeBlock(sizeBlock)
{
    srand(time(0));
}

Target::~Target()
{
    while (mVectorPoint.size() > 0)
    {
        QPoint *p = mVectorPoint.back();
        delete p;
        mVectorPoint.pop_back();
    }
}

void Target::addRow()
{
    for (int i = 0; i < mVectorPoint.size(); i++)
    {
        mVectorPoint.at(i)->setY(mVectorPoint.at(i)->y() + mSizeBlock);
    }

    for (int i = 0; i < mFormWidth / mSizeBlock; i++)
    {
        if (rand() % 2)
        {
            mVectorPoint.push_back(new QPoint(i * mSizeBlock, 0));
        }
    }
}

void Target::addBlock(int tankX)
{
    int maxY = 0;
    bool isBlock = false;
    for (int i = 0; i < mVectorPoint.size(); i++)
    {
        if (mVectorPoint.at(i)->x() == tankX && mVectorPoint.at(i)->y() >= maxY)
        {
            maxY = mVectorPoint.at(i)->y();
            isBlock = true;
        }
    }

    if (isBlock)
        maxY += mSizeBlock;
    mVectorPoint.push_back(new QPoint(tankX, maxY));

    deleteRow();
}

void Target::deleteRow()
{
    int blockCountInRow = mFormWidth / mSizeBlock;
    int tempCount = 0;
    int y = 0;

    for (int i = 0; i < mVectorPoint.size(); ++i)
    {
        for (int j = 0; j < mVectorPoint.size(); ++j)
        {
            if (mVectorPoint.at(i)->y() == mVectorPoint.at(j)->y())
            {
                tempCount++;
            }
        }

        if (tempCount == blockCountInRow)
        {
            y = mVectorPoint.at(i)->y();
            for (int j = 0; j < mVectorPoint.size(); ++j)
            {
                if (y == mVectorPoint.at(j)->y())
                {
                    QPoint *p = mVectorPoint.at(j);
                    delete p;
                    mVectorPoint.erase(mVectorPoint.begin() + j);
                    j--;
                }
            }
            for (int j = 0; j < mVectorPoint.size(); ++j)
            {
                if (mVectorPoint.at(j)->y() > y)
                {
                    mVectorPoint.at(j)->setY(mVectorPoint.at(j)->y() - mSizeBlock);
                }
            }
            return;
        }

        tempCount = 0;
    }
}

bool Target::isGameOver()
{
    for (int i = 0; i < mVectorPoint.size(); ++i)
    {
        if (mVectorPoint.at(i)->y() >= mFormHeight - mSizeBlock * 3)
        {
            return true;
        }
    }
    return false;
}

QPoint Target::at(int index) const
{
    return *mVectorPoint.at(index);
}

int Target::sizeBlock() const
{
    return mSizeBlock;
}

int Target::countBlock() const
{
    return mVectorPoint.size();
}
