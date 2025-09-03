#include <stdio.h>

int main(){
    int vote;
    int x=0,y=0,z=0,c=1;
    char a;

    while(c){
        printf("Enter 1 to vote for x\nEnter 2 to vote for y\nEnter 3 to vote for z\nYour choice: ");
        scanf("%d",&vote);

        switch(vote){
        case 1:
            x += 1;
            break;
        case 2:
            y += 1;
            break;
        case 3:
            z += 1;
            break;
        }

        printf("Enter 'N' to exit! OR 'Y' to continue\n");
        scanf(" %c",&a);

        if (a=='N'||a=='n'){
            c = 0;
        }
        else if(a=='y'||a=='Y'){
            c = 1;
        }
        else{
            printf("Invalid input!\n\n");
            break;
        }
    }
    printf("x: %d\n",x);
    printf("y: %d\n",y);
    printf("z: %d\n",z);

    if((x>=y)&&(y>=z)){
        printf("X is the winner");} 
    else if((y>=x)&&(y>=z)){
        printf("Y is the winner");} 
    else{
        printf("Z is the winner");}
    printf("\nExiting!");
}