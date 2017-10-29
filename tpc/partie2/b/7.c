#include <stdio.h>

int est_chiffre(char c) {
    if ( c >= '0' && c <= '9' ) {
        return 1;
    }
    else {
        return 0;
    }
}

int est_majuscule(char c) {
    if ( c >= 'A' && c <= 'Z' ) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    char c;
    printf("Entrez une lettre : " );
    c = getchar();
    
    if (est_chiffre(c) == 1) {
        printf("Le charactère entré est un chiffre.\n");
        return 0;
    }

    if (est_majuscule(c) == 1) {
        printf("Le charactère entré est une lettre MAJUSCULE.\n");
    }
    else {
        printf("Le charactère entré est une lettre minuscule.\n");
    }
    
    return 0;
}

