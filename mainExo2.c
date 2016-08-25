#include <stdio.h>
#include <stdlib.h>


int Position(int T[], int x);


int Position(int T[], int x){
    for (int i=0;i<5;i++){
        if (T[i]==x)
            return i;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int tab[5]={1,3,5,6,8};
    int position = Position(tab, 8);
    printf("%d\n", position);
    return 0;
    }
