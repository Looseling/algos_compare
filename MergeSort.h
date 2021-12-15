#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

void mergesort(vector<int>& arr)
{
    vector<int> right;
    vector<int> left;
    if (arr.size() > 1)
    {
       
        int halfsize = arr.size() / 2;
        for (int i = 0; i < arr.size(); i++)
        {
            if (i < halfsize)
            {
                left.push_back(arr[i]);
            }
            else
            {
                right.push_back(arr[i]);
            }
        }
        mergesort(left);
        mergesort(right);
        arr.clear();
        int j = 0;
        int k = 0;
        while (k < left.size() && j < right.size()) {
            if (left[k] > right[j]) {
                arr.push_back(right[j]);
                j++;
            }
            else {
                arr.push_back(left[k]);
                k++;
            }
        }

        while (k < left.size()) {
            arr.push_back(left[k]);
            k++;
        }

        while (j < right.size()) {
            arr.push_back(right[j]);
            j++;
        }



    }
    right.clear();
    left.clear();

}