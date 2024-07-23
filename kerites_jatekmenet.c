#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "kerites_jatekmenet.h"
#include "altalanos.h"
#include "debugmalloc.h"
#include "foresz.h"
#include "menu.h"

bool keritve(int x,int y,int meret,char jatekos,char** tmb,int** voltetmb){
    if (1 != voltetmb[y][x] && tmb[y][x]==jatekos){
        voltetmb[y][x] = 1;

        if ((y+1 < meret && tmb[y+1][x]=='#') || (y-1 >= 0 && tmb[y-1][x]=='#' ) || (x+1 < meret && tmb[y][x+1]=='#') || (x-1 >= 0 && tmb[y][x-1]=='#'))
            return false;

        if (x+1 < meret && tmb[y][x+1] == jatekos){
            if (keritve(x+1,y,meret,jatekos,tmb,voltetmb)==false)
                return false;
        }
        if (x-1 >= 0 && tmb[y][x-1] == jatekos){
            if (keritve(x-1,y,meret,jatekos,tmb,voltetmb)==false)
                return false;
        }
        if (y+1 < meret && tmb[y+1][x] == jatekos){
            if (keritve(x,y+1,meret,jatekos,tmb,voltetmb)==false)
                return false;
        }
        if (y-1 >= 0 && tmb[y-1][x] == jatekos){
            if (keritve(x,y-1,meret,jatekos,tmb,voltetmb)==false)
                return false;
        }
    }
    return true;
}

void keritvecsere(int meret,char** tmb){
    int** volte;
    for (int x = 0; x < meret; x++){
        for (int y = 0; y < meret; y++){
            if (tmb[y][x] != '#'){
                volte = voltetomb(meret);
                if (keritve(x,y,meret,tmb[y][x],tmb, volte) == true){
                    for (int j = 0; j < meret ; j++){
                        for (int i = 0; i < meret ; i++){
                            if (volte[j][i] == 1){
                                tmb[j][i] = '#';
                            }
                        }
                    }
                }
                for (int i=0;i<meret;i++)
                    free(volte[i]);
                free(volte);
            }
        }
    }
}
