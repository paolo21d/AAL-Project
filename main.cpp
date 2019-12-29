#include <iostream>
#include "Compare.h"

using namespace std;
void optimalTimer();

int main() {
    Compare compare;
    int fieldLength = 500000;
    int maxHeight = 15;
    int quantityOfTries = 100;

    //bool result = compare.compareResults(fieldLength, maxHeight, quantityOfTries);
    //cout << "RESULT OF COMPARISON: " << result;

    optimalTimer();
}

void optimalTimer() {
    Compare compare;
    int stepsQuantity = 10; //ile pomiarów będzie wykonanych
    int stepSize = 10000; //co jaką długość będą wykonywane pomiary
    int stepOffset = 110000; //od jakiej dlugości zaczynją się pomiary
    int quantityOfTries = 1000; //ilość próbek na krok
    int maxHeight = 20;

    auto *optTimes = new long long int[quantityOfTries];
    for (int i = 1; i <= stepsQuantity; ++i) {
        int step = stepSize * i + stepOffset;
        long long int optAverageTime = compare.statisticTimeOptimal(step, maxHeight, quantityOfTries);
        cout << "LENGTH\t" << step << "\tTIME\t" << optAverageTime << endl;
    }
    delete[] optTimes;
}