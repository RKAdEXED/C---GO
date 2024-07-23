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

void menu(){
    char valaszt;
    printf("Egyeduli : e   Jatek: g   Dicsoseglista: b   Kilepes: s\nmenupont: ");
    while (scanf("%c",&valaszt)==1){
        if (valaszt == 'g')
            jatek();
        if (valaszt == 'e')
            jatek_e();
        if (valaszt == 'b'){
            scoreboardmenu();
        }
        if (valaszt == 's')
            break;
    }
}
