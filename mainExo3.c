#include <stdio.h>
#include <stdlib.h>


void somme(int a[], int b[], int resultat[], int n){
	int i;
	for (i = 0; i < n; i++) {
		resultat[i] = a[i] + b[i];
	}
}

void lecture(int tab[], int n){
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", tab[i]);
	}
	printf("\n");
}

void ecriture(int tab[], int n){
	int i;
	for(i = 0; i < n; i++) {
	    printf(" element %d : ", i + 1);
		scanf("%d", &tab[i]);
	}
}

int main(){
	int n;
	printf("Taille tableau: ");
	scanf("%d", &n);

	int a[n];
	int b[n];
	int resultat[n];
	printf("Valeurs tableau 1:\n");
	ecriture(a, n);
	printf("Valeurs tableau 2:\n");
	ecriture(b, n);
	somme(a, b, resultat, n);
	lecture(resultat, n);

	return 0;
}
