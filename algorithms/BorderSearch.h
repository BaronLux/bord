#pragma once
#include "Algorithm.h"
class BorderSearch :
    public Algorithm
{
    int finded;
    size_t find(int* arr, int key, size_t size) {
        if (size != 0) {
            comparison_count+=2;
            int buff = arr[size - 1];//Сохраним прежний элемент массива
            arr[size - 1] = key;//Гарантируем, что value есть в массиве
            //Есть гарантия того, что элемент есть в массиве, значит индекс можно не проверять
            size_t i = 0;
            for (i = 0; arr[i] != key; ++i) {//Одно условие в цикле
                comparison_count++;
            }
            arr[size - 1] = buff;//Восстанавливаем последний элемент
            if (i != (size - 1) || key == buff) {//Не уткнулись в барьер или последний элемент был искомым
                return i;
            }
        }
        return std::numeric_limits<int>::max();
    }

    int *Alg(int* arr, int n) final // функция Al
    {
        finded = find(arr, key, n - 1);
        return arr;
    }
    string GetName() final
    {
        return "border search";
    }

};

