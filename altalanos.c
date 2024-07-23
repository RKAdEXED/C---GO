#include <stdlib.h>
#include <stdio.h>
#include "altalanos.h"
#include "debugmalloc.h"
#include "foresz.h"
#include "menu.h"

int** voltetomb(int meret){
    char** tomb_tomb = (int**) malloc(sizeof(int*)*meret);
    for (int i = 0; i<meret;i++)
        tomb_tomb[i] = (int*) malloc(sizeof(int)*meret);
    for (int i = 0; i < meret; i++){
        for (int j = 0; j < meret; j++){
            tomb_tomb[i][j] = 0;
        }
    }
    return tomb_tomb;
}

int palyameret(){
    int meret;
    printf("Valassz: 9/19\n");
    scanf("%d",&meret);
    while (meret != 9 && meret != 19){
        printf("\nValassz: 9/19\n");
        scanf("%d",&meret);
    }
    return meret;
}

char** palya(int meret){
    char** tomb_tomb = (char**) malloc(sizeof(char*)*(meret));
    for (int i = 0; i<meret;i++)
        tomb_tomb[i] = (char*) malloc(sizeof(char)*(meret));
    for (int i = 0; i < meret; i++){
        for (int j = 0; j < meret; j++){
            tomb_tomb[i][j] = '#';
        }
    }
    return tomb_tomb;
}

void palyairas(int meret,char** tomb){
    for (int i = 0; i<meret;++i){
        for (int j = 0;j<meret;j++)
            printf("%c ",tomb[i][j]);
        printf("\n");
    }
}

void csere(int x,int y,int maxim, int player, char** tomb){
    if (x > maxim || y > maxim)
        return NULL;
    else
        if (player == 0 && tomb[y][x] != 'X' && tomb[y][x] != 'O')
            tomb[y][x] = 'X';
        else
            if (player == 1 && tomb[y][x] != 'X' && tomb[y][x] != 'O')
                tomb[y][x] = 'O';
}
