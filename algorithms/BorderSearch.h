#pragma once
#include "Algorithm.h"
class BorderSearch :
    public Algorithm
{
    int finded;
    size_t find(int* arr, int key, size_t size) {
        if (size != 0) {
            comparison_count+=2;
            int buff = arr[size - 1];//�������� ������� ������� �������
            arr[size - 1] = key;//�����������, ��� value ���� � �������
            //���� �������� ����, ��� ������� ���� � �������, ������ ������ ����� �� ���������
            size_t i = 0;
            for (i = 0; arr[i] != key; ++i) {//���� ������� � �����
                comparison_count++;
            }
            arr[size - 1] = buff;//��������������� ��������� �������
            if (i != (size - 1) || key == buff) {//�� ��������� � ������ ��� ��������� ������� ��� �������
                return i;
            }
        }
        return std::numeric_limits<int>::max();
    }

    int *Alg(int* arr, int n) final // ������� Al
    {
        finded = find(arr, key, n - 1);
        return arr;
    }
    string GetName() final
    {
        return "border search";
    }

};

