#include <stdio.h>
int main(){
int num, factorial=1;
printf("enter an integer ");
scanf("%d", &num);
int i=num;
while(i>0)
{
factorial= factorial*i;
i--;
}
printf("Factorial of the number %d is %d\n", num, factorial);
return 0;
}