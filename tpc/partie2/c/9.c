#include <stdio.h>

#define TAILLE 4

int main() {
    char tab[TAILLE];
    int i = 0;
    
    printf("Entrez %d caractères suivit de Entrée: " , TAILLE);
    while ( i < TAILLE ) {
        tab[i] = getchar();
        i++;
    }
    
    printf("%s\n", tab);
    
    return 0 ;
}
