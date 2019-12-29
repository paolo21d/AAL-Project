#ifndef SECONDSTEP_COMPARE_H
#define SECONDSTEP_COMPARE_H

#include <cstdlib>
#include <ctime>
#include <utility>

class Compare {
public:
    bool compareResults(int length, int maxHeight, int quantityOfTries);
    int* generateInput(int length, int maxHeight);
    //return optimalTime, brutforceTime
    std::pair<long long int, long long int> statisticTimeBoth(int length, int maxHeight, int quantityOfTries);
    long long int statisticTimeOptimal(int length, int maxHeight, int quantityOfTries);
    long long int statisticTimeBrutforce(int length, int maxHeight, int quantityOfTries);
};


#endif //SECONDSTEP_COMPARE_H
