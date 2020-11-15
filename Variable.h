#include <stdio.h>
#include <stdlib.h>

int profit = 0, x = 0, ctrorder = 0, currentorder = 0;

struct list{
	char type[10];
	char name[205];
	char flavor[25];
	char topping[25];
	double calories;
	int price;
	char size;
};
struct list food[500];

struct list2{
    char type[10];
    char name[205];
    char flavor[25];
    char topping[25];
    double calories;
    int price;
    char size;
    int time;
};
struct list2 orderFood[500];

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

void end(){
	cls();
	puts("_/_/_/_/_/  _/                            _/            _/      _/");sleep();                  
	puts("   _/      _/_/_/      _/_/_/  _/_/_/    _/  _/          _/  _/    _/_/    _/    _/  ");sleep();  
	puts("  _/      _/    _/  _/    _/  _/    _/  _/_/              _/    _/    _/  _/    _/");sleep();      
	puts(" _/      _/    _/  _/    _/  _/    _/  _/  _/            _/    _/    _/  _/    _/ ");sleep();      
	puts("_/      _/    _/    _/_/_/  _/    _/  _/    _/          _/      _/_/      _/_/_/ ");sleep();    
    exit(0);                     	
}