#include <stdio.h>

#define TAILLE 5

int est_min(char c) {
    if ( c >= 'a' && c <= 'z' ) {
        return 0;
    }
    else {
        return 1;
    }
}

char maj(char c) {
    char m;
    int diff = 'a' - 'A';
    if (est_min(c) == 0) {
        m = c - diff;
    }
    else {
        m = c;
    }
    
    return m;
}

int main() {
    char tab[TAILLE];
    int i = 0;
    printf( "Entrez un mot formé de 5 charactères : ");
    
    while (i < TAILLE) {
        tab[i] = getchar();
        i++;
    }
    
    i = 0;
    while (i < TAILLE) {
        tab[i] = maj(tab[i]);
        i++;
    }
    
    printf("%s", tab);
    
    return 0;
}

