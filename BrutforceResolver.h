//
// Created by paolo on 28.12.2019.
//

#ifndef SECONDSTEP_BRUTFORCERESOLVER_H
#define SECONDSTEP_BRUTFORCERESOLVER_H

#include <iostream>
#include <cmath>
#include "Resolver.h"

class BrutforceResolver: public Resolver {
public:
    int getResult(int length, int *field);
};


#endif //SECONDSTEP_BRUTFORCERESOLVER_H
