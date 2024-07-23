#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"
#include "files.h"
#include "foresz.h"
#include "menu.h"

void beolvas(int* x, int* y){
    int ez,az;
    FILE* fp = fopen("Eredmeny.txt","r");
    if (fp == NULL) {
        perror("Fájl megnyitása sikertelen");
        return;
    }
    fscanf(fp,"%d:%d", &ez, &az);
    fclose(fp);
    *x = ez;
    *y = az;
}

void mentes(int* x, int* y,int ki){
    FILE* fp = fopen("Eredmeny.txt","w");
    if (fp == NULL) {
        perror("Fájl megnyitása sikertelen");
        return;
    }
    if (ki == 0)
        *x += 1;
    if (ki == 1)
        *y += 1;
    fprintf(fp,"%d:%d", *x, *y);
    fclose(fp);
}

void scoreboardmenu(){
    char scoreboard;
    printf("Megnez: m, Torol: t\n");
    scanf("%s", &scoreboard);
    if (scoreboard == 'm'){
        int* eddigi_0,* eddigi_1,gamer_0 = 0,gamer_1 = 0;
        eddigi_0 = &gamer_0;
        eddigi_1 = &gamer_1;
        beolvas(eddigi_0,eddigi_1);
        printf("Jatekos 0: %d\nJatekos 1: %d\nMenu:",*eddigi_0,*eddigi_1);
    }
    if (scoreboard == 't'){
        int* eddigi_0,* eddigi_1,gamer_0 = 0,gamer_1 = 0,ki = 2;
        eddigi_0 = &gamer_0;
        eddigi_1 = &gamer_1;
        mentes(eddigi_0,eddigi_1,ki);
        printf("\nMenu: ");
    }
}
