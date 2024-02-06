// trucchetto per fare contento l'editor, che altrimenti si lamenta che le strutture dati non sono definite
#ifndef USE_HASH_TABLE
#define USE_HASH_TABLE
#endif

#include "dictionary.h"

#include <math.h> // sqrt()

using namespace dict;

struct dict::cell
{
   Elem elem;
   cell *next;
};

/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
int h1(Key s) // funzione di hash che considera unicamente il valore ascii del primo carattere della chiave (se esiste) e restituisce il resto della divisione di tale valore per tableDim
{
   // implementare la funzione richiesta e modificare il return
   if (s.size() > 0)
   {
      int k = s[0];
      return k % tableDim;
   }
   else
      return 0;
}

/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
int h2(Key s) // funzione di hash che somma il codice ascii di ogni carattere nella chiave e restituisce il resto della divisione di tale somma per tableDim
{
   // implementare la funzione richiesta e modificare il return
   return 0;
}

/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
int h3(Key s) // funzione di hash diversa da h1 ed h2, che progettate e implementate voi seguendo qualche criterio che vi sembra ragionevole
{
   // implementare la funzione richiesta e modificare il return
   return 0;
}

/****************************************************************/
/*    FUNZIONE DA MODIFICARE PER FARE ESPERIMENTI DIVERSI       */
/****************************************************************/
int h(Key s)
{
   return h1(s); // modificare questa chiamata per sperimentare l'utilizzo delle funzioni di hash h1, h2, h3, definite prima
}

// Funzione ausiliaria per restituire un puntatore a cell
cell *dict::isAlreadyIn(const Key k, const Dictionary &d)
{
   int key = h(k);
   cell *aux = d[key];
   while (aux != emptyBucket)
   {
      if (aux->elem.key == k)
         return aux;
      else
         aux = aux->next;
   }

   return emptyBucket;
}

/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/* Ritorna OK se la chiave non esisteva già e se l'inserimento  */
/* ha avuto successo.							    */
/* Ritorna FAIL se la chiave esisteva già o se l'inserimento    */
/* non ha avuto successo.*/
/****************************************************************/
Error dict::insertElem(const Key k, const Value v, Dictionary &s)
{
   if (isAlreadyIn(k, s) != emptyBucket)
      return FAIL;

   cell *nuova = new cell;

   nuova->elem.key = k;
   nuova->elem.value = v;
   nuova->next = s[h(k)];
   s[h(k)] = nuova;

   return OK;
}

/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/* Ritorna il Value v associato alla Key k, se questa esiste    */
/* Ritorna emptyValue altrimenti					    */
/****************************************************************/
Value dict::search(const Key k, const Dictionary &s)
{
   Bucket present = isAlreadyIn(k, s);
   if (present == emptyBucket)
      return emptyValue;
   else
      return present->elem.value;
}

/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/* Ritorna OK se la chiave esiste nel dizionario e se la 	    */
/* cancellazione ha avuto successo					    */
/* Ritorna FAIL se la chiave non esisteva nel dizionaio o se la */
/* cancellazione non ha avuto successo				    */
/****************************************************************/
Error dict::deleteElem(const Key k, Dictionary &s)
{
   Bucket present = isAlreadyIn(k, s);
   if (present == emptyBucket)
      return FAIL;
   else if (s[h(k)] == present)
   {
      s[h(k)] = present->next;
      delete present;
   }
   else
   {
      Bucket prev = s[h(k)];

      while (prev->next != present)
      {
         prev = prev->next;
      }
      prev->next = present->next;
      delete present;
   }
   return OK;
}

/****************************************************************/
Dictionary dict::createEmptyDict()
{
   Bucket *d = new Bucket[tableDim];
   for (int i = 0; i < tableDim; ++i)
      d[i] = emptyBucket;
   return d;
}

/****************************************************************/
Dictionary readFromFile(string nome_file)
{
   ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
   if (!ifs)
   {
      cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n";
      return createEmptyDict();
   }
   return readFromStream(ifs);
}

/****************************************************************/
Dictionary readFromStdin()
{
   cout << "\nInserire una sequenza di linee che rispettano la sintassi key: value.<enter>\nDigitare CTRL^ D per terminare l'inserimento\n";
   Dictionary d = readFromStream((std::cin));
   // Questa serve per aggirare un bug di alcune versioni attuali di glibc.
   clearerr(stdin);
   return d;
}

/****************************************************************/
Dictionary readFromStream(istream &str)
{
   Dictionary d = createEmptyDict();
   string key, kcopy;
   string value;
   getline(str, key, ':');
   getline(str, value);
   while (!str.eof())
   {
      kcopy = key;
      removeBlanksAndLower(kcopy);
      insertElem(kcopy, value, d); // FINCHE' NON IMPLEMENTATE LA INSERTELEM, NON PUO' FUNZIONARE CORRETTAMENTE: la insertElem e' la prima funzione che dovete implementare
      getline(str, key, ':');
      getline(str, value);
   }
   str.clear();
   return d;
}

/****************************************************************/
int printBucket(Bucket b) // stampa il contenuto di un bucket e restituisce il numero di elementi contenuti nel bucket stesso
{
   int counter = 0;
   while (b != emptyBucket)
   {
      counter++;
      cout << (b->elem).key << ": " << (b->elem).value << "\n";
      b = b->next;
   }
   return counter;
}

/****************************************************************/
void print(const Dictionary &s)
// stampa il contenuto del dizionario ed anche informazioni su come sono stati organizzati gli elementi
{
   int bucketDim[tableDim];
   int totalElem = 0;
   for (unsigned int i = 0; i < tableDim; ++i)
   {
      cout << "\nBucket " << i << "\n\n";
      bucketDim[i] = printBucket(s[i]);
      totalElem += bucketDim[i];
   }
   float means = totalElem / (float)tableDim;
   float standardDevSum = 0;
   for (unsigned int i = 0; i < tableDim; ++i)
      standardDevSum += (bucketDim[i] - means) * (bucketDim[i] - means);

   /* Lo scarto tipo, deviazione standard, o scarto quadratico medio e' un indice di dispersione statistico, vale a dire una stima della variabilita' di una popolazione di dati o di una variabile casuale.
   Lo scarto tipo e' uno dei modi per esprimere la dispersione dei dati intorno ad un indice di posizione, quale puo' essere, ad esempio, la media aritmetica. */

   cout << "\n===STATISTICHE SULL'ORGANIZZAZIONE DEL DIZIONARIO===\n";

   for (unsigned int i = 0; i < tableDim; ++i)
      cout << "\nBucket " << i << ": " << bucketDim[i] << " elementi";

   cout << "\nIl numero totale di elementi memorizzati e' " << totalElem;
   cout << "\nIl numero di bucket nel dizionario e' " << tableDim;
   if (tableDim != 0)
      cout << "\nIl numero atteso di elementi per bucket e' " << means << "\nLa deviazione standard e' " << sqrt(standardDevSum / tableDim);
}
