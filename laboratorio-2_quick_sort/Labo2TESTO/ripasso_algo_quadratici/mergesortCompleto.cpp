/**************************************************************************************
               MERGESORT
***************************************************************************************/



void fondi(vector<int> &v, unsigned int inizio, unsigned int centro, unsigned int fine)
{
   vector<int> vsinistra, vdestra;

   for (unsigned int i = inizio; i <= centro; ++i)
      vsinistra.push_back(v[i]);

   for (unsigned int i = centro + 1; i <= fine; ++i)
      vdestra.push_back(v[i]);

   unsigned int indicesinistra = 0;
   unsigned int maxsin = vsinistra.size();
   unsigned int indicedestra = 0;
   unsigned int maxdes = vdestra.size();

   for (unsigned int i = inizio; i <= fine; ++i)
   {
      if (indicesinistra < maxsin && indicedestra < maxdes)
      {
         if (vsinistra[indicesinistra] < vdestra[indicedestra])
         {
            v[i] = vsinistra[indicesinistra];
            indicesinistra++;
            continue;
         }
         else
         {
            v[i] = vdestra[indicedestra];
            indicedestra++;
            continue;
         }
      }

      if (indicesinistra == maxsin && indicedestra < maxdes)
      {
         v[i] = vdestra[indicedestra];
         indicedestra++;
         continue;
      }

      if (indicedestra == maxdes && indicesinistra < maxsin)
      {
         v[i] = vsinistra[indicesinistra];
         indicesinistra++;
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
