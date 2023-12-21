// Implementa le funzioni sulle liste realizzate con strutture doppiamente collegate, circolari, con sentinella, senza ordinamento

// FILE DA MODIFICARE

#include "ASD-doubly-linked-list.h"


using namespace list;

struct list::node {  // descrivo qui, fuori dal namespace, come e' fatta la struttura node: i dettagli interni non saranno visibili dal main
    Elem info;
    node *prev;
    node *next;
};

/*************************************************/
/* Implementazione delle operazioni di utilita'  */
/*************************************************/

void readFromStream(istream& str, List& l) {
    createEmpty(l);
    Elem e;
    str>>e;
    if (!str) throw runtime_error("Errore inserimento dati\n");
    // assumiamo che il segnale di fine input nel file sia  FINEINPUT
    while (e != FINEINPUT)  {     
        addRear(e, l);   // aggiunge l'elemento alla fine della lista
        str>>e;
        if (!str) throw runtime_error("Errore inserimento dati\n");
    }
}

/* legge il contenuto di una lista da file */
void readFromFile(string nome_file, List& l) {
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    readFromStream(ifs, l);
}


/* legge il contenuto di una lista da standard input */
void readFromStdin(List& l) {
   cout << "\nInserire una sequenza di numeri separati da spazi seguiti da " << FINEINPUT << " per terminare\n";
   readFromStream((std::cin), l);
}

/* stampa la lista */
void print(const List& l) {
   List q = l->next;  // q "salta la sentinella" e va alla testa della lista
   while (q != l) {   // avanza finche' non finisce la lista
      cout << q->info << "; ";
      q = q->next; 
    }
}


/**************************************************/
/* Implementazione delle operazioni nel namespace */
/**************************************************/

/* crea la lista vuota */
void list::createEmpty(List& l) {
    l = new node;
    l->info = EMPTYELEM;
    l->prev = l;
    l->next = l;
}

/* restituisce true se la lista e' vuota (ed e' vuota se il next di l, e' l stessa */
bool list::isEmpty(const List& l) {
    return l->next == l;
}

 /* restituisce la dimensione della lista */
int list::size(const List& l) {
    int count = 0;
    List aux = l->next;

    while(aux != l){
        count++;
        aux = aux->next;
    }
    return count;
}


/* "smantella" la lista svuotandola */
void list::clear(const List& l) {
    if(!isEmpty(l)){
    
        List aux = l->next;
        List del = aux;
        
        while(aux != l){
            aux = aux->next;
            delete del;
            del = aux;
            aux = aux->next;
        }
        
        delete del;
        l->next = l;
        l->prev = l;
    }
}

/* restituisce l'elemento in posizione pos se presente; restituisce un elemento 
che per convenzione si decide che rappresenta l'elemento vuoto altrimenti*/
Elem list::get(int pos, const List& l) {
    if(isEmpty(l)) return EMPTYELEM;
    List aux = l->next;
    for(int i = 1; i <= pos; i++){
        if(aux == l) return EMPTYELEM;
        aux = aux->next;
    }
    return aux->info;
}

/* modifica l'elemento in posizione pos, se la posizione e' ammissibile */
void list::set(int pos, Elem e, const List& l) {
    if(isEmpty(l)) return;
    List aux = l->next;
    for(int i = 1; i <= pos; i++){
        if(aux == l) return;
        aux = aux->next;
    }
    aux->info = e;
}

/* inserisce l'elemento in posizione pos, shiftando a destra gli altri elementi */
void list::add(int pos, Elem e, const List& l) {

    List n = new node;  
    n->info = e;

    if(isEmpty(l)){
        l->next = n;
        l->prev = n;
        n->next = l;
        n->prev = l;
        return;
    }

    List curr = l->next;
    List prev = l;

    for(int i = 1; i <= pos; i++){
        if(curr == l) {
            cout << "pos value exceedes the number of nodes in the list." << endl;
            return;
        }
        curr = curr->next;
        prev = prev->next;
    }

    prev->next = n;
    n->prev = prev;
    n->next = curr;
    curr->prev = n;
}

/* inserisce l'elemento alla fine della lista */
void list::addRear(Elem e,  const List& l) {
    List n = new node;
    n->info = e;
    List last = l->prev;

    last->next = n;
    n->prev = last;
    n->next = l;
    l->prev = n;
}

/* inserisce l'elemento all'inizio della lista */
void list::addFront(Elem e, const List& l) {

    List n = new node;
    n->info = e;
    List snd = l->next;

    n->next = snd;
    n->prev = l;
    l->next = n;
    snd->prev = n;
}

/* cancella l'elemento in posizione pos dalla lista */
void list::removePos(int pos, const List& l) {

    if(isEmpty(l)){
        return;
    }
    
	List del = nullptr;


    List curr = l->next;
    List p = l;

    for(int i = 1; i <= pos; i++){
        if(curr == l) {
            cout << "pos value exceedes the number of nodes in the list." << endl;
            return;
        }
        curr = curr->next;
        p = p->next;
    }
	del = curr;
	curr = curr->next;
	
    p->next = curr;
    curr->prev = p;
    delete del;
}

 /* cancella tutte le occorrenze dell'elemento elem, se presenti, dalla lista */
void list::removeEl(Elem e, const List& l) {

    if(isEmpty(l)){
        return;
    }
    
	List del = nullptr;
	List aux = l->next;

    while(aux != l){
    	if(aux->info == e){
    		
    		List del = aux;
    		aux = aux->next;
    		List p = del->prev;
    		
    		p->next = aux;
    		aux->prev = p;
    		
    		delete del;
    	}else {
    			aux = aux->next;
    		  }
    }
    
    
    
    
}



