//ciao mondo

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int initData;
    void *next;
} Node; 

Node *head = NULL;

// 4 opzioni
// AGGIUNGERE
Node *aggiungiNodo(int *numero) {
    //definiamo un contenitore che fungera simile a un init di contenitore
    Node *contenitore = NULL;
    // valutiamo se head e' vuoto ovviamente la prima volta la lista sara vuota di conseguenza, creeremo il primo nodo
    if (head == NULL) {
        // diamo a contenitore un indirizzo di MEMORIA
        contenitore = malloc(sizeof(Node));
        // controlliamo se siamo riusciti ad asseggnare l'indirizzo di memoria a contenitore
        if (contenitore == NULL)
            return 0;
        // ora inizializziamo o diamo un nuovo valore a initData che ora risulta vuoto
        contenitore->initData = *numero;
        // head e' NULL ora gli assegniamo lo stesso indirizzo di memoria di contenitore
        head = contenitore;
        // cambiamo il nodo a cui punta next che sara NULL perche dopo di lui non ci sara alcun altro nodo
        // considerazione personale: potremmo usare solo e solamente haed per modificare 
        // verrebbe scritto tipo
        // head = malloc etc..
        // head -> initData = *numb;
        // head -> next = NULL;
        contenitore->next = NULL;
        // se head non e' NULL quindi contiene gia un nodo struct
    } else {
        // qui facciamo sempre l'assegnazione di indirizzo di memoria
        contenitore = malloc(sizeof(Node));
        // controlliamo il successo o fallimento di indirizzo di memoria
        if (contenitore == NULL)
            return 0;
        // non faremo direttamente head ma su contenitore, perche siamo modificando un nuovo elemento
        contenitore->initData = *numero;
        // qui puntiamo head perche puntiamo ;'indirizzo di memoria che abbiamo assegnato gia da prima, non importa se astralmente si trova destra sinistra dopra e giu
        contenitore->next = head;
        // ora assegnami a head il nuovo indirizzo di memoria perche avremmo un nuovo elemento sara head che sara collegato al prossimo tramite next
        head = contenitore;
        // immaginiamo che punti sempre all'ultimo che e' stato aggiunto che a sua volta sara collegato all'ultimo aggiunto prima di lui
    }
    return contenitore;
}
// TOGLIERE Usiamo in rimuoviNodo int perche restituira return 1 che e fallimento o return 0 come fallimento
// argomento usiamo numero pointer
int rimuoviNodo(int *numero){
    // faccio un contenitore per adress di memoria di head contenitore fornisce da attuale di adress
    Node *contenitore = head;
    // prescendente iniziamo con head anche perche ora come ora, noi partiamo da inzio quidni non avremmo ancora qualcosa prima di haed
    Node *precedente = head;
    // ora un while che fara la stessa cosa fino a quando contenitore non uguale a NULL diventera NULL perche alla fine non ci saranno piu nodi
    while (contenitore != NULL) {
        // controlliamo se il numero che abbiamo inserito equivale a initData che e' il valore all'interno del nodo
        if (contenitore->initData == *numero){
            // if contnitere == head intendiamo se' il primo nodo che troviamo ed e' quello che dobbiamo togliere allora
            if (contenitore == head){
                // indichiamo un nuovo indirizzo di memoria per head che sara il suo successivo
                head = head->next;
                //altrimenti
            }else{
                // prescendete prendere next di contenitore attuale a cui stiamo puntando il suo next 
                // quindi next = contenitore next attuale, in precendente mettiamo adress a qui verra collegata al prossimo di contenitore che ha head
                precedente->next = contenitore->next;
                // liberiamo la memoria 
                free(contenitore);
                // rendiamo contenitore NULL
                contenitore = NULL;
            }
            // ritorniamo 1 per successo
            return 1;
        }
        // precendente prende le informazioni di contenitore quidni dati e next 
        precedente = contenitore;
        // contenitore prende come valori quelli dell'indirizzo di memoria a cui e' next
        contenitore = contenitore->next;
    }
    // ritornamo 0 per  falliemnto
    return 0;  
}

