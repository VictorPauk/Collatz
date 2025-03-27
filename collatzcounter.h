#ifndef COLLATZCOUNTER_H
#define COLLATZCOUNTER_H

#include <QObject>

class CollatzCounter : public QObject
{
    Q_OBJECT
public:
    CollatzCounter(long long n, int numThreads);
    ~CollatzCounter();
    void StartCalc();
    void StopCalc();


signals:
    void calcFinished(long long maxNum, long long maxSteps, int timeMS);
private:
    long long n;
    int numThreads;
    bool isRunning;

    std::atomic<long long> maxSteps;
    std::atomic<long long> maxNum;
    std::atomic<int> threadsFinished;
    std::atomic<bool> stopFlag;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;

    long long countOfNumbers(long long num);
    void findMaxLen(int start,int end);

};

#endif // COLLATZCOUNTER_H
