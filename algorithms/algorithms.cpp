// algorithms.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "Algorithm.h"
#include "Generators.h"
#include "QuikSort.h"
#include "BorderSearch.h"
using namespace std;

void PrintArr(int* arr, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << '\t';
	}
	cout << endl;
}

int* Sort(int* arr, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i+1; i < n; i++)
		{
			if (arr[i] < arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
	return arr;
}

void test()
{
	auto bord = new BorderSearch();
	auto sort = new QuickSort();
	
	int n = 6;
	int* arr = new int[] {-100, -10, 0, 12, 13, 14 };
	arr = sort->Alg(arr, n);
	PrintArr(arr, n);

	bord->Run(arr, n);

	bord->Print();
}

int main()
{
	auto bord = new BorderSearch();
	auto sort = new QuickSort();

	auto gen = new Generators();
	

	cin >> bord->key; // 
	cout << "random sorted arr min -> max" << endl;
	for (size_t i = 2; i < 7; i++)
	{
		int n = pow(10, i);
		auto key_idx = rand() % n;
		auto arr = gen->RandomGen(n);
		arr[key_idx] = bord->key; // искомый элемент гарантированно будет находиться в массиве
		arr = sort->Alg(arr, n);

		cout << n << endl;

		bord->Run(arr, n);
		bord->Print();
	}

	cout << "random arr" <<endl;
	for (size_t i = 2; i < 7; i++)
	{
		int n = pow(10, i);
		auto key_idx = rand() % n;
		auto arr = gen->RandomGen(n);
		arr[key_idx] = bord->key;

		cout << n << endl;

		bord->Run(arr, n);
		bord->Print();
	}

	cout << "random sorted arr max -> min" << endl;
	for (size_t i = 2; i < 7; i++)
	{
		int n = pow(10, i);
		auto key_idx = rand() % n;
		auto arr = gen->RandomGen(n);
		arr[key_idx] = bord->key;
		arr = Sort(arr, n);

		cout << n << endl;

		bord->Run(arr, n);
		bord->Print();
	}

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
