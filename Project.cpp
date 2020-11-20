#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "Cookingprocess.h"

struct Food{
	char type[10];
	char name[205];
	char flavor[25];
	char topping[25];
	double calories;
	int price;
	char size;
	struct Food *next, *prev;
} *foodHead = NULL, *foodTail = NULL, *foodCurr = NULL;

struct History{
	char type[10];
	char name[205];
	char flavor[25];
	char topping[25];
	double calories;
    int price;
    char size;
    int time;
	int day;
	int month;
	int year;
	int hours;
	int minute;
	int second;
	char time_stat[3];
	struct History *next, *prev;
} *historyHead = NULL, *historyCurr = NULL, *historyTail = NULL;

void menu();
void add();
void end();
void sleep();
void cls();
void history();
struct Food *createFood(char type[], char name[], char flavor[], char topping[], double calories, int price, char size);
void pushFoodTail(char type[], char name[], char flavor[], char topping[], double calories, int price, char size);
void lowerCase(char str[]);


int main(){
	menu();	
return 0;
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
		}else{
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
			food[x].price = price;
			break;
		}
	}
	while(1){
		printf("Input the topping ['Caramel' | 'Honey' | 'Syrup'](Case Insensitive): ");
		scanf("%[^\n]", topping);
		getchar();
		lowerCase(topping);
		if(strcmp(topping,"honey") == 0){
			topping[0] = topping[0] - 'a' + 'A';
			break;
		}else if(strcmp(topping,"caramel") == 0){
			topping[0] = topping[0] - 'a' + 'A';
			break;
		}else if(strcmp(topping,"syrup") == 0){
			topping[0] = topping[0] - 'a' + 'A';
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
			break;
		}
	}
	pushFoodTail("", tempname, "-", topping, cal, price, '-');
	puts("\nSuccesfully added a new menu!");
	x++;		
	char enter;
	scanf("%c",&enter);
	menu();
}

void addDrink(){
	cls();
	char tempname[200];
	int price;
	char flavor[25];
	char size;
	while(1){
		printf("Input the name [at least 5 characters]: ");
		scanf("%[^\n]", tempname);
		getchar();
		int len = strlen(tempname);
		if(len<5){
			continue;
		}else{
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
			break;
		}
	}
	while(1){
		printf("Input the flavor ['Mint' | 'Mix Berry' | 'Cheese'](Case Sensitive): ");
		scanf("%[^\n]", flavor);
		getchar();
		if(strcmp(flavor,"Mint") == 0){
			break;
		}else if(strcmp(flavor,"Mix Berry") == 0){
			break;
		}else if(strcmp(flavor,"Cheese") == 0){
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
			break;
		}else if(size == 'M'){
			break;
		}else if(size == 'L'){
			break;
		}else{
			continue;
		}
	}
	pushFoodTail("-", tempname, flavor, "-", 0, price, size);
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
	// printf("| No | Name        | Price     | Topping    | Callories | Flavor       | size | Order Time              |\n");
    // printf("---------------------------------------------------------------------------------------------------------\n");
    // for(int i = 0;i < x;i++){
    //     printf("| %-2d | %-11s | %-9d | %-10s | %-9.2lf | %-12s | %-4c | %d/%02d/%d %02d:%02d:%02d %s  |\n",i+1 ,  food[i].name, food[i].price, food[i].topping, food[i].calories, food[i].flavor, food[i].size, orderFood[i].year, orderFood[i].month, orderFood[i].day, orderFood[i].hours, orderFood[i].minute, orderFood[i].second, orderFood[i].time_stat);
    // }
	// puts("");
	printf("| No | Name        | Price     | Topping    | Callories | Flavor       | size | Order Time              |\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
	historyCurr = historyHead;
	int counter = 1;
	while(historyCurr != NULL){
		printf("| %-2d | %-11s | %-9d | %-10s | %-9.2lf | %-12s | %-4c | %d/%02d/%d %02d:%02d:%02d %s  |\n", counter ,  historyCurr->name, historyCurr->price, historyCurr->topping, historyCurr->calories, historyCurr->flavor, historyCurr->size, historyCurr->year, historyCurr->month, historyCurr->day, historyCurr->hours, historyCurr->minute, historyCurr->second, historyCurr->time_stat);
		historyCurr = historyCurr->next;
		counter++;
	}
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
		foodCurr = foodHead;
		int index = 1;
		while(foodCurr != NULL){
            printf("|%-3d | %-11s | %-9d | %-10s | %-9.2lf | %-12s | %-4c |\n", index ,  foodCurr->name, foodCurr->price, foodCurr->topping, foodCurr->calories, foodCurr->flavor, foodCurr->size);
			index++;
			foodCurr = foodCurr->next;
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
		char timeStat[5];
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
			strcpy(timeStat, "AM");
		}else{ 
			orderFood[ctrorder].day = day;
			orderFood[ctrorder].month = month;
			orderFood[ctrorder].year = year;
			orderFood[ctrorder].second = seconds;
			orderFood[ctrorder].minute = minutes;
			orderFood[ctrorder].hours = hours - 12;
			hours -= 12;
			strcpy(timeStat, "PM");
		}
		int time;
		if(food[menuchoice-1].flavor[0] == '-'){
			int random = rand()%41 + 50;
			if(strcmp(food[menuchoice-1].topping, "honey") == 0 || strcmp(food[menuchoice-1].topping, "Honey") == 0){
				time = random + 10;
				orderFood[ctrorder].time = random + 10;
			}
			else if(strcmp(food[menuchoice-1].topping, "caramel") == 0 || strcmp(food[menuchoice-1].topping, "Caramel") == 0){
				time = random + 15;
				orderFood[ctrorder].time = random + 15;
			}
			else if(strcmp(food[menuchoice-1].topping, "syrup") == 0 || strcmp(food[menuchoice-1].topping, "Syrup") == 0){
				time = random + 20;
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

void lowerCase(char str[]){
	int counter = 0;
	while(str[counter] != '\0'){
		if(str[counter] <= 'Z' && str[counter] >= 'A'){
			str[counter] = str[counter] - 'A' + 'a';
		}
		counter++;
	}
	return;
}
struct Food *createFood(char type[], char name[], char flavor[], char topping[], double calories, int price, char size){
	struct Food *newFood = (struct Food*)malloc(sizeof(struct Food));
	strcpy(newFood->type, type);
	strcpy(newFood->name, name);
	strcpy(newFood->flavor, flavor);
	strcpy(newFood->topping, topping);
	newFood->calories = calories;
	newFood->price = price;
	newFood->size = size;
	newFood->next = NULL;
	newFood->prev = NULL;
	return newFood;
}

void pushFoodTail(char type[], char name[], char flavor[], char topping[], double calories, int price, char size){
	struct Food* temp = createFood(type, name, flavor, topping, calories, price, size);
	if(foodHead == NULL){
		foodHead = foodTail = temp;
	}
	else{
		temp->prev = foodTail;
		foodTail->next = temp;
		foodTail = temp;
	}
	return;
}

struct History *createHistory(char type[], char name[], char flavor[], char topping[], double calories, int price, char size, int time, int day, int month, int year, int hours, int minute, int second, char time_stat[]){
	struct History *newHistory = (struct History*)malloc(sizeof(struct History));
	strcpy(newHistory->name, name);
    newHistory->price = price;
    strcpy(newHistory->topping, topping);
    newHistory->calories = calories;
    strcpy(newHistory->flavor, flavor);
    newHistory->size = size;
	strcpy(newHistory->type, type);
	return newHistory;
}