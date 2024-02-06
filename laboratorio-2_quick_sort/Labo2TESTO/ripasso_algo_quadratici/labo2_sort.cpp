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
   for (unsigned int i = centro + 1; i <= fine; i++)
   {
      vdestro.push_back(v[i]);
   }

   unsigned int indicesinistro = 0;
   unsigned int indicedestro = 0;
   unsigned int sinmax = vsinistro.size();
   unsigned int desmax = vdestro.size();

   for (unsigned int i = inizio; i <= fine; i++)
   {
      if (indicesinistro < sinmax && indicedestro < desmax)
      {
         if (vsinistro[indicesinistro] < vdestro[indicedestro])
         {
            v[i] = vsinistro[indicesinistro];
            ++indicesinistro;
            continue;
         }
         else
         {
            v[i] = vdestro[indicedestro];
            indicedestro++;
            continue;
         }
      }
      else if (indicesinistro < sinmax && indicedestro == desmax)
      {
         v[i] = vsinistro[indicesinistro];
         indicesinistro++;
         continue;
      }
      else
      {
         v[i] = vdestro[indicedestro];
         indicedestro++;
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
int partitionTrivial(vector<int> &v, int inizio, int fine)
{
   int pivot_index = inizio;        // scelta banale;
   scambia(v, pivot_index, inizio); // metto il pivot in prima posizione (operazione inutile in questo specifico caso.)

   int i = inizio + 1;
   for (int j = inizio + 1; j <= fine; j++)
   {
      if (v[j] < v[inizio])
      {
         scambia(v, i, j);
         i++;
      }
   }

   scambia(v, inizio, i - 1);
   return i - 1;
}

void qsTrivial(vector<int> &v, int inizio, int fine)
{
   if (inizio < fine)
   {
      int pivot_index = partitionTrivial(v, inizio, fine); // partition restituisce l'indice definitivo del pivot.
      qsTrivial(v, inizio, pivot_index - 1);               // -1 perche' il pivot ovviamente e' gia al suo posto
      qsTrivial(v, pivot_index + 1, fine);                 // +1 perche' il pivot ovviamente e' gia al suo posto
   }
}

void quickSortTrivial(vector<int> &v)
{
   if (v.size() != 0)
   {
      qsTrivial(v, 0, v.size() - 1);
   }
}

/**************************************************************************************
            QUICKSORT RANDOMIZZATO
***************************************************************************************/

int partitionRandom(vector<int> &v, int inizio, int fine)
{
   int pivot_index = inizio + rand() % (fine - inizio + 1); // +1 e' per rendere incluso il valore 'fine'.
   int i = inizio + 1;
   scambia(v, inizio, pivot_index); // metto il pivot in prima posizione.

   for (int j = inizio + 1; j <= fine; j++)
   {
      if (v[j] < v[inizio])
      {
         scambia(v, i, j);
         i++;
      }
   }

   scambia(v, inizio, i - 1);
   return i - 1;
}

void qsRandom(vector<int> &v, int inizio, int fine)
{
   if (inizio < fine)
   {
      int pivot_index = partitionRandom(v, inizio, fine);
      qsRandom(v, inizio, pivot_index - 1);
      qsRandom(v, pivot_index + 1, fine);
   }
}

void quickSortRandom(vector<int> &v)
{
   srand(time(NULL));
   /* Implementare quickSort randomizzato con partizione in place */
   if (v.size() != 0)
      qsRandom(v, 0, v.size() - 1);
}
