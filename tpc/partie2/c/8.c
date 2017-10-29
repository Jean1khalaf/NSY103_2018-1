#include <stdio.h>
#include <stdlib.h>

#define TAILLE 5

int main() {
    char tab[TAILLE];
    int i = 0;

    printf("Entrez %d caractères suivit de Entrée: " , TAILLE);
    while ( i < TAILLE ) {
        tab[i] = getchar();
        i++;
    }

    i=0;
    while( i < TAILLE ) {
        printf("%c", tab[i]);
        i++;
    }
    printf("\n");
    return 0 ;
}

