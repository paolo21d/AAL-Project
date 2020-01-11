#include <iostream>
#include <cstdlib>
#include "Compare.h"
#include "OptimalResolver.h"

using namespace std;

void optimalTimer();

void batchMode(int argc, char *argv[]);

void menu();

void optimalStepTimer(int offset, int maxHeight, int stepSize, int quantityOfSteps, int quantityOfTries);

void bothStepTimer(int offset, int maxHeight, int stepSize, int quantityOfSteps, int quantityOfTries);

int main(int argc, char *argv[]) {
	Compare compare;
	int fieldLength = 500000;
	int maxHeight = 15;
	int quantityOfTries = 100;

	//bool result = compare.compareResults(fieldLength, maxHeight, quantityOfTries);
	//cout << "RESULT OF COMPARISON: " << result;

	//optimalTimer();
	//compare.compareResults(5000, 200, 1000000);

	if (argc >= 2) {
		batchMode(argc, argv);
	} else {
		menu();
	}
}

void optimalTimer() {
	Compare compare;
	int stepsQuantity = 1; //ile pomiarów będzie wykonanych
	int stepSize = 10000; //co jaką długość będą wykonywane pomiary
	int stepOffset = 110000; //od jakiej dlugości zaczynją się pomiary
	int quantityOfTries = 1000; //ilość próbek na krok
	int maxHeight = 20;

	cout << "LENGTH TIME[ms]" << endl;
	for (int i = 1; i <= stepsQuantity; ++i) {
		int step = stepSize * i + stepOffset;
		long long int optAverageTime = compare.statisticTimeOptimal(step, maxHeight, quantityOfTries);
		cout << step << " " << optAverageTime << endl;
	}
}

void menu() {
	bool exit = false;
	int option;

	while (!exit) {
		cout << "Wybierz operacje jaka chcesz wykonac:" << endl;
		cout << "1\tPojedyncze rozwiazanie" << endl
			 << "2\tGenerowanie przypadkow testowych i porownanie wynikow dla algorytmu Optimal oraz Brutforce" << endl
			 << "3\tPomiar czasu wykonania dla coraz wiekszych probek dla algorytmu Optimal" << endl
			 << "4\tPomiar czasu wykonania dla coraz wiekszych probek dla obu algotymow" << endl
			 << "0\tWyjscie z programu" << endl;
		cin >> option;

		if (option == 1) {
			int fieldLength;
			cout << "Podaj dlugosc pola:";
			cin >> fieldLength;
			cout << "Podaj wysokosci slupkow, oddzielajac dane spacja" << endl;
			int *field = new int[fieldLength];
			for (int i = 0; i < fieldLength; ++i) {
				cin >> field[i];
			}
			OptimalResolver resolver;
			int result = resolver.getResult(fieldLength, field);
			cout << "RESULT:" << result << endl;
			delete[] field;
		} else if (option == 2) {
			cout << "Podaj argumenty: dlugosc pola, max wysokosc slupka, ilosc prob" << endl;
			int fieldLength, maxPostHeight, quantityOfTries;
			cin >> fieldLength >> maxPostHeight >> quantityOfTries;
			cout << "Jezeli zostanie znaleziony przypadek niezgodny zostanie od wyswitlony" << endl;
			Compare compare;
			compare.compareResults(fieldLength, maxPostHeight, quantityOfTries);
		} else if (option == 3) {
			cout << "Podaj argumenty: "
				 << "offset, max wysokosc slupka, wielkosc kroku, ilosc krokow, ilosc probek pomiarowych na dany krok"
				 << endl;
			int offset, maxHeight, stepSize, quantityOfSteps, quantityOfTries;
			cin >> offset >> maxHeight >> stepSize >> quantityOfSteps >> quantityOfTries;
			optimalStepTimer(offset, maxHeight, stepSize, quantityOfSteps, quantityOfTries);
		} else if (option == 4) {
			cout << "Podaj argumenty: "
				 << "offset, max wysokosc slupka, wielkosc kroku, ilosc krokow, ilosc probek pomiarowych na dany krok"
				 << endl;
			int offset, maxHeight, stepSize, quantityOfSteps, quantityOfTries;
			cin >> offset >> maxHeight >> stepSize >> quantityOfSteps >> quantityOfTries;
			bothStepTimer(offset, maxHeight, stepSize, quantityOfSteps, quantityOfTries);
		} else if (option == 0) {
			exit = true;
			break;
		} else {
			cout << "Niepoprawne dane!" << endl;
		}
	}
}

