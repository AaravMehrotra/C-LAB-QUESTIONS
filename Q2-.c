#include <stdio.h>

int main() {
    int n, a = 0, b = 1, c;
    printf("Enter an integer  ");
    scanf("%d", &n);
    {
    printf("%d is a part of the Fibonacci series.\n", n);
    return 0;
    }
    c = a + b;
    while (c <= n) {
    if (c == n) {
    printf("%d is a part of the Fibonacci series.\n", n);
    return 0;
    }
    a = b;
    b = c;
    c = a + b;
    }
    printf("%d is not a part of the Fibonacci series.\n", n);
    return 0;
}