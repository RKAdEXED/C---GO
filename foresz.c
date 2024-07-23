#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "debugmalloc.h"
#include "files.h"
#include "kerites_jatekmenet.h"
#include "altalanos.h"
#include "szamlalo.h"
#include "foresz.h"
#include "menu.h"

void jatek(){
    int meret = palyameret();
    char** tabla = palya(meret);
    int x = -1,y = -1, jatekos = 0,skippszamlalo = 0;
    char skipp = 'n';
    palyairas(meret,tabla);

    printf("Lepes megadasa x:y forma\n0. jatekos: ");
    while (scanf("%d:%d",&x,&y) == 2 || scanf("%c",&skipp) == 1){
        if (skipp == 's'){
            jatekos++;
            skippszamlalo++;
            skipp = 'n';
            if (skippszamlalo == 2){
                break;
            }
        }
        else{
            skippszamlalo = 0;
            jatekos++;
        }
        if (jatekos == 2)
            jatekos = 0;
        if (x != -1 || y != -1){
            csere(x,y,meret,jatekos,tabla);
            keritvecsere(meret,tabla);
            palyairas(meret,tabla);
        }

        printf("\n%d. jatekos jon: ",jatekos);
        skipp = 'n';
    }
    int jatekos_1_pont = szamlalas(tabla,meret,'X');
    int jatekos_0_pont = szamlalas(tabla,meret,'O');
    printf("\n1.jatek: %d\n2.jatek: %d\n", jatekos_0_pont, jatekos_1_pont);
    int* eddigi_0,* eddigi_1, gamer_0 = 0, gamer_1 = 0;
    eddigi_0 = &gamer_0;
    eddigi_1 = &gamer_1;
    int ki;
    beolvas(eddigi_0,eddigi_1);

    if (jatekos_0_pont > jatekos_1_pont)
        ki = 0;
    if (jatekos_0_pont < jatekos_1_pont)
        ki = 1;
    if (jatekos_0_pont == jatekos_1_pont)
        ki = 2;
    mentes(eddigi_0,eddigi_1,ki);
    for (int i=0; i<meret; i++)
        free(tabla[i]);
    free(tabla);
}

void jatek_e(){
    int meret = palyameret();
    char** tabla = palya(meret);
    int x = -1,y = -1, jatekos = 0,skippszamlalo = 0;
    char skipp = 'n';
    palyairas(meret,tabla);
    printf("Ki kezd?: ");
    int kia = scanf("%d",&kia);

    printf("Lepes megadasa x:y forma\n0. jatekos: ");
    while (scanf("%d:%d",&x,&y) == 2 || scanf("%c",&skipp) == 1){
        if (skipp == 's'){
            jatekos++;
            skippszamlalo++;
            skipp = 'n';
            if (skippszamlalo == 2){
                break;
            }
        }
        else{
            skippszamlalo = 0;
            jatekos++;
        }
        if (jatekos == 2)
            jatekos = 0;
        if (kia == jatekos){
            if (x != -1 || y != -1){
                csere(x,y,meret,jatekos,tabla);
                keritvecsere(meret,tabla);
                palyairas(meret,tabla);
            }
        }
        else{
            if (kia == 0){
                territory_ai(tabla,meret,'X');
            }
            else{
                territory_ai(tabla,meret,'O');
            }
        }

        printf("\n%d. jatekos jon: ",jatekos);
        skipp = 'n';
    }
    int jatekos_1_pont = szamlalas(tabla,meret,'X');
    int jatekos_0_pont = szamlalas(tabla,meret,'O');
    printf("\n1.jatek: %d\n2.jatek: %d\n", jatekos_0_pont, jatekos_1_pont);
    int* eddigi_0,* eddigi_1, gamer_0 = 0, gamer_1 = 0;
    eddigi_0 = &gamer_0;
    eddigi_1 = &gamer_1;
    int ki;
    beolvas(eddigi_0,eddigi_1);

    if (jatekos_0_pont > jatekos_1_pont)
        ki = 0;
    if (jatekos_0_pont < jatekos_1_pont)
        ki = 1;
    if (jatekos_0_pont == jatekos_1_pont)
        ki = 2;
    mentes(eddigi_0,eddigi_1,ki);
    for (int i=0; i<meret; i++)
        free(tabla[i]);
    free(tabla);
}


void territory_ai(char** palya, int meret, char jatekos) {
    int best_x = -1, best_y = -1, best_score = -1;
    for (int x = 0; x < meret; x++) {
        for (int y = 0; y < meret; y++) {
            if (palya[y][x] == '#') {
                int score = calculate_score(palya, meret, jatekos, x, y);
                if (score > best_score) {
                    best_score = score;
                    best_x = x;
                    best_y = y;
                }
            }
        }
    }
    palya[best_y][best_x] = jatekos;
}

int calculate_score(char** board, int board_size, char player, int x, int y) {
    char opponent = (player == 'X') ? 'O' : 'X';
    int score = 0;
    bool visited[board_size][board_size];
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            visited[i][j] = false;
        }
    }
    score = dfs(board, board_size, x, y, player, opponent, visited);
    return score;
}

int dfs(char** board, int board_size, int x, int y, char player, char opponent, bool visited[board_size][board_size]) {
    if (x < 0 || x >= board_size || y < 0 || y >= board_size || visited[y][x] || board[y][x] == opponent) {
        return 0;
    }
    visited[y][x] = true;
    int score = 1;
    score += dfs(board, board_size, x-1, y, player, opponent, visited);
    score += dfs(board, board_size, x+1, y, player, opponent, visited);
    score += dfs(board, board_size, x, y-1, player, opponent, visited);
    score += dfs(board, board_size, x, y+1, player, opponent, visited);
    return score;
}
