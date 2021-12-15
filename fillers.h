#pragma once
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>

using namespace std;

random_device rd;
mt19937 gen(time(NULL));


void almost_sorted(vector<int>& arr) {
    swap(arr[0], arr[arr.size()-1]);
}




//random numbs generator
void fill_array(vector<int>& arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        uniform_int_distribution<int> dist(-100, 100);
        arr.push_back(dist(gen));
    }
}
//reverse numbs generator
void reverse_array(vector<int>& arr) {
    reverse(arr.begin(), arr.end());
}
