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
   int prev, curr;
   unsigned int size = v.size();

   for (int i = 1; i < size; i++)
   {
      curr = i;
      prev = i - 1;

      while (prev >= 0 && v[curr] < v[prev])
      {
         scambia(v, curr, prev);
         curr--;
         prev--;
      }
   }
}

/**************************************************************************************
            BUBBLESORT
***************************************************************************************/
void bubbleSort(vector<int> &v)
{
   int size = v.size();

   for (int i = 0; i < size; i++)
   {
      int curr = 0;
      int next = curr + 1;
      bool swapped = false;

      for (int j = i; next < size; j++)
      {
         if (v[curr] > v[next])
            scambia(v, curr, next);
         ++curr;
         ++next;
         swapped = true;
      }
      if (!swapped)
         return;
   }
}

/**************************************************************************************
               MERGESORT
***************************************************************************************/
void fondi(vector<int> &v, unsigned int inizio, unsigned int centro, unsigned int fine)
{
   vector<int> vsinistro, vdestro;

   for (unsigned int i = inizio; i <= centro; i++)
   {
      vsinistro.push_back(v[i]);
   }
   for (unsigned int j = centro + 1; j <= fine; j++)
   {
      vdestro.push_back(v[j]);
   }

   unsigned int indicesinistra = 0;
   unsigned int indicedestra = 0;
   unsigned int maxsin = vsinistro.size();
   unsigned int maxdes = vdestro.size();

   for (unsigned int i = inizio; i <= fine; i++)
   {
      if (indicesinistra < maxsin && indicedestra < maxdes)
      {
         if (vsinistro[indicesinistra] > vdestro[indicedestra])
         {
            v[i] = vdestro[indicedestra];
            ++indicedestra;
            continue;
         }
         else
         {
            v[i] = vsinistro[indicesinistra];
            ++indicesinistra;
            continue;
         }
      }
      else if (indicesinistra < maxsin && indicedestra == maxdes)
      {
         v[i] = vsinistro[indicesinistra];
         ++indicesinistra;
         continue;
      }
      else if (indicesinistra == maxsin && indicedestra < maxdes)
      {
         v[i] = vdestro[indicedestra];
         ++indicedestra;
         continue;
      }
   }
}

void ms(vector<int> &v, unsigned int inizio, unsigned int fine)
{
   if (inizio < fine)
   {
      unsigned int centro = (inizio + fine) / 2;
      ms(v, inizio, centro);
      ms(v, centro + 1, fine);
      fondi(v, inizio, centro, fine);
   }
}

void mergeSort(vector<int> &v)
{
   if (v.size() != 0)
      ms(v, 0, v.size() - 1);
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
