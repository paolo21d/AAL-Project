#include <iostream>
#include <chrono>
#include "Compare.h"
#include "OptimalResolver.h"

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
    OptimalResolver resolver;
    int stepsQuantity = 10; //ile pomiarów będzie wykonanych
    int stepSize = 10000; //co jaką długość będą wykonywane pomiary
    int stepOffset = 110000; //od jakiej dlugości zaczynją się pomiary
    int quantityOfTries = 1000; //ilość próbek na krok
    int maxHeight = 20;

    chrono::steady_clock::time_point optBegin, optEnd;
    auto *optTimes = new long long int[quantityOfTries];
    for (int i = 1; i <= stepsQuantity; ++i) {
        int step = stepSize * i + stepOffset;
        for (int k = 0; k < quantityOfTries; ++k) {
            int *input = compare.generateInput(step, maxHeight);
            optBegin = chrono::steady_clock::now();
            resolver.getResult(step, input);
            optEnd = chrono::steady_clock::now();
            optTimes[k] = chrono::duration_cast<chrono::microseconds>(optEnd - optBegin).count();
            delete[] input;
        }

        //policzenie sredniego czasu
        long long int optSumOfTime = 0;
        for (int k = 0; k < quantityOfTries; ++k) {
            optSumOfTime += optTimes[k];
        }
        long long int optAverageTime = optSumOfTime / quantityOfTries;

        cout << "LENGTH\t" << step << "\tTIME\t" << optAverageTime << endl;
    }
    delete[] optTimes;
}