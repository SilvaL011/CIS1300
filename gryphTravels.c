#include <stdio.h>

int main(){
    int timeFormatChoice;
    int flightHour;
    int flightMinutes;
    char dayPeriod;

    printf("Would you like to input your time slot using 12 or 24 hour time format? (Type 1 for 12 hour/Type 2 for 24 hour)\n");
    scanf("%d", &timeFormatChoice);

    if(timeFormatChoice == 1){
        printf("What hour would be more appropriate for your flight?\n");
        scanf("%d", &flightHour);

        printf("What minute of the specified hour would be more appropriate for your flight?\n");
        scanf("%d", &flightMinutes);

        printf("%d:%d AM or PM?(Type 'p' for PM/Type 'a' for AM)\n", flightHour, flightMinutes);
        scanf(" %c", &dayPeriod);

        if(dayPeriod == 'a'){
            printf("The picked time for your flight was %d:%dAM.\n", flightHour, flightMinutes);
        } else{
            printf("The picked time for your flight was %d:%dPM.\n", flightHour, flightMinutes);
        }
    } else{
        printf("What hour would be more appropriate for your flight?\n");
        scanf("%d", &flightHour);

        printf("What minute of the specified hour would be more appropriate for your flight?\n");
        scanf("%d", &flightMinutes);

        printf("The picked time for your flight was %d:%d.\n", flightHour, flightMinutes);
    }
}