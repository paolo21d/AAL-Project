//
// Created by paolo on 28.12.2019.
//

#ifndef SECONDSTEP_OPTIMALRESOLVER_H
#define SECONDSTEP_OPTIMALRESOLVER_H


#include "Resolver.h"

class OptimalResolver: public Resolver {
public:
    int getResult(int length, int *field);
private:
    void reverseField();
};


#endif //SECONDSTEP_OPTIMALRESOLVER_H
