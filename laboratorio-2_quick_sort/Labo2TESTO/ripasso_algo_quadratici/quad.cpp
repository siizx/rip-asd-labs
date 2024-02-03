#include <iostream>
#include <vector>
#include "labo2_sort.h"

using namespace std;

int main()
{
    // creo due vector.
    vector<int> v = {5, 66, 950, 34, 99, 424, 2, 1657, 1, 4311, 200, 0, 432, 88, 63, 845, 321, 17};
    printVector(v); // stampo il vector

    // Ordino il vector con una tipo di sorting a scelta:
    // selectionSort(v);
    insertionSort(v);
    printVector(v); // stampo il vector ordinato

    return 0;
}