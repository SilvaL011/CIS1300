#include <stdio.h>

int main(){
    int timeFormatChoice;
    int flightHour;
    int flightMinute;
    char dayPeriod;
    int convertedFlightHour;
    int totalTimeInMin;
    int flightDepartures[8] = {435, 495, 555, 615, 675, 915, 975, 1035};
    int smallestDiff;
    int closestFlight;

    printf("Would you like to enter the time in 12-hour format (enter 1) or 24-hour format(enter 2)? ");
    scanf("%d", &timeFormatChoice);

    if(timeFormatChoice == 1){
        printf("Enter time in 12 hour format\n");
        printf("Enter a value between 0 and 12 for hour: ");
        scanf("%d", &flightHour);
        printf("Enter a value between 0 and 60 for minutes: ");
        scanf("%d", &flightMinute);
        printf("Enter a for am or p for pm: ");
        scanf(" %c", &dayPeriod);

        printf("\n");
        printf("---------------------------\n");

        
        
        if(dayPeriod == 'p'){

            if(flightHour < 10 && flightMinute < 10){
                printf("You entered 0%d:0%d pm\n ", flightHour, flightMinute);
            } else if(flightHour < 10 && flightMinute >= 10){
                printf("You entered 0%d:%d pm\n", flightHour, flightMinute);
            } else if(flightHour >= 10 && flightMinute < 10){
                printf("You entered %d:0%d pm\n", flightHour, flightMinute);
            } else{
                printf("You entered %d:%d pm\n", flightHour, flightMinute);
            }

            switch (flightHour){
                case 1:
                    convertedFlightHour = 13;
                    break;
                case 2:
                    convertedFlightHour = 14;
                    break;
                case 3:
                    convertedFlightHour = 15;
                    break;
                case 4:
                    convertedFlightHour = 16;
                    break;
                case 5:
                    convertedFlightHour = 17;
                    break;
                case 6:
                    convertedFlightHour = 18;
                    break;
                case 7:
                    convertedFlightHour = 19;
                    break;
                case 8:
                    convertedFlightHour = 20;
                    break;
                case 9:
                    convertedFlightHour = 21;
                    break;
                case 10:
                    convertedFlightHour = 22;
                    break;
                case 11:
                    convertedFlightHour = 23;
                    break;
                case 12:
                    convertedFlightHour = 0;
                    break;
                default:
                    convertedFlightHour = flightHour;
                    break;
            }

            if(convertedFlightHour < 10 && flightMinute < 10){
                printf("In 24 hour format - you entered 0%d:0%d\n", convertedFlightHour, flightMinute);
            } else if(convertedFlightHour < 10 && flightMinute >= 10){
                printf("In 24 hour format - you entered 0%d:%d\n", convertedFlightHour, flightMinute);
            } else if(convertedFlightHour >= 10 && flightMinute < 10){
                printf("In 24 hour format - you entered %d:0%d\n", convertedFlightHour, flightMinute);
            } else{
                printf("In 24 hour format - you entered %d:%d\n", convertedFlightHour, flightMinute);
            }
    
        } else{
            if(flightHour < 10 && flightMinute < 10){
                printf("You entered 0%d:0%d am\n", flightHour, flightMinute);
            } else if(flightHour < 10 && flightMinute >= 10){
                printf("You entered 0%d:%d am\n", flightHour, flightMinute);
            } else if(flightHour >= 10 && flightMinute < 10){
                printf("You entered %d:0%d am\n", flightHour, flightMinute);
            } else{
                printf("You entered %d:%d am\n", flightHour, flightMinute);
            }

            if(flightHour < 10 && flightMinute < 10){
                printf("In 24 hour format - you entered 0%d:0%d\n", flightHour, flightMinute);
            } else if(flightHour < 10 && flightMinute >= 10){
                printf("In 24 hour format - you entered 0%d:%d\n", flightHour, flightMinute);
            } else if(flightHour >= 10 && flightMinute < 10){
                printf("In 24 hour format - you entered %d:0%d\n", flightHour, flightMinute);
            } else{
                printf("In 24 hour format - you entered %d:%d\n", flightHour, flightMinute);
            }
        }

        totalTimeInMin = convertedFlightHour * 60 + flightMinute;
    } else{
        printf("Enter time in 24 hour format\n");
        printf("Enter a value between 0 and 23 for hour: ");
        scanf("%d", &flightHour);
        printf("Enter a value between 0 and 60 for minutes: ");
        scanf("%d", &flightMinute);
        printf(" ---------------------------\n");


        if(flightHour < 10 && flightMinute < 10){
            printf("You entered 0%d:0%d\n", flightHour, flightMinute);
        } else if(flightHour < 10 && flightMinute >= 10){
            printf("You entered 0%d:%d\n", flightHour, flightMinute);
         } else if(flightHour >= 10 && flightMinute < 10){
            printf("You entered %d:0%d\n", flightHour, flightMinute);
        } else{
            printf("You entered %d:%d\n", flightHour, flightMinute);
        }

        switch (flightHour){
            case 13:
                convertedFlightHour = 1;
                break;
            case 14:
                convertedFlightHour = 2;
                break;
            case 15:
                convertedFlightHour = 3;
                break;
            case 16:
                convertedFlightHour = 4;
                break;
            case 17:
                convertedFlightHour = 5;
                break;
            case 18:
                convertedFlightHour = 6;
                break;
            case 19:
                convertedFlightHour = 7;
                break;
            case 20:
                convertedFlightHour = 8;
                break;
            case 21:
                convertedFlightHour = 9;
                break;
            case 22:
                convertedFlightHour = 10;
                break;
            case 23:
                convertedFlightHour = 11;
                break;
            case 00:
                convertedFlightHour = 12;
                break;
            default:
                convertedFlightHour = flightHour;
                break;
        }

        if(flightHour >= 12){ 
            if(flightHour < 10 && flightMinute < 10){
                printf("In 12 hour format - you entered 0%d:0%d pm\n ", flightHour, flightMinute);
            } else if(flightHour < 10 && flightMinute >= 10){
                printf("In 12 hour format - you entered 0%d:%d pm\n", flightHour, flightMinute);
            } else if(flightHour >= 10 && flightMinute < 10){
                printf("In 12 hour format - you entered %d:0%d pm\n", flightHour, flightMinute);
            } else{
                printf("In 12 hour format - you entered %d:%d pm\n", flightHour, flightMinute);
            }
        } else{ 
            if(flightHour < 10 && flightMinute < 10){
                printf("In 12 hour format - you entered 0%d:0%d am\n ", flightHour, flightMinute);
            } else if(flightHour < 10 && flightMinute >= 10){
                printf("In 12 hour format - you entered 0%d:%d am\n", flightHour, flightMinute);
            } else if(flightHour >= 10 && flightMinute < 10){
                printf("In 12 hour format - you entered %d:0%d am\n", flightHour, flightMinute);
            } else{
                printf("In 12 hour format - you entered %d:%d am\n", flightHour, flightMinute);
            }
        }
    }
    printf("---------------------------\n");

    totalTimeInMin = flightHour * 60 + flightMinute;

    closestFlight = flightDepartures[0];
    smallestDiff = totalTimeInMin - closestFlight;

    if(smallestDiff < 0){
        smallestDiff = -smallestDiff;
    }

    for(int i = 1; i < 8; i++){
        int difference = totalTimeInMin - flightDepartures[i];

        if(difference < 0){
            difference = -difference;
        }
        if(difference < smallestDiff){
            smallestDiff = difference;
            closestFlight = flightDepartures[i];
        }
    }

    switch(closestFlight){
        case 435:
            printf("Closest departure times is 7:15 a.m., arriving 8:25 a.m.");
            break;
        case 495:
            printf("Closest departure times is 8:15 a.m., arriving 9:25 a.m.");
            break;
        case 555:
            printf("Closest departure times is 9:15 a.m., arriving 10:25 a.m.");
            break;
        case 615:
            printf("Closest departure times is 10:15 a.m., arriving 11:25 a.m.");
            break;
        case 675:
            printf("Closest departure times is 11:15 a.m., arriving 12:25 a.m.");
            break;
        case 915:
            printf("Closest departure times is 03:15 p.m., arriving 4:25 a.m.");
            break;
        case 975:
            printf("Closest departure times is 04:15 p.m., arriving 5:25 a.m.");
            break;
        case 1035:
            printf("Closest departure times is 05:15 p.m., arriving 6:25 p.m.");
            break;
    }
}