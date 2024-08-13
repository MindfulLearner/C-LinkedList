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


// TOGLIERE


// INSERIAMO UNA POSIZIOEN DEL NODO


// STAMPARE



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

int main(int argc, char *argv[]){
    int controllo =-2;
    while (controllo !=5){
        stampaControlli();
        int numeroScelto = scanf("%d", &controllo);
        if (numeroScelto == 1 && numeroScelto > 0 && numeroScelto < 5){
            switch (controllo) {
                case 1:
                    printf("\taggiungo \n");
                    printf("\n");
                        break;
                case 2:
                    printf("\ttolgo \n");
                    printf("\n");
                        break;
                case 3:
                    printf("\tinserimento\n");
                    printf("\n");
                        break;
                case 4:
                    printf("\tPRINTATO\n");
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