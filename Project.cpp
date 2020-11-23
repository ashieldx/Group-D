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
void History(){
	
}
void addDessert(){
	cls();
	char tempname[200];
	int price;
	char topping[25];
	double cal;
	while(1){
		
		printf("Input the name [at least 5 characters]: ");
		scanf("%[^\n]", tempname);
		getchar();
		int len = strlen(tempname);
		if(len<5){
			continue;
		}else
		{
			//strcpy(food[x].name, tempname);
			break;
		}
	}
	while(1){
		printf("Input the price [10-500]: $ ");
		scanf("%d", &price);
		getchar();
		if(price<10 || price > 500){
			continue;
		}else{
			//food[x].price = price;
			break;
		}
	}
	while(1){
		printf("Input the topping ['Caramel' | 'Honey' | 'Syrup'](Case Insensitive): ");
		scanf("%[^\n]", topping);
		getchar();
		if(strcmp(topping,"honey") == 0 || strcmp(topping,"Honey") == 0){
			strcpy(topping, "Honey");
			break;
		}else if(strcmp(topping,"caramel") == 0 || strcmp(topping,"Caramel") == 0){
			strcpy(topping, "Caramel");
			break;
		}else if(strcmp(topping,"syrup") == 0 || strcmp(topping,"Syrup") == 0){
			strcpy(topping, "Syrup");
			break;
		}else{
			continue;
		}
	}
	while(1){
		printf("Insert calories [1.00 - 99.00]: ");
		scanf("%lf", &cal);
		getchar();
		if(cal < 1.00 || cal > 99.00){
			continue;
		}else{
			//food[x].calories = cal;
			break;
		}
	}
	//strcpy(food[x].flavor,"-");
	//food[x].size = '-';
	puts("\nSuccesfully added a new menu!");	
	pushTail1("1", tempname, "-", topping, cal, price, '-');	
	x++;
	char enter;
	scanf("%c",&enter);
	menu();
}

void addDrink(){
	char tempname[200];
	char flavor[25];
	int price;
	char size;
	cls();
	while(1){
		printf("Input the name [at least 5 characters]: ");
		scanf("%[^\n]", tempname);
		getchar();
		int len = strlen(tempname);
		if(len<5){
			continue;
		}else{
			//strcpy(food[x].name, tempname);
			break;
		}
	}
	while(1){
		printf("Input the price [10-500]: $ ");
		scanf("%d", &price);
		getchar();
		if(price<10 || price > 500)
		{
			continue;
		}else
		{
			//food[x].price = price;
			break;
		}
	}
	while(1){
		printf("Input the flavor ['Mint' | 'Mix Berry' | 'Cheese'](Case Sensitive): ");
		scanf("%[^\n]", flavor);
		getchar();
		if(strcmp(flavor,"Mint") == 0){
			strcpy(flavor, "Mint");
			break;
		}else if(strcmp(flavor,"Mix Berry") == 0){
			strcpy(flavor,"Mix Berry");
			break;
		}else if(strcmp(flavor,"Cheese") == 0){
			strcpy(flavor,"Cheese");
			break;
		}else{
			continue;
		}
	}
	while(1){
		printf("Input the size [S | M | L](Case Sensitive): ");
		scanf("%c", &size);
		getchar();
		if(size == 'S'){
			size = 'S';
			break;
		}else if(size == 'M'){
			size = 'M';
			break;
		}else if(size == 'L'){
			size = 'L';
			break;
		}else{
			continue;
		}
	}
	double calories = 0;
	puts("\nSuccesfully added a new menu!");
	pushTail1("2", tempname, flavor, "-", calories , price, size);
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
				//strcpy(food[x].type, "Dessert");
				addDessert();
				break;
			case '2':
				//strcpy(food[x].type, "Drink");
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
    printhistory();
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
        printorder();
        printf("Choose menu to order [1 - %d] : ", x);
        scanf("%d", &menuchoice);
		getchar();
		struct Node *result = InsertOrder(menuchoice);
		/*
        strcpy(orderFood[ctrorder].name, food[menuchoice-1].name);
        orderFood[ctrorder].price = food[menuchoice-1].price;
        strcpy(orderFood[ctrorder].topping, food[menuchoice-1].topping);
        orderFood[ctrorder].calories = food[menuchoice-1].calories;
        strcpy(orderFood[ctrorder].flavor, food[menuchoice-1].flavor);
        orderFood[ctrorder].size = food[menuchoice-1].size;
		strcpy(orderFood[ctrorder].type, food[menuchoice-1].type);
		*/

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

		int time;
		if(result->flavor[0] == '-'){
			int random = rand()%41 + 50;
			if(strcmp(result->topping, "honey") == 0 || strcmp(result->topping, "Honey") == 0){
				time = random + 10;
			}
			else if(strcmp(result->topping, "caramel") == 0 || strcmp(result->topping, "Caramel") == 0){
				time = random + 15;
			}
			else if(strcmp(result->topping, "syrup") == 0 || strcmp(result->topping, "Syrup") == 0){
				time = random + 20;
			}
			// printf("randtime %d %d\n", random, time);
		}
		else{
			int random = rand()%41 + 10;
			if(strcmp(result->flavor, "Mint") == 0){
				time = random + 10;
			}
			else if(strcmp(result->flavor, "Mix Berry") == 0){
				time = random + 20;
			}
			else if(strcmp(result->flavor, "Cheese") == 0){
				time = random + 30;
			}
		}

		ctrorder++;
		currentorder++;
		if (hours < 12){
			pushTail2(result->type, result->name, result->flavor, result->topping, result->calories, result->price, result->size, day, month, year, hours, minutes, seconds, "AM", time);
		}else{ 
			pushTail2(result->type, result->name, result->flavor, result->topping, result->calories, result->price, result->size, day, month, year, hours-12, minutes, seconds, "PM", time);
		}
        printf("Press Enter to continue");
        getchar();
        menu();
		
    }
    
}

void menu(){	
	while(1){
		cls();
		puts("Welcome to Opercooked");
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

