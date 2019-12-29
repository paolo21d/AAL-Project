//
// Created by paolo on 28.12.2019.
//

#include "BrutforceResolver.h"
#include <chrono>
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
void BrutforceResolver::checkCapacity() {
    int capacity = getCurrentCapacity();
    //cout << "CheckCapacity: length " << lengthOfWorm() << " minWorm " << minWorm() << " capacity " << capacity << endl;
    if (capacity > maxCapacity)
        maxCapacity = capacity;
}
int BrutforceResolver::getCurrentCapacity() {
    return minWorm() * lengthOfWorm();
}
int BrutforceResolver::lengthOfWorm() {
    return wormHead - wormAss;
}
int BrutforceResolver::minWorm() {
    return min(field[wormHead], field[wormAss]);
}
long long int BrutforceResolver::resultTime(int argLength, int *argField) {
    chrono::steady_clock::time_point begin, optEnd;
    begin = chrono::steady_clock::now();
    getResult(argLength, argField);
    optEnd = chrono::steady_clock::now();
    long long int calculationTime = chrono::duration_cast<chrono::microseconds>(optEnd - begin).count();
    return calculationTime;
}
