#ifndef SECONDSTEP_COMPARE_H
#define SECONDSTEP_COMPARE_H

#include <cstdlib>
#include <ctime>

class Compare {
public:
    bool compareResults(int length, int maxHeight, int quantityOfTries);
    int* generateInput(int length, int maxHeight);
};


#endif //SECONDSTEP_COMPARE_H
