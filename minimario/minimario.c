#include <stdio.h>
int main() {
 int Height;
 while(1){
 printf("Height:");
 scanf("%d", &Height);
 if(Height > 0 ) {
     break;
 }
 }
 for(int i=0;i<Height;i++){
    for(int j=Height;j<Height+i+1;j++)
    {
        printf("#");
    }
  printf("\n");
 }
}