#include "collatzcounter.h"
#include <atomic>
#include <QDebug>
#include <QtConcurrent/QtConcurrent>
CollatzCounter::CollatzCounter(long long n,int numThreads) : n(n),numThreads(numThreads),
    maxSteps(0),maxNum(0),threadsFinished(0),stopFlag(false) {}

CollatzCounter::~CollatzCounter() {}

void CollatzCounter::StartCalc()
{
    stopFlag.store(false);

    threadsFinished.store(0);

    int elem_for_thread = n / numThreads;

    QList<QFuture<void>> futures;

    for (size_t i = 0; i < numThreads; ++i)
    {
        size_t start = i* elem_for_thread+1;
        size_t end = (i == numThreads - 1) ? n : start + elem_for_thread - 1;


        futures.append(QtConcurrent::run([this,start,end]()
                                         {findMaxLen(start,end);
         }));
    }

     for(auto& future :futures)
        future.waitForFinished();
}

void CollatzCounter::StopCalc()
{
    if (stopFlag.load())
        return;
    auto endTime = std::chrono::high_resolution_clock::now();
    auto timeDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    int timeMS = timeDuration.count();
    stopFlag.store(true);
    qDebug() <<"time - "<< timeMS;
    emit calcFinished(maxNum,maxSteps,timeMS);
    qDebug() << "Calculation stopped by me. Max steps: " << maxSteps;
}

long long CollatzCounter::countOfNumbers(long long num)
{
    long long steps = 1;
    while(num != 1)
    {
        if (num % 2 == 0)
        {
            num /= 2;
            steps++;
        }
        else
        {
            num = (num * 3 + 1) / 2;
            steps += 2;
        }
        if(num>std::numeric_limits<long long>::max())
        {
            emit calcFinished(-1,-1,-1);
            stopFlag.store(true);
             return steps;
        }
    }
    return steps;
}

void CollatzCounter::findMaxLen(int start,int end)
{
    long long tempNum = start;
    long long tempSteps = 0;
    startTime = std::chrono::high_resolution_clock::now();

    for (size_t i = start; i <= end; ++i)
    {
        long long steps = countOfNumbers(i);

        if(stopFlag.load())
            return;

        if (steps > tempSteps)
        {
            tempSteps = steps;
            tempNum = i;
        }
    }

    if (tempSteps > maxSteps.load())
    {
        maxSteps.store (tempSteps);
        maxNum.store (tempNum);
    }


    threadsFinished++;

    if(threadsFinished == numThreads)
    {
        StopCalc();
    }

    qDebug() << "Calculation finished. Max steps: " << maxSteps;
}


