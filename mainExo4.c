#include <stdio.h>
#include <stdlib.h>

void histogramme(int note[], int n, int histo[], int h)
{
    int i, j;
    for(i = 0; i < h; i++)
    {
        histo[i] = 0;
        for(j = 0; j < n; j++)
        {
            if(note[j] == i)
            {
                histo[i] += 1;
            }
        }
    }
}

void lecture(int tab[], int n)
{
    int c;
    for(c = 0; c < n; c++)
    {
        printf("%d ", tab[c]);
    }
    printf("\n");
}

void ecriture(int tab[], int n, int seuil)
{
    int i;
    for(i = 0; i < n; i++)
    {
        do
        {
            printf(" Note %d : ", i + 1);
            scanf("%d", &tab[i]);
        }
        while(tab[i] >= seuil);
    }
}

void affichage(int tab[], int n)
{
    int i, plus;
    for(i = 0; i < n; i++)
    {
        printf("[%d] : ", i);
        for (plus = 0; plus < tab[i]; plus++)
            printf("+");
        printf("\n");
    }
}

int main()
{
    int n;
    const int capacite = 21;
    int histo[capacite];
    printf("Saisir le nombre de notes:\n");
    scanf("%d", &n);
    printf("\n");

    int note[n];
    printf("Veuillez saisir chaques notes:\n");
    ecriture(note, n, capacite);
    printf("\n");
    lecture(note, n);
    printf("\n");
    histogramme(note, n, histo, capacite);
    affichage(histo, capacite);

    return 0;
}
