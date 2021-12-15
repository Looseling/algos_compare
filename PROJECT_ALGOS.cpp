#include "QuickSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "fillers.h"

#include <vector>
#include <windows.h>
#include <fstream>
#include <algorithm>



using namespace std;

int step = 100;
int maxStep = 10000;
//For Rands
double Quick_Random = 0;
double Merge_Random = 0;
double Heap_Random = 0;
//For Sorteds
double Quick_Sorted = 0;
double Heap_Sorted = 0;
double Merge_Sorted = 0;
//for Reverse
double Quick_Reverse = 0;
double Merge_Reverse = 0;
double Heap_Reverse = 0;
//almost sorted
double Quick_Almost = 0;
double Merge_Almost = 0;
double Heap_Almost = 0;
// get average from 100 arrays
int iterations = 100;



//return runtime
double AllStuff(vector<int>& arr, void what(vector<int>& arr))
{

    LARGE_INTEGER start, end;
    LARGE_INTEGER fr;

    QueryPerformanceFrequency(&fr);
    double freq = fr.QuadPart / 1.0;

    QueryPerformanceCounter(&start);
    what(arr);
    QueryPerformanceCounter(&end);

    return (double)(end.QuadPart - start.QuadPart) * 10;
}

int main()
{




    //file
    ofstream _average("average.txt");
    ofstream _sorted("sorted.txt");
    ofstream _reverse("reverse.txt");
    ofstream _almost("almost_sorted.txt");

    //arrs
    vector<int> arr;
    vector<int> arr2;
    vector<int> arr3;







    for (int len = step; len < maxStep; len += step)
    {
        for (int i = 0; i < iterations; i++)
        {
            //fill array
            fill_array(arr, len);
            fill_array(arr2, len);
            fill_array(arr3, len);

            ////Random
            Quick_Random += AllStuff(arr, &_quicksort);
            Merge_Random += AllStuff(arr2, &mergesort);
            Heap_Random += AllStuff(arr3, &heapSort);
            
            //Sorted
            Quick_Sorted += AllStuff(arr, &_quicksort);
            Merge_Sorted += AllStuff(arr2, &mergesort);
            Heap_Sorted += AllStuff(arr3, &heapSort);

            //almost sorted
            almost_sorted(arr);
            almost_sorted(arr2);
            almost_sorted(arr3);
                
            Quick_Almost += AllStuff(arr, &_quicksort);
            Merge_Almost+= AllStuff(arr2, &mergesort);
            Heap_Almost += AllStuff(arr3, &heapSort);
            
            //reverse
            reverse_array(arr);
            reverse_array(arr2);
            reverse_array(arr3);
           
            Quick_Reverse += AllStuff(arr, &_quicksort);
            Merge_Reverse += AllStuff(arr2, &mergesort);
            Heap_Reverse += AllStuff(arr3, &heapSort);


            arr.clear();
            arr2.clear();
            arr3.clear();
        }

        Quick_Random /= iterations;
        Merge_Random /= iterations;
        Heap_Random /= iterations;

        Quick_Sorted /= iterations;
        Merge_Sorted /= iterations;
        Heap_Sorted /= iterations;

        Quick_Reverse /= iterations;
        Merge_Reverse /= iterations;
        Merge_Reverse /= iterations;

        Quick_Almost /= iterations;
        Merge_Almost /= iterations;
        Heap_Almost /= iterations;


        _average << len << " " << Quick_Random << " " << Merge_Random << " " << Heap_Random << endl;
        _sorted << len << " " << Quick_Sorted << " " << Merge_Sorted << " " << Heap_Sorted << endl;
        _reverse << len << " " << Quick_Reverse << " " << Merge_Reverse << " " << Heap_Reverse << endl;
        _almost << len << " " << Quick_Almost << " " << Merge_Almost << " " << Heap_Almost << endl;


    }
    _average.close();
    _sorted.close();
    _reverse.close();
    _almost.close();

}
