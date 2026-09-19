#include <stdio.h>
void main() {
    int times;
    do{ 
        printf("How many times do you want the cat to meow?\n");
        scanf("%d", &times);
    }while (times <= 0);
            for(times; times > 0; times--) {
            printf("Meow\n");}
  
    
}