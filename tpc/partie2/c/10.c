#include <stdio.h>

#define TAILLE 4

int main() {
    char tab[TAILLE+1];
    int i = 0;
    
    printf("Entrez %d caractères suivit de Entrée: " , TAILLE);
    while ( i < TAILLE ) {
        tab[i] = getchar();
        i++;
    }
    
    tab[i] = 0;
    printf("%s\n", tab);
    
    return 0;
}

