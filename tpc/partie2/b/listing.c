#include <stdio.h>

int est_chiffre(char c) {
    if ( c >= '0' && c <= '9' ) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    char c;
    printf("Entrez un caractère : " );
    c = getchar();
    
    if (est_chiffre(c) == 1) {
        printf("Le charactère entré est un chiffre\n");
    }
    else {
        printf("Le charactère entré est une lettre\n");
    }
    
    return 0;
}

