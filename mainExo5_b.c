#include<stdio.h>

void Lecture(int tab[], int n)
{
    int c;

    for(c = 0; c < n; c++)
    {
        printf("%d ", tab[c]);
    }
    printf("\n");
}


void nb_premiers(int premiers[], int n)
{
    int i, k, m, t;
    m = 0;

    for(i = 2; m < n; i++)
    {
        t = 0;
        for( k = 2; k < i; k++)
        {
            if(i%k == 0)
                t = 1;
        }
        if( t == 0)
        {
            premiers[m] = i;
            m = m + 1;
        }
    }
}

int main()
{
    int n;

    printf("Veuillez saisir un entier supérieur ou egal a 1:");
    do
    {
        scanf("%d", &n);
    }
    while(n < 1);

    int premiers[n];
    nb_premiers(premiers, n);
    Lecture(premiers, n);

    return 1;
}
