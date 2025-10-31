#include <stdio.h>

int main() {
    int num1, num2, sum;
    int *ptr1, *ptr2;
    ptr1 = &num1;
    ptr2 = &num2;
    printf("Enter number 1: ");
    scanf("%d", ptr1);
    printf("Enter number 2: ");
    scanf("%d", ptr2);
    sum = *ptr1 + *ptr2;
    printf("Sum = %d\n", sum);
    return 0;
}