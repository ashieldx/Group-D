#include<stdio.h>
int main()
{
    printf("| NO  | Name              | Price   |  Topping     | Callories| Flavor | Size |\n");
    printf("| %2d  | %-12s      | %7d | %-12s | %-8.2lf | %-6s | %-5s|\n",1,"Lime Ball",20,"Caramel",1.50, "-","-");
    printf("| %2d  | %-12s      | %7d | %-12s | %-8s | %-6s | %-5s|\n",2,"Mojito",10,"-","-", "Mint","M");
    printf("Choose a menu to order [1-2]: ");
    int choose;
    scanf("%d",&choose);
    puts("");
    puts("Sucessfully add to order list!\n");
    printf("Press enter to continuue"); getchar(); getchar();
    
    return 0;
}