void batchMode(int argc, char *argv[]) {
	int taskType = atoi(argv[1]);

	if (taskType == 1) {
		// pojedynczy przypadek testowy -> zwrot rowiazania
		// arguments: fieldLength, postHeights...
		int fieldLength = atoi(argv[2]);
		int *field = new int[fieldLength];
		for (int i = 0; i < fieldLength; ++i) {
			field[i] = atoi(argv[3 + i]);
		}
		OptimalResolver resolver;
		int result = resolver.getResult(fieldLength, field);
		cout << result << endl;
		delete[] field;
	} else if (taskType == 2) {
		// generowanie przypadków testowych i rozwiązanie ich za pomocą BrutforceResolver oraz OptimalResolver i porównanie wyników
		// arguments: quantityOfTries, fieldLength, maxPostHeight
		int quantityOfTries = atoi(argv[1]);
		int fieldLength = atoi(argv[2]);
		int maxPostHeight = atoi(argv[3]);

		Compare compare;
		compare.compareResults(fieldLength, maxPostHeight, quantityOfTries);
	} else if (taskType == 3) {
		// pomiar czasu wykonania dla narastającyh danych dla optymalnego algorytmu
		// arguments: offset(starting length of field), maxHeight, stepSize, quantityOfSteps, quantityOfTries
		int offset = atoi(argv[2]);
		int maxHeight = atoi(argv[3]);
		int stepSize = atoi(argv[4]);
		int quantityOfSteps = atoi(argv[5]);
		int quantityOfTries = atoi(argv[6]);

		optimalStepTimer(offset, maxHeight, stepSize, quantityOfSteps, quantityOfTries);
	} else if (taskType == 4) {
		// pomiar czasu wykonania dla narastającyh danych dla obu algorytmów
		// arguments: offset(starting length of field), maxHeight, stepSize, quantityOfSteps, quantityOfTries
		int offset = atoi(argv[2]);
		int maxHeight = atoi(argv[3]);
		int stepSize = atoi(argv[4]);
		int quantityOfSteps = atoi(argv[5]);
		int quantityOfTries = atoi(argv[6]);

		bothStepTimer(offset, maxHeight, stepSize, quantityOfSteps, quantityOfTries);
	} else {
		cout << "Incorrect parameter!" << endl;
	}
}

void optimalStepTimer(int offset, int maxHeight, int stepSize, int quantityOfSteps, int quantityOfTries) {
	Compare compare;
	cout << "LENGTH\tTIME[ms]\tq(LENGTH)" << endl;
	auto *optimalTimes = new long long int[quantityOfSteps];
	auto *expectedTimes = new int[quantityOfSteps];
	for (int i = 0; i < quantityOfSteps; ++i) {
		int step = stepSize * i + offset;
		optimalTimes[i] = compare.statisticTimeOptimal(step, maxHeight, quantityOfTries);
		expectedTimes[i] = step;
	}

	double timeMedian = optimalTimes[quantityOfSteps / 2];
	double expectedTimeMedian = expectedTimes[quantityOfSteps / 2];
	for (int i = 0; i < quantityOfSteps; ++i) {
		int step = stepSize * i + offset;
		double q = ((double) optimalTimes[i] * expectedTimeMedian) / ((double) expectedTimes[i] * timeMedian);
		cout << step << "\t" << optimalTimes[i] << "\t" << q << endl;
	}
	delete[] optimalTimes;
	delete[] expectedTimes;
}

void bothStepTimer(int offset, int maxHeight, int stepSize, int quantityOfSteps, int quantityOfTries) {
	Compare compare;
	auto *optimalTimes = new long long int[quantityOfSteps];
	auto *optimalExpectedTimes = new int[quantityOfSteps];
	auto *brutforceTimes = new long long int[quantityOfSteps];
	auto *brutforceExpectedTimes = new int[quantityOfSteps];
	for (int i = 0; i < quantityOfSteps; ++i) {
		int step = stepSize * i + offset;
		pair<long long int, long long int> times = compare.statisticTimeBoth(step, maxHeight, quantityOfTries);
		optimalTimes[i] = times.first;
		optimalExpectedTimes[i] = step;
		brutforceTimes[i] = times.second;
		brutforceExpectedTimes[i] = step;
	}

	cout << "OPTIMAL: length\ttime[ms]\tQ[n]" << endl;
	double optimalTimeMedian = optimalTimes[quantityOfSteps / 2];
	double optimalExpectedTimeMedian = optimalExpectedTimes[quantityOfSteps / 2];
	for (int i = 0; i < quantityOfSteps; ++i) {
		int step = stepSize * i + offset;
		double q = ((double) optimalTimes[i] * optimalExpectedTimeMedian) /
				   ((double) optimalExpectedTimes[i] * optimalTimeMedian);
		cout << step << "\t" << optimalTimes[i] << "\t" << q << endl;
	}

	cout << "BRUTFORCE: length\ttime[ms]\tQ[n]" << endl;
	double brutforceTimeMedian = brutforceTimes[quantityOfSteps / 2];
	double brutforceExpectedTimeMedian = brutforceExpectedTimes[quantityOfSteps / 2];
	for (int i = 0; i < quantityOfSteps; ++i) {
		int step = stepSize * i + offset;
		double q = ((double) brutforceTimes[i] * brutforceExpectedTimeMedian) /
				   ((double) brutforceExpectedTimes[i] * brutforceTimeMedian);
		cout << step << "\t" << brutforceTimes[i] << "\t" << q << endl;
	}

	delete[] optimalTimes;
	delete[] optimalExpectedTimes;
	delete[] brutforceTimes;
	delete[] brutforceExpectedTimes;
}