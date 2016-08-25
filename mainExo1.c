#include <stdio.h>
#include <stdlib.h>
#define TAILLE 10

void Lecture(int *p){
    int i=0;
    for (; i<TAILLE; i++, p++) {
        printf("tab[%d]", i);
        scanf("%d", p);
    }
}

void Ecriture(int *p){
    int i=0;
    for (; i<TAILLE; i++, p++) {
         printf("%d\t", *p);
    }
}

int main(int argc, const char * argv[]){
    int tab[TAILLE];
    printf("Lecture :\n");
    Lecture(&tab[0]);
    printf("Afficher :\n");
    Ecriture(&tab[0]);
    return 0;
}
