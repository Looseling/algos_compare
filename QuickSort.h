#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

int partition(vector<int>& arr, int lowest, int highest) {

    //int pivot = rand() % (highest - lowest) + lowest;
    //int pivot = highest;
    int wall = lowest - 1;

    for (int i = lowest; i < highest; i++)
    {
        if (arr[highest] > arr[i])
        {
            wall++;
            swap(arr[wall], arr[i]);
        }

    }
    wall++;
    swap(arr[wall], arr[highest]);




    return wall;
}

void quicksort(vector<int>& arr, int lowest, int highest) {

    int wall;

    if (highest > lowest) {
        wall = partition(arr, lowest, highest);
        quicksort(arr, lowest, wall - 1);
        quicksort(arr, wall + 1, highest);
    }

}

void _quicksort(vector<int>& arr) {

    //srand(time(NULL));
    quicksort(arr, 0, arr.size() - 1);
}



