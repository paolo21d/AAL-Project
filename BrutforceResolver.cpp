//
// Created by paolo on 28.12.2019.
//

#include "BrutforceResolver.h"
using namespace std;

int BrutforceResolver::getResult(int argLength, int *argField) {
    lengthOfField = argLength;
    field = argField;
    wormHead = 1;
	wormTail = 0;
    maxCapacity = 0;

    for (wormTail = 0; wormTail < lengthOfField - 1; wormTail++) {
        wormHead = wormTail + 1;
        int tempMax = field[wormHead];
        checkCapacity();
        for (; wormHead < lengthOfField; wormHead++) {
            if (field[wormHead] >= field[wormTail]) {
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