// INSERIAMO UNA POSIZIOEN DEL NODO
Node *aggiungiNodoLibero(int *numeroPosizione, int *numeroNumero) {
// ######################## CODICE 1 IDEA
    Node *same = head;
    Node *precedente = head;
    Node *newNode = NULL;
    newNode = malloc(sizeof(Node));
    newNode->initData = *numeroNumero;
    // if i type 2 i will iterate 2 times!! so . i type 1  it will go to first node
    // DA sistemare!!! PROBLEM IN NUMERO POSIZIONE
    if (*numeroPosizione == 1){
        same = NULL;
        (*numeroPosizione)--;
        printf("per aggiungere a primo bisogna usare il comando add. nel menu!\n");
    } 
    while (same != NULL && numeroPosizione != 0) {
        printf("swagger while Posizione: %d\n", *numeroPosizione);
        (*numeroPosizione)--;
        if (*numeroPosizione == 0) {
            printf("swagger if Posizione: %d\n", *numeroPosizione);
            precedente->next = newNode;
            newNode->next = same;
        }
        precedente = same;
        same = same->next;
    }

    // ###############CODICE 2
    // Node *same = head;
    //    while (same != NULL && *numeroPosizione != 0)
    //    {
    //    same = same->next;
    //        (*numeroPosizione)--;
    //    }
    //    if (numeroPosizione != 0)
    //    {
    //        printf("NON TROVATO POSIZIONE NON DISPONIBILE");
    //        return NULL;
    //    }
    //    Node *new = malloc(sizeof(Node));
    //    if (new == NULL)
    //        return NULL;
    //    new->initData = *numeroNumero;
    //    new->next = same->next;
    //    same->next = new;
    //    return new;

}

// STAMPARE
void printList() {
    // node
    // puntiamo a al primo head collegato all'indirizzo di memoria dell'ultimo aggiunto difatti
    // stiamo dando ad attuale indirizzo di memoria di head
    // nella costruzione del head noi puntiamo sempre a contenitore alla fine quindi l'ultimo aggiunto e primo della lista sara questo
    Node *attuale = head;
    //il ciclo per la stampa partira solo se non e' null attaule quindi nemmeno head null la lista ha valori
    while (attuale != NULL){ 
        // stampera iniData di attuale nello stesso indirizzo di memoria di head
        printf("%d linkato a -> ", attuale-> initData);
        //dato che in head e' contenuto anche indirizzo di memoria di quello su ccessivo attuale prendere il prossimo indirizzo di memoria
        attuale = attuale->next;
                    // ricomincia il ciclo fino a quando attuale non si trovera in un indirizzo NULL
                }
                }

// USCIRE DAL GIOCO



// FUNZIONE DI CONTROLLO 
void stampaControlli() {
    printf("\n");
    printf("###################################################################################################\n");
    printf("Questi sono i comandi che puoi usare per la tua linkedList: \n");
    printf("\t'1' aggiungera un elemento nella lista , in caso sia vuota verra aggiunta una nuova e spostata a destra quella vecchia\n");
    printf("\t'2' togliera un elemento dalla lista\n");
    printf("\t'3' inserimenti posizione del nodo\n");
    printf("\t'4' ti fara printare le tua lista ->\n");
    printf("\t'5' ti fara uscire dal programma\n");
    printf("####################################################################################################\n");
    printf("\n");
    return;
}
int datoPerInit;
Node *contenitore;

int main(int argc, char *argv[]){
    int controllo =-2;
    while (controllo !=5){
        stampaControlli();
        int numeroScelto = scanf("%d", &controllo);
        if (numeroScelto == 1 && numeroScelto > 0 && numeroScelto < 5){
            switch (controllo) {
                case 1:
                    printf("\taggiungo \n");
                    scanf("%d", &datoPerInit);
                    // node poinmter usiamo un node contenitore per contenere il return di contenitore nella funziona ggiungiNodo
                    contenitore = aggiungiNodo(&datoPerInit);
                    printf("al numero scelto e' stato dato indirizzo di memoria: %p\n", (void*)contenitore);
                    printf("\n");
                    break;
                case 2:
                    printf("\ttolgo \n");
                    // iniiziare remove :w
                    // inseriamo un intero che verra passato a rimuoviNodo
                    scanf("%d", &datoPerInit);
                    // usiamo int non nodo perchhe avremo un int che ritorna return  0 o 1 
                    int swag = rimuoviNodo(&datoPerInit);
                    // return 1 success, return 0 not succes
                    if (!swag){ 
                        printf("e' stato un fallimento. Non esiste nella lista il numero: %d\n", datoPerInit); 
                    } else {
                        printf("e' stato rimossso correttamente il numero: %d\n", datoPerInit);
                    }
                    printf("\n");
                    break;
                case 3:
                    // uso 2 numeri di inserimento: 1 per la posizione e uno per il numero che si vuole inserire:w
                    // 
                    printf("\tinserimento\n");
                    printf("inserimento numero della posizione: \n");
                    int numberPosition;
                    scanf("%d", &numberPosition);
                    printf("Inserisci numero che vuole inserire nella lista\n");
                    scanf("%d", &datoPerInit);
                    contenitore = aggiungiNodoLibero(&numberPosition, &datoPerInit);
                    printf("\n");
                    break;
                case 4:
                    printf("\tPRINTING\n");
                    printList();
                    printf("\n");
                    break;
                case 5:
                    printf("\tquit dal programma\n");
                    printf("\n");
                    break;
            }
        }
    }
    return 0;
}
