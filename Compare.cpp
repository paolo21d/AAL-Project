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

