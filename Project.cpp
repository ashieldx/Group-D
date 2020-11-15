#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "Cookingprocess.h"

void menu();
void add();
void end();
void sleep();
void cls();
void history();


int main(){
	menu();	
return 0;
}	

void addDessert(){
	cls();
	while(1){
		char tempname[200];
		printf("Input the name [at least 5 characters]: ");
		scanf("%[^\n]", tempname);
		getchar();
		int len = strlen(tempname);
		if(len<5){
			continue;
		}else{
			strcpy(food[x].name, tempname);
			break;
		}
	}
	while(1){
		int price;
		printf("Input the price [10-500]: $ ");
		scanf("%d", &price);
		getchar();
		if(price<10 || price > 500){
			continue;
		}else{
			food[x].price = price;
			break;
		}
	}
	while(1){
		char topping[25];
		printf("Input the topping ['Caramel' | 'Honey' | 'Syrup'](Case Insensitive): ");
		scanf("%[^\n]", topping);
		getchar();
		if(strcmp(topping,"honey") == 0 || strcmp(topping,"Honey") == 0){
			strcpy(food[x].topping, "Honey");
			break;
		}else if(strcmp(topping,"caramel") == 0 || strcmp(topping,"Caramel") == 0){
			strcpy(food[x].topping, "Caramel");
			break;
		}else if(strcmp(topping,"syrup") == 0 || strcmp(topping,"Syrup") == 0){
			strcpy(food[x].topping, "Syrup");
			break;
		}else{
			continue;
		}
	}
	while(1){
		double cal;
		printf("Insert calories [1.00 - 99.00]: ");
		scanf("%lf", &cal);
		getchar();
		if(cal < 1.00 || cal > 99.00){
			continue;
		}else{
			food[x].calories = cal;
			break;
		}
	}
	strcpy(food[x].flavor,"-");
	food[x].size = '-';
	puts("\nSuccesfully added a new menu!");
	x++;		
	char enter;
	scanf("%c",&enter);
	menu();
}

void addDrink(){
	cls();
	while(1){
		char tempname[200];
		printf("Input the name [at least 5 characters]: ");
		scanf("%[^\n]", tempname);
		getchar();
		int len = strlen(tempname);
		if(len<5){
			continue;
		}else{
			strcpy(food[x].name, tempname);
			break;
		}
	}
	while(1){
		int price;
		printf("Input the price [10-500]: $ ");
		scanf("%d", &price);
		getchar();
		if(price<10 || price > 500){
			continue;
		}else{
			food[x].price = price;
			break;
		}
	}
	while(1){
		char flavor[25];
		printf("Input the flavor ['Mint' | 'Mix Berry' | 'Cheese'](Case Sensitive): ");
		scanf("%[^\n]", flavor);
		getchar();
		if(strcmp(flavor,"Mint") == 0){
			strcpy(food[x].flavor, "Mint");
			break;
		}else if(strcmp(flavor,"Mix Berry") == 0){
			strcpy(food[x].flavor,"Mix Berry");
			break;
		}else if(strcmp(flavor,"Cheese") == 0){
			strcpy(food[x].flavor,"Cheese");
			break;
		}else{
			continue;
		}
	}
	while(1){
		char size;
		printf("Input the size [S | M | L](Case Sensitive): ");
		scanf("%c", &size);
		getchar();
		if(size == 'S'){
			food[x].size = 'S';
			break;
		}else if(size == 'M'){
			food[x].size = 'M';
			break;
		}else if(size == 'L'){
			food[x].size = 'L';
			break;
		}else{
			continue;
		}
	}
	
	strcpy(food[x].topping, "-");
	food[x].calories = 0;
	puts("\nSuccesfully added a new menu!");
	x++;
	getchar();
	menu();
}

void add(){	
	while(1){
		cls();
		puts("What do you want to add?");
		puts("[1.] Dessert");
		puts("[2.] Drink");
		printf("Choose: ");
		char choose;
		scanf("%c", &choose);
		getchar();
		switch(choose){
			case '1':
				strcpy(food[x].type, "Dessert");
				addDessert();
				break;
			case '2':
				strcpy(food[x].type, "Drink");
				addDrink();
				break;
			default:
				continue;
		}	
	}
}

void history(){
	cls();
	printf("| No | Name        | Price     | Topping    | Callories | Flavor       | size | Order Time              |\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    for(int i = 0;i < x;i++){
        printf("|%-3d | %-11s | %-9d | %-10s | %-9.2lf | %-12s | %-4c | %d/%02d/%d %02d:%02d:%02d %s  |\n",i+1 ,  food[i].name, food[i].price, food[i].topping, food[i].calories, food[i].flavor, food[i].size, orderFood[i].year, orderFood[i].month, orderFood[i].day, orderFood[i].hours, orderFood[i].minute, orderFood[i].second, orderFood[i].time_stat);
    }
	puts("");

	printf("Press Enter to continue.");
	
	getchar();
    menu();
}

