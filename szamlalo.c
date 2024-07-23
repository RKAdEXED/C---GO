#include <stdlib.h>
#include <stdio.h>
#include "altalanos.h"
#include "debugmalloc.h"
#include "szamlalo.h"
#include "foresz.h"
#include "menu.h"

bool keritesszamlalo(int x,int y,int meret,char masikjatekos,char** tmb,int** voltetmb){
    if (1 != voltetmb[y][x] && tmb[y][x]=='#'){
        voltetmb[y][x] = 1;

        if ((y+1 < meret && tmb[y+1][x]==masikjatekos) || (y-1 >= 0 && tmb[y-1][x]==masikjatekos) || (x+1 < meret && tmb[y][x+1]==masikjatekos) || (x-1 >= 0 && tmb[y][x-1]==masikjatekos)){
            return false;
        }

        if (x+1 < meret && tmb[y][x+1] == '#'){
            if (keritesszamlalo(x+1,y,meret,masikjatekos,tmb,voltetmb)==false)
                return false;
        }
        if (x-1 >= 0 && tmb[y][x-1] == '#'){
            if (keritesszamlalo(x-1,y,meret,masikjatekos,tmb,voltetmb)==false)
                return false;
        }
        if (y+1 < meret && tmb[y+1][x] == '#'){
            if (keritesszamlalo(x,y+1,meret,masikjatekos,tmb,voltetmb)==false)
                return false;
        }
        if (y-1 >= 0 && tmb[y-1][x] == '#'){
            if (keritesszamlalo(x,y-1,meret,masikjatekos,tmb,voltetmb)==false)
                return false;
        }
    }
    return true;
}

int szamlalas(char** tmb,int meret,char jatekos){
    int mennyi = 0;
    int** helyivolte;
    int** kontroll = voltetomb(meret);

    char masikjatekos;

    if (jatekos == 'X')
        masikjatekos = 'O';
    if (jatekos == 'O')
        masikjatekos = 'X';

    for (int i=0; i < meret; i++){
        for (int j=0; j < meret; j++){
            helyivolte = voltetomb(meret);
            if (kontroll[j][i] != 1 && tmb[j][i] == '#'){
                if (keritesszamlalo(i,j,meret,masikjatekos,tmb,helyivolte)==true){
                    for (int x = 0; x < meret; x++){
                        for (int y = 0;y < meret; y++){
                            if(helyivolte[y][x] == 1){
                                kontroll[y][x] = 1;
                                mennyi++;
                            }
                        }
                    }
                }
            }
            for (int i=0;i<meret;i++)
                free(helyivolte[i]);
            free(helyivolte);
        }
    }


    for (int i=0; i < meret; i++){
        for (int j=0; j < meret; j++){
            if (tmb[i][j] == jatekos){
                mennyi++;
            }
        }
    }
    for (int i=0;i<meret;i++)
        free(kontroll[i]);
    free(kontroll);
    return mennyi;
}
