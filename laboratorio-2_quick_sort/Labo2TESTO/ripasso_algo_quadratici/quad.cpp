#include <iostream>
#include <vector>
#include "labo2_sort.h"

using namespace std;

int main()
{
    // creo due vector.
    vector<int> daOrdinare = {5, 66, 950, 34, 99, 424, 2, 1657, 1, 4311, 200, 0, 432, 88, 63, 845, 321, 17};
    vector<int> ordinato;

    copyVector(daOrdinare, ordinato); // copio arg1 in arg2
    printVector(ordinato);            // stampo il vector

    return 0;
}