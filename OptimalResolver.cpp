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
    wormAss = 0;
    maxCapacity = min(field[wormHead], field[wormAss]);

    while (wormHead < lengthOfField) {
        //cout<<field[wormAss]<<" "<<field[wormHead]<<endl;
        if (field[wormHead] >= field[wormAss]) {
            checkCapacity();
            wormAss = wormHead;
            //cout<<"ass: "<<field[wormAss]<<" head: "<<field[wormHead]<<endl;
        }
        wormHead++;
    }

    //reverse
    reverseField();
    //cout<<endl<<"REVERSE!!!"<<endl;

    wormHead = 1;
    wormAss = 0;

    while (wormHead < lengthOfField) {
        //cout<<field[wormAss]<<" "<<field[wormHead]<<endl;
        if (field[wormHead] >= field[wormAss]) {
            checkCapacity();
            wormAss = wormHead;
            //cout<<"ass: "<<field[wormAss]<<" head: "<<field[wormHead]<<endl;
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
