//
// Created by paolo on 28.12.2019.
//

#ifndef SECONDSTEP_BRUTFORCERESOLVER_H
#define SECONDSTEP_BRUTFORCERESOLVER_H

#include <iostream>
#include <cmath>

class BrutforceResolver {
private:
    int lengthOfField;
    int *field;
    int wormHead, wormAss, maxCapacity;

public:
    int getResult(int length, int *field);
private:
    void checkCapacity();
    int getCurrentCapacity();
    int lengthOfWorm();
    int minWorm();
};


#endif //SECONDSTEP_BRUTFORCERESOLVER_H
