//
// Created by paolo on 28.12.2019.
//

#include "OptimalResolver.h"
#include <iostream>
using namespace std;

int OptimalResolver::getResult(int argLength, int *argField) {
    lengthOfField = argLength;
    field = argField;
    wormHead = 1;
	wormTail = 0;
    maxCapacity = min(field[wormHead], field[wormTail]);

    while (wormHead < lengthOfField) {
        if (field[wormHead] >= field[wormTail]) {
            checkCapacity();
			wormTail = wormHead;
        }
        wormHead++;
    }

    //reverse
    reverseField();

    wormHead = 1;
	wormTail = 0;

    while (wormHead < lengthOfField) {
        if (field[wormHead] >= field[wormTail]) {
            checkCapacity();
			wormTail = wormHead;
        }
        wormHead++;
    }

    return maxCapacity;
}
void OptimalResolver::reverseField() {
    for (int i = 0; i < lengthOfField / 2; i++) {
        swap(field[i], field[lengthOfField - 1 - i]);
    }
}
