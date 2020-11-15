#include<stdio.h>
int main()
{
    printf("| NO  | Name              | Price   |  Topping | Callories| Flavor | Size |");
    printf("| %-5d  | %5s      | %5d | %s | %.2lf | %s | %s|",1,"Lime Ball",20,"Caramel",1.50, "Mint","Min");
    printf("| %-5d  | %5s      | %5d | %s | %.2lf | %s | %s|",2,"Mojito",10,"Caramel",1.50, "Mint","Min");
    return 0;
}