void order()
{
	srand(time(NULL));
    int menuchoice, hours, minutes, seconds, day, month, year;
    if(x==0)
    {
        cls();
        puts("There is no Dessert or Drink on the list!\n");
        printf("Press ENTER to continue");
        char enter;
        scanf("%c", &enter);
        menu();
    }else
    {
        cls();
        printf("| No | Name        | Price     | Topping    | Callories | Flavor       | size |\n");
        printf("-------------------------------------------------------------------------------\n");
        for(int i = 0;i < x;i++)
        {
            printf("|%-3d | %-11s | %-9d | %-10s | %-9.2lf | %-12s | %-4c |\n",i+1 ,  food[i].name, food[i].price, food[i].topping, food[i].calories, food[i].flavor, food[i].size);
        }
        printf("Choose menu to order [1 - %d] : ", x);
        scanf("%d", &menuchoice);
		getchar();

        strcpy(orderFood[ctrorder].name, food[menuchoice-1].name);
        orderFood[ctrorder].price = food[menuchoice-1].price;
        strcpy(orderFood[ctrorder].topping, food[menuchoice-1].topping);
        orderFood[ctrorder].calories = food[menuchoice-1].calories;
        strcpy(orderFood[ctrorder].flavor, food[menuchoice-1].flavor);
        orderFood[ctrorder].size = food[menuchoice-1].size;
		strcpy(orderFood[ctrorder].type, food[menuchoice-1].type);
		
        printf("\nSuccessfully add to order list!\n\n");

    	time_t now;

    	time(&now);
 
    	struct tm *local = localtime(&now);

    	hours = local->tm_hour;          
    	minutes = local->tm_min;       
    	seconds = local->tm_sec;        

    	day = local->tm_mday;           
    	month = local->tm_mon + 1;        
    	year = local->tm_year + 1900;    

    
		if (hours < 12){
			orderFood[ctrorder].day = day;
			orderFood[ctrorder].month = month;
			orderFood[ctrorder].year = year;
			orderFood[ctrorder].second = seconds;
			orderFood[ctrorder].minute = minutes;
			orderFood[ctrorder].hours = hours;
			strcpy(orderFood[ctrorder].time_stat, "AM");
		}else{ 
			orderFood[ctrorder].day = day;
			orderFood[ctrorder].month = month;
			orderFood[ctrorder].year = year;
			orderFood[ctrorder].second = seconds;
			orderFood[ctrorder].minute = minutes;
			orderFood[ctrorder].hours = hours - 12;
			strcpy(orderFood[ctrorder].time_stat, "PM");
		}
		
		if(food[menuchoice-1].flavor[0] == '-'){
			int random = rand()%41 + 50;
			if(strcmp(food[menuchoice-1].topping, "honey") == 0 || strcmp(food[menuchoice-1].topping, "Honey") == 0){
				orderFood[ctrorder].time = random + 10;
			}
			else if(strcmp(food[menuchoice-1].topping, "caramel") == 0 || strcmp(food[menuchoice-1].topping, "Caramel") == 0){
				orderFood[ctrorder].time = random + 15;
			}
			else if(strcmp(food[menuchoice-1].topping, "syrup") == 0 || strcmp(food[menuchoice-1].topping, "Syrup") == 0){
				orderFood[ctrorder].time = random + 20;
			}
		}
		else{
			int random = rand()%41 + 10;
			if(strcmp(food[menuchoice-1].flavor, "Mint") == 0){
				orderFood[ctrorder].time = random + 10;
			}
			else if(strcmp(food[menuchoice-1].flavor, "Mix Berry") == 0){
				orderFood[ctrorder].time = random + 20;
			}
			else if(strcmp(food[menuchoice-1].topping, "Cheese") == 0){
				orderFood[ctrorder].time = random + 30;
			}
		}
		ctrorder++;
		currentorder++;

        printf("Press Enter to continue");
        getchar();
        menu();
    }
    
}

void menu(){	
	while(1){
		cls();
		puts("Welcome to Opercoocked");
		printf("Total profit: $%d\n", profit);
		puts("=============================");
		puts("[1.] Add Dessert or Beverage ");
		puts("[2.] View Cooking Process ");
		puts("[3.] View Order History ");
		puts("[4.] Order Desert or Beverage ");
		puts("[5.] Exit ");
		printf(">> ");
		char menuInput;
		scanf("%c", &menuInput);
		getchar();	
		switch(menuInput){
			case '1':
				add();
				break;
			case '2':
				process();
				break;
			case '3':
				history();
				break;
			case '4':
				order();
				break;
			case '5':
				end();
				break;
			default:
				continue;
		}		
	}	
}

