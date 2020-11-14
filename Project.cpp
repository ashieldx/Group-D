#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

void menu();
void add();
int profit = 0, x = 0;

struct list{
	int type;
	char name[205];
	char flavor[25];
	char topping[25];
	double calories;
	int price;
	char size;
};
struct list food[500];

void cls(){
	for(int i =0;i<60;i++){
		puts("");
	}
	return;
}

void sleep(){
	for(int i=0;i<100000000;i++){
		printf("");
	}
	return;
}

void exit(){
	cls();
	printf("TERIMA KASIH");
    exit(0);                     	
}

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
		printf("Input the topping ['Caramel' | 'Honey' | 'Syrup']: ");
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
			food[x].size ='S';
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
				addDessert();
				break;
			case '2':
				addDrink();
				break;
			default:
				continue;
		}	
	}
}

void order(){
	if(x==0){
		cls();
		puts("There is no Dessert or Drink on the list!\n");
		printf("Press ENTER to continue");
		char enter;
		scanf("%c", &enter);
		menu();
	}else{
		puts("Food List: ");
		cls();
		for(int i =0;i<x;i++){
			if(food[i].calories == 0){
				printf("%s %d %s - %s %c\n", food[i].name, food[i].price, food[i].topping, food[i].flavor, food[i].size);
			}else{
				printf("%s %d %s %.2lf %s %c\n", food[i].name, food[i].price, food[i].topping, food[i].calories, food[i].flavor, food[i].size);
			}
		}
		char enter;
		scanf("%c", &enter);
		menu();
	}
	
}

void menu(){	
	while(1){
		cls();
		printf("Total profit: $%d\n", profit);
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
				//process();
				break;
			case '3':
				//history();
				break;
			case '4':
				order();
				break;
			case '5':
				exit();
				break;
			default:
				continue;
		}		
	}	
}
