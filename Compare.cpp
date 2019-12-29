//
// Created by paolo on 28.12.2019.
//

#include "Compare.h"
#include "BrutforceResolver.h"
#include "OptimalResolver.h"
#include <chrono>
using namespace std;

bool Compare::compareResults(int length, int maxHeight, int quantityOfTries) {
    BrutforceResolver brutforceResolver;
    OptimalResolver optimalResolver;
    int optimalResult, brutforceResult;
    chrono::steady_clock::time_point optBegin, optEnd, brutBegin, brutEnd;
    for (int i = 0; i < quantityOfTries; ++i) {
        cout << "Try no " << i << endl;
        int *input = generateInput(length, maxHeight);

        //optimal
        optBegin = chrono::steady_clock::now();
        optimalResult = optimalResolver.getResult(length, input);
        optEnd = chrono::steady_clock::now();
        //cout << "Optimal: " << optimalResult << endl;

        //brut
        brutBegin = chrono::steady_clock::now();
        brutforceResult = brutforceResolver.getResult(length, input);
        brutEnd = chrono::steady_clock::now();
        //cout << "Brute: " << brutforceResult << endl;

        cout << "OPT\t" << chrono::duration_cast<chrono::microseconds>(optEnd - optBegin).count()
             << "\tBRT\t" << chrono::duration_cast<chrono::microseconds>(brutEnd - brutBegin).count() << endl;
        if (optimalResult != brutforceResult) {
            cout << "ERROR" << endl << length << endl;
            for (int j = 0; j < length; j++) {
                cout << input[j] << " ";
            }
            cout << endl;
            delete[] input;
            return false;
        }
        delete[] input;
    }
    return true;
}
int *Compare::generateInput(int length, int maxHeight) {
    srand(time(NULL));
    int *field = new int[length];
    for (int i = 0; i < length; ++i) {
        field[i] = (rand() % maxHeight) + 1;
    }
    return field;
}
std::pair<long long int, long long int> Compare::statisticTimeBoth(int length, int maxHeight, int quantityOfTries) {
    OptimalResolver optimalResolver;
    BrutforceResolver brutforceResolver;
    auto *optTimes = new long long int[quantityOfTries];
    auto *brutTimes = new long long int[quantityOfTries];
    for (int k = 0; k < quantityOfTries; ++k) {
        int *input = generateInput(length, maxHeight);
        optTimes[k] = optimalResolver.resultTime(length, input);
        brutTimes[k] = brutforceResolver.resultTime(length, input);
        delete[] input;
    }

    //policzenie sredniego czasu
    long long int optSumOfTime = 0;
    long long int brutSumOfTime = 0;
    for (int k = 0; k < quantityOfTries; ++k) {
        optSumOfTime += optTimes[k];
        brutSumOfTime += brutTimes[k];
    }
    long long int optAverageTime = optSumOfTime / quantityOfTries;
    long long int brutAverageTime = brutSumOfTime / quantityOfTries;
    delete[] optTimes;
    delete[] brutTimes;
    return pair<long long int, long long int>(optAverageTime, brutAverageTime);
}

long long int Compare::statisticTimeOptimal(int length, int maxHeight, int quantityOfTries) {
    OptimalResolver resolver;
    auto *optTimes = new long long int[quantityOfTries];
    for (int k = 0; k < quantityOfTries; ++k) {
        int *input = generateInput(length, maxHeight);
        optTimes[k] = resolver.resultTime(length, input);
        delete[] input;
    }

    //policzenie sredniego czasu
    long long int optSumOfTime = 0;
    for (int k = 0; k < quantityOfTries; ++k) {
        optSumOfTime += optTimes[k];
    }
    long long int optAverageTime = optSumOfTime / quantityOfTries;
    delete[] optTimes;
    return optAverageTime;
}

long long int Compare::statisticTimeBrutforce(int length, int maxHeight, int quantityOfTries) {
    BrutforceResolver resolver;
    auto *brutTimes = new long long int[quantityOfTries];
    for (int k = 0; k < quantityOfTries; ++k) {
        int *input = generateInput(length, maxHeight);
        brutTimes[k] = resolver.resultTime(length, input);
        delete[] input;
    }

    //policzenie sredniego czasu
    long long int brutSumOfTime = 0;
    for (int k = 0; k < quantityOfTries; ++k) {
        brutSumOfTime += brutTimes[k];
    }
    long long int brutAverageTime = brutSumOfTime / quantityOfTries;
    delete[] brutTimes;
    return brutAverageTime;
}

