#include<stdio.h>
int main() 
{
int num, i, prime;
printf("enter a number");
scanf("%d", &num);
if (num < 1) {
prime = 0;
}
for (i =2; i <= num / 2; i++){
if (num % i == 0) {
prime = 0;
}
}
if (prime == 1) {
printf("%d is prime", num);
} else {
printf("%d is not a prime\n", num);
}
return 0;
}