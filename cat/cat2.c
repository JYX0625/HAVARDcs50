#include <stdio.h>
void meow();
void main() {
    int times;
    printf("How many times do you want the cat to meow?\n");
    scanf("%d", &times);
    while (times > 0) {
        meow();
        times--;
    }
}
void meow() {
    printf("Meow\n");
}