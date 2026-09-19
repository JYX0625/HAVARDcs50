#include <stdio.h>
int main() {
    printf("what is x?  ");
    int x;
    scanf("%d", &x);
    printf("\n");
    printf("what is y?  ");
    int y;
    scanf("%d", &y);
    if(x<y)
        printf("x is less than y\n");
    else if(x==y)
        printf("x is equal to y\n");
     else
        printf("x is greater than y\n");
    return 0;
}
