//
// Created by paolo on 28.12.2019.
//

#ifndef SECONDSTEP_OPTIMALRESOLVER_H
#define SECONDSTEP_OPTIMALRESOLVER_H


class OptimalResolver {
private:
    int lengthOfField;
    int *field;
    int wormHead, wormAss, maxCapacity;

public:
    int getResult(int length, int *field);
    long long int resultTime(int length, int *field);
private:
    void checkCapacity();
    void reverseField();
    int getCurrentCapacity();
    int lengthOfWorm();
    int minWorm();
};


#endif //SECONDSTEP_OPTIMALRESOLVER_H
