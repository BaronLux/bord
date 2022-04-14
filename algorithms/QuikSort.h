#pragma once
#include "Algorithm.h"
class QuickSort :
    public Algorithm
{

    int* quickSort(int* numbers, int left, int right)
    {
        int pivot; // разрешающий элемент
        int l_hold = left; //левая граница
        int r_hold = right; // правая граница
        pivot = numbers[left];
        while (left < right) // пока границы не сомкнутся
        {
            while ((numbers[right] >= pivot) && (left < right))
            {
                this->comparison_count++;
                this->iter_count++;

                right--;
            }// сдвигаем правую границу пока элемент [right] больше [pivot]
            if (left != right) // если границы не сомкнулись
            {
                numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
                left++; // сдвигаем левую границу вправо
            }
            while ((numbers[left] <= pivot) && (left < right))
            {
                this->comparison_count++; // количество сравнений
                this->iter_count++; // количество итераций

                left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
            }
            if (left != right) // если границы не сомкнулись
            {
                numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
                right--; // сдвигаем правую границу влево
            }
        }
        numbers[left] = pivot; // ставим разрешающий элемент на место
        pivot = left;
        left = l_hold;
        right = r_hold;
        if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
            quickSort(numbers, left, pivot - 1);
        if (right > pivot)
            quickSort(numbers, pivot + 1, right);

        
        return numbers;
    }

    string GetName()
    {
        return "quick sort";
    }
public:
    int* Alg(int* arr, int n) final // функция Al
    {
        return quickSort(arr, 0, n - 1);
    }
};

