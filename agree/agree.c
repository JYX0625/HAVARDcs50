#include <stdio.h>
int main() {
    printf("Do you agree? \n");
    char a;
    scanf("%c",&a);
    if (a == 'y' || a == 'Y') {
        printf("You agreed! \n");
    } else if (a == 'n' || a == 'N') {
        printf("You disagreed! \n");
    } else {
        printf("Invalid input! \n");
    }
}