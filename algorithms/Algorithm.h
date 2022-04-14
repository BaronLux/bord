#pragma once
#include <stdlib.h>
#include "omp.h"
#include <algorithm>
#include <iostream>
#include <ctime>
#include <ostream>
#include <chrono>

using namespace std;

class Algorithm abstract
{
protected:
	int iter_count, comparison_count; // количество итераций и сравненей
	long long elapsed; // время затраченное на работу алгоритма
	string name;
	string delimiter = "----------------------\n";

	virtual string GetName() = 0;
	virtual int* Alg(int* arr, int n) = 0; // 
public:
	int key = 100000;
	void Run(int* arr, int n)
	{
		iter_count = 0; comparison_count = 0;

		std::chrono::time_point<std::chrono::high_resolution_clock> start, stop;
		start = std::chrono::high_resolution_clock::now();
		Alg(arr, n);
		stop = std::chrono::high_resolution_clock::now();

		elapsed = std::chrono::duration_cast<chrono::nanoseconds> (stop - start).count();
	}
	void Print()
	{
		cout << delimiter + GetName() << endl;
		cout << "iter_count=" << iter_count << endl;
		cout << "comparison_count=" << comparison_count << endl;
		cout << "elapsed[ns]=" << elapsed << endl;
		cout << delimiter;
	}
};

