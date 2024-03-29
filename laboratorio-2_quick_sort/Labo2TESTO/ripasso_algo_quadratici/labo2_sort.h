#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

void selectionSort(vector<int> &);
void insertionSort(vector<int> &);
void bubbleSort(vector<int> &);
void mergeSort(vector<int> &);
void quickSortTrivial(vector<int> &);
void quickSortRandom(vector<int> &);

void printVector(const vector<int> &);
void copyVector(vector<int> &, vector<int> &);
int findMinIndex(const vector<int> &v, const int begin, const int end);
