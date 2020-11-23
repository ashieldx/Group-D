#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int profit = 0, x = 0, ctrorder = 0, currentorder = 0;

struct Node{
	char type[10];
	char name[205];
	char flavor[25];
	char topping[25];
	double calories;
	int price;
	char size;
	Node *next;
} *head, *tail, *curr;

struct Node2{
    char type[10];
    char name[205];
    char flavor[25];
    char topping[25];
    double calories;
    int price;
    char size;
	int day;
	int month;
	int year;
	int hours;
	int minute;
	int second;
	char time_stat[3];
	int time;
	Node2 *next;
} *head2, *tail2, *curr2;

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


Node *createNode(char type[], char name[], char flavor[], char topping[], double calories, int price, char size) //node order
{
    Node *temp = (Node*)malloc(sizeof(Node));
    strcpy(temp->type, type);
	strcpy(temp->name, name);
	strcpy(temp->flavor, flavor);
	strcpy(temp->topping, topping);
	temp->calories = calories;
	temp->price = price;
	temp->size = size;
    temp->next = NULL;
    return temp;
}
Node2 *createNode2(char type[], char name[], char flavor[], char topping[], double calories, int price, char size, int day, int month, int year, int hours, int minute, int second, char time_stat[], int time)
{ // node history/purchase 
	Node2 *temp = (Node2*)malloc(sizeof(Node2));
    strcpy(temp->type, type);
	strcpy(temp->name, name);
	strcpy(temp->flavor, flavor);
	strcpy(temp->topping, topping);
	temp->calories = calories;
	temp->price = price;
	temp->size = size;
	temp->day = day;
	temp->month = month;
	temp->year = year;
	temp->hours = hours;
	temp->minute = minute;
	temp->second = second;
	temp->time = time;
	strcpy(temp->time_stat, time_stat);
    temp->next = NULL;
    return temp;
}
void pushHead1(char type[], char name[], char flavor[], char topping[], double calories, int price, char size) // ini buat push item
{
    Node *temp = createNode(type, name, flavor, topping, calories, price, size);
    if(!head) 
    {
        head = tail = temp;
    } else
    {
        temp->next = head;
        head = temp;
    }
}
void pushTail1(char type[], char name[], char flavor[], char topping[], double calories, int price, char size)  // ini buat push item
{
  Node *temp = createNode(type, name, flavor, topping, calories, price, size);
  if(!head) 
  { 
    head = tail = temp;
  } else 
  { 
    tail->next = temp; 
    tail = temp; 
  }
}
void pushHead2(char type[], char name[], char flavor[], char topping[], double calories, int price, char size, int day, int month, int year, int hours, int minute, int second, char time_stat[], int time) // ini buat push history
{ // push history
    Node2 *temp = createNode2(type, name, flavor, topping, calories, price, size, day, month, year, hours, minute, second, time_stat, time);
    if(!head2) 
    {
        head2 = tail2 = temp;
    } else
    {
        temp->next = head2;
        head2 = temp;
    }
}
void pushTail2(char type[], char name[], char flavor[], char topping[], double calories, int price, char size, int day, int month, int year, int hours, int minute, int second, char time_stat[], int time) // ini buat push history
{ // push history
    Node2 *temp = createNode2(type, name, flavor, topping, calories, price, size, day, month, year, hours, minute, second, time_stat, time);
    if(!head2) 
    {
        head2 = tail2 = temp;
    } else
    {
        tail2->next = temp;
        tail2 = temp;
    }
}
Node* InsertOrder(int menuchoice)
{
	Node *temp;
	curr = head;
	int i = 0;
	while(curr)
	{
		if(i == menuchoice-1)
		{
			temp = curr;
			break;
		}
        curr = curr->next;
		i++;
	}
	return temp;
}

void printorder()
{
	if(!head)
	{
		return;
	} else
	{
		curr = head;
		int i = 0;
		while(curr)
		{
			printf("|%-3d | %-11s | %-9d | %-10s | %-9.2lf | %-12s | %-4c |\n", i+1 ,  curr->name, curr->price, curr->topping, curr->calories, curr->flavor, curr->size);
            curr = curr->next;
			i++;
		}
	}
}
void printhistory()
{
	if(!head2)
    {
        return;
    } else
    {
        curr2 = head2;
		int i = 0;
        while(curr2)
        {
            printf("|%-3d | %-11s | %-9d | %-10s | %-9.2lf | %-12s | %-4c | %d/%02d/%d %02d:%02d:%02d %s  |\n",i+1 ,  curr2->name, curr2->price, curr2->topping, curr2->calories, curr2->flavor, curr2->size, curr2->year, curr2->month, curr2->day, curr2->hours, curr2->minute, curr2->second, curr2->time_stat);
            curr2 = curr2->next;
			i++;
        }
    }
}