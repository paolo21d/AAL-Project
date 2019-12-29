//
// Created by paolo on 28.12.2019.
//

#include "BrutforceResolver.h"
using namespace std;

int BrutforceResolver::getResult(int argLength, int *argField) {
    lengthOfField = argLength;
    field = argField;
    wormHead = 1;
    wormAss = 0;
    maxCapacity = 0;

    for (wormAss = 0; wormAss < lengthOfField - 1; wormAss++) {
        wormHead = wormAss + 1;
        int tempMax = field[wormHead];
        checkCapacity();
        for (; wormHead < lengthOfField; wormHead++) {
            //cout<<"ASS: "<<field[wormAss]<<" HEAD: "<<field[wormHead]<<endl;
            if (field[wormHead] >= field[wormAss]) {
                checkCapacity();
                break;
            }
            if (field[wormHead] <= tempMax)
                continue;
            if (field[wormHead] > tempMax)
                tempMax = field[wormHead];
            checkCapacity();
        }
    }

    return maxCapacity;
}
