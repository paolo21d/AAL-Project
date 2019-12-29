//
// Created by paolo on 29.12.2019.
//

#ifndef SECONDSTEP_RESOLVER_H
#define SECONDSTEP_RESOLVER_H


class Resolver {
protected:
    int lengthOfField;
    int *field;
    int wormHead, wormAss, maxCapacity;

public:
    virtual int getResult(int length, int *field) = 0;
    long long int resultTime(int length, int *field);
protected:
    void checkCapacity();
    int getCurrentCapacity();
    int lengthOfWorm();
    int minWorm();
};


#endif //SECONDSTEP_RESOLVER_H
