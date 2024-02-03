#include "labo2_sort.h"

void scambia(vector<int> &v, int i, int j)
{
   int tmp = v[j];
   v[j] = v[i];
   v[i] = tmp;
}

void printVector(const vector<int> &v)
{
   for (int i = 0; i < v.size(); i++)
   {
      cout << v.at(i) << " ";
   }
   cout << endl;
};

void copyVector(vector<int> &a, vector<int> &b)
{
   for (int i = 0; i < a.size(); i++)
   {
      b.push_back(a.at(i));
   }
}

/**************************************************************************************
            SELECTION SORT
***************************************************************************************/
void selectionSort(vector<int> &v)
{
}

/**************************************************************************************
            INSERTION SORT
***************************************************************************************/
void insertionSort(vector<int> &v)
{
}

/**************************************************************************************
            BUBBLESORT
***************************************************************************************/
void bubbleSort(vector<int> &v)
{
}

/**************************************************************************************
               MERGESORT
***************************************************************************************/
void fondi(vector<int> &v, unsigned int inizio, unsigned int centro, unsigned int fine)
{
}

void ms(vector<int> &v, unsigned int inizio, unsigned int fine)
{
}

void mergeSort(vector<int> &v)
{
}

/**************************************************************************************
            QUICKSORT CON SCELTA "BANALE" DEL PIVOT
***************************************************************************************/

void quickSortTrivial(vector<int> &v)
{
   /* Implementare quickSort banale con partizione in place */
}

/**************************************************************************************
            QUICKSORT RANDOMIZZATO
***************************************************************************************/

void quickSortRandom(vector<int> &v)
{
   /* Implementare quickSort randomizzato con partizione in place */
}
