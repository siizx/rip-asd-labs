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

void copyVector(vector<int> &a, vector<int> &b) // copy v1 into v2
{
   for (int i = 0; i < a.size(); i++)
   {
      b.push_back(a.at(i));
   }
}

int findMinIndex(const vector<int> &v, const int begin, const int end) // finds index of smallest element in the vector.
{
   int min_index = begin;
   for (int i = begin; i < end; i++)
   {
      if (v.at(i) < v.at(begin))
      {
         min_index = i;
         // cout << "min idx: " << i << "    min val: " << v[min_index] << endl;
      }
   }
   return min_index;
}

/**************************************************************************************
            SELECTION SORT
***************************************************************************************/
void selectionSort(vector<int> &v)
{
   for (int i = 0; i < v.size(); i++)
   {
      int minIndex = 0;
      for (int p = i; p < v.size(); p++)
      {
         minIndex = findMinIndex(v, i, v.size());
         if (v[minIndex] < v[i])
            scambia(v, minIndex, i);
      }
   }
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
