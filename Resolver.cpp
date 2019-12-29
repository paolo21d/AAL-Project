//
// Created by paolo on 29.12.2019.
//

#include "Resolver.h"
#include <iostream>
#include <chrono>
using namespace std;

long long int Resolver::resultTime(int argLength, int *argField) {
    chrono::steady_clock::time_point beginTime, endTime;
    beginTime = chrono::steady_clock::now();
    getResult(argLength, argField);
    endTime = chrono::steady_clock::now();
    long long int calculationTime = chrono::duration_cast<chrono::microseconds>(endTime - beginTime).count();
    return calculationTime;
}
void Resolver::checkCapacity() {
    int capacity = getCurrentCapacity();
    //cout << "CheckCapacity: length " << lengthOfWorm() << " minWorm " << minWorm() << " capacity " << capacity << endl;
    if (capacity > maxCapacity)
        maxCapacity = capacity;
}
int Resolver::getCurrentCapacity() {
    return minWorm() * lengthOfWorm();
}
int Resolver::lengthOfWorm() {
    return wormHead - wormAss;
}
int Resolver::minWorm() {
    return min(field[wormHead], field[wormAss]);
}
