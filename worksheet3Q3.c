/* Write a C program that assigns bonus air miles to customers using the following rules: 
bonus air miles is 100 if traveled miles exceeds 5000 in a period of time; it is 60 if traveled 
miles only exceeds 3000; and 10 otherwise. Hint: Use a multi-way if-else*/


#include <stdio.h>

int main(){

    int bonus;
    int traveledMiles;

    printf("Enter travelled Miles: ");
    scanf("%d", &traveledMiles);

    if(traveledMiles > 5000){
        bonus = 100;
    } else if(traveledMiles > 3000){
        bonus = 60;
    } else{
        bonus = 10;
    }

    printf("Bonus= %d\n", bonus);
    return 0;
}