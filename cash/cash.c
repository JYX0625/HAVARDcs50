#include <stdio.h>
int main() {
int change ;
while(1) {
printf("Change owed: ");
scanf("%d", &change);
if (change > 0) {
    break;
}
      }
int a=change / 25;
int b=(change % 25) / 10;
int c=(change % 25 % 10) / 5;
int d=change % 25 % 10 % 5;
printf(" %d\n", a+b+c+d);
 }