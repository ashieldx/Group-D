#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include "Variable.h"

void process(){

    cls();
    if(currentorder == 0){
        puts("There is no cooking process recently!\n");
        puts("Press Enter to continue");
        getchar();
        return;
    }
    else{

        int temp = 1;
        printf("| No  | Type     | Name               | Price  | Time Left |\n");
        puts("----------------------------------------------------------------");
        for(int i = 0 ; i < ctrorder ; i++){
            if(orderFood[i].time <= 0){
                continue;
            }
            orderFood[i].time -= 10;
            if(orderFood[i].time <= 0){
                currentorder--;
            }
        }
        for(int i = 0 ; i < ctrorder ; i++){
            if(orderFood[i].time <= 0){
                continue;
            }
            else{
                printf("| %d | %s | %s | $%d | %d    s|\n", temp++, orderFood[i].type, orderFood[i].name, orderFood[i].price, orderFood[i].time);
            }
        }


        getchar();
    }

}