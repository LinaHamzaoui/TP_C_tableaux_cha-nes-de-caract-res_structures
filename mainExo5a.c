#include <stdio.h>
#include <stdlib.h>

void lecture(int tab[], int n)
{
    int k;

    for (k = 0; k < n; k++)
    {
        printf("%d ", tab[k]);
    }
    printf("\n");
}

int est_premier(int n)
{
    int k;

    if ((n == 0) || (n == 1))
        return 0;
    if (n == 2)
        return 1;
    for (k= 2; k < n; k =k + 1)
    {
        if (n%k == 0)
            return 0;
    }

    return 1;
}

void nb_premiers(int premiers[], int n)
{
    int m, i, t;
    m = 0;

    for(i = 2; m < n; i++)
    {
        t = est_premier(i);
        if(t == 1)
        {
            premiers[m] = i;
            m = m + 1;
        }
    }
}

int main()
{
    int n;

    printf("veuillez saisir un entier superieur ou egal a 1:");
    do
    {
        scanf("%d", &n);
    }
    while(n < 1);

    int premiers[n];
    nb_premiers(premiers, n);

    if(n == 1)
        printf("Le 1er nombre premier est :\n");
    else
        printf("Les %d 1er nombres premiers sont :\n", n);
    lecture(premiers, n);

    return 0;
}

