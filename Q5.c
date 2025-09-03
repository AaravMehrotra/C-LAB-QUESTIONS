/*
write a program to accept 2 numbers from user and display the sources of even and cubes of odd numbers*/
#include<stdio.h>
int main(){
    int num1,num2;
    printf("enter two numbers ");
    scanf("%d %d",&num1,&num2);
    for(int i=num1;i<=num2;i++){
        if(i%2==0){
            printf("square of %d is %d\n",i,i*i);
        }
        else{
            printf("cube of %d is %d\n",i,i*i*i);
        }
    }
    return 0;
}