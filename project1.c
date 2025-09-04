#include <stdio.h>

int main() {
    int cost = 0, users, ticketType, userChoice, totalCost, totalUsers;

    printf("Price for seats: \n");
    printf("Premium Seat -> $200 \n");
    printf("Standard Seat -> $150 \n");
    printf("Economy seat -> $100");

    do {
        printf("Enter the type of ticket you want! \n");
        printf("Enter 1 for premium, 2 for standard and 3 for economy \t");
        scanf("%d",&ticketType);
        switch (ticketType) {
            case 1:
                printf("Enter the number of tickets for premium seats: \t");
                scanf("%d",&users);
                cost = users * 200;
                totalUsers += users;
                totalCost += cost;
                printf("Your total cost would be: %d",cost);
                break;
                case 2:
                printf("Enter the number of tickets for standard seats: \t");
                scanf("%d",&users);
                totalUsers += users;
                cost = users * 150;
                totalCost += cost;
                printf("Your total cost would be: %d", cost);
                break;
                case 3:
                printf("Enter the number of tickets for economy seats: \t");
                scanf("%d",&users);
                cost = users * 100;
                totalUsers += users;
                totalCost += cost;
                printf("Your total cost would be: %d", cost);
                break;
                default:printf("Enter a valid ticket type [1-3]!!");
        }
        printf("Enter any number except 0 if you want to continue booking! \t");
        scanf("%d", &userChoice);
    } while (userChoice !=0);

    if (totalUsers >=5) {
        totalCost = totalCost -  (totalCost * 0.05);
        printf("Your total ticket price would be: rupees %d for %d people!", totalCost, totalUsers);
    } else {
        printf("Your total cost will be: %d for %d people", totalCost, totalUsers);
    }

    return 0;
}