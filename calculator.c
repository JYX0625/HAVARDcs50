#include <stdio.h>
int main() {
    int jackpot = 0;
    float a=1;
    float b=3;
    float c=a/b;
    printf("c=%.20f\n",c);
/*while(1) {
  printf("您是否希望将奖池金额增加1000元?\n");
  char answer;
  scanf(" %c", &answer);
  if(answer == 'y' || answer == 'Y') {
    jackpot += 1000;
    printf("奖池金额已增加1000元,目前的金额为%d元。\n", jackpot);
  } else {
    printf("操作已取消。\n");
    break;
  }
}*/
  return 0;
}