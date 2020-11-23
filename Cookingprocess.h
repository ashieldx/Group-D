<<<<<<< Updated upstream
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
        puts("------------------------------------------------------------");

        int i = 0;
        curr2 = head2;
        while(i < ctrorder){
            if(curr2->time <= 0){
                i++;
                curr2 = curr2->next;
                continue;
            }

            curr2->time -= 10;

            if(curr2->time <= 0){
                profit += curr2->price;
                currentorder--;
            }
            curr2 = curr2->next;
            i++;
        }

        i = 0;
        curr2 = head2;
        while(i < ctrorder){
            if(curr2->time <= 0){
                curr2 = curr2->next;
                i++;
                continue;
            }
            else{
                printf("| %-3d | %-8s | %-18s | $%-5d | %-8ds |\n", temp++, curr2->type, curr2->name, curr2->price, curr2->time);
            }
            i++;
            curr2 = curr2->next;
        }

        puts("");

	    printf("Press Enter to continue.");
        
        getchar();
        
    }

=======
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
        puts("------------------------------------------------------------");
        for(int i = 0 ; i < ctrorder ; i++){
            if(orderFood[i].time <= 0){
                continue;
            }
            orderFood[i].time -= 10;
            if(orderFood[i].time <= 0){
                profit += orderFood[i].price;
                currentorder--;
            }
        }
        for(int i = 0 ; i < ctrorder ; i++){
            if(orderFood[i].time <= 0){
                continue;
            }
            else{
                printf("| %-3d | %-8s | %-18s | $%-5d | %-8ds |\n", temp++, orderFood[i].type, orderFood[i].name, orderFood[i].price, orderFood[i].time);
            }
        }

        puts("");

	    printf("Press Enter to continue.");
        
        getchar();
    }

>>>>>>> Stashed changes
}