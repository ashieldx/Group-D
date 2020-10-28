#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

void menu();
int profit = 0;

void cls(){
	for(int i =0;i<60;i++){
		puts("");
	}
	return;
}

void sleep(){
	for(long long i=0;i<100000;i++){
		printf("");
	}
	return;
}

void exit(){
	cls();
	
}

int main(){
	menu();
	return 0;
}

void menu(){
	while(1){
		cls();
		puts(" ______     ______   ______     ______     ______     ______     ______     __  __     ______     _____    ");
		puts("/\\  __ \\   /\\  == \\ /\\  ___\\   /\\  == \\   /\\  ___\\   /\\  __ \\   /\\  __ \\   /\\ \\/ /    /\\  ___\\   /\\  __-.  ");
		puts("\\ \\ \\/\\ \\  \\ \\  _-/ \\ \\  __\\   \\ \\  __<   \\ \\ \\____  \\ \\ \\/\\ \\  \\ \\ \\/\\ \\  \\ \\  _\"-.  \\ \\  __\\   \\ \\ \\/\\ \\ ");
		puts(" \\ \\_____\\  \\ \\_\\    \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\____- ");
		puts("  \\/	_____/   \\/_/     \\/_____/   \\/_/ /_/   \\/_____/   \\/_____/   \\/_____/   \\/_/\\/_/   \\/_____/   \\/____/ ");
		puts("==========================================================================================================");
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
		if(menuInput == '1'){
			//add();
		}else if(menuInput == '2'){
			//process();
		}else if(menuInput == '3'){
			//history();
		}else if(menuInput == '4'){
			//order();
		}else if(menuInput == '5'){
			return 0;
		}else{
			continue;
		}
	}
		
}

