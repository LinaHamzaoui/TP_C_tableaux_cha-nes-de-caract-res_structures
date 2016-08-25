#include<stdio.h>

void nb_premiers(int premiers[], int n)
{
    int i = 2, j, b, k;

    for (j = 0; j < n; )
    {
        b = 1;
        for (k = 0; k < j; k++)
        {
            if(i%premiers[k] == 0)
                b = 0;
        }
        if(b)
        {
            premiers[j] = i;
            j++;
        }
        i++;
    }
}
void Lecture(int tab[], int n)
{
    int a;

    for(a = 0; a< n; a++)
    {
        printf("%d ", tab[a]);
    }
    printf("\n");
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
    Lecture(premiers, n);

    return 0;
}
