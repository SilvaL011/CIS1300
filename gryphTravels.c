#include <stdio.h>
#include <stdbool.h>

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
    int hotelDecision;
    int hotelChoice;
    int rideDecision;
    int birthday;
    bool discount1 = false;
    bool discount2 = false;
    int hotelCost = 0;
    int flightCost;
    int daysInMontreal = 0;
    int hotelNightPrice;
    int ridePrice = 0;
    int totalPriceBfrTax;
    int firstDigitOfBirthday;
    int secondDigitOfBirthday;
    int sumOfBirthdayDigits;
    float priceWithDiscounts;
    float priceWithTaxes;

    printf("Would you like to enter the time in 12-hour format (enter 1) or 24-hour format(enter 2)? ");
    
    scanf("%d", &timeFormatChoice);

    if(timeFormatChoice == 1){
        printf("\n");
        printf("Enter time in 12 hour format\n");
        printf("\n");
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
        printf("\n");
        printf("Enter time in 24 hour format\n");
        printf("\n");
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
            printf("Closest departure times is 7:15 a.m., arriving 8:25 a.m.\n");
            flightCost = 231;
            break;
        case 495:
            printf("Closest departure times is 8:15 a.m., arriving 9:25 a.m.\n");
            flightCost = 226;
            break;
        case 555:
            printf("Closest departure times is 9:15 a.m., arriving 10:25 a.m.\n");
            flightCost = 226;
            break;
        case 615:
            printf("Closest departure times is 10:15 a.m., arriving 11:25 a.m.\n");
            flightCost = 283;
            break;
        case 675:
            printf("Closest departure times is 11:15 a.m., arriving 12:25 p.m.\n");
            flightCost = 283;
            break;
        case 915:
            printf("Closest departure times is 03:15 p.m., arriving 4:25 p.m.\n");
            flightCost = 226;
            break;
        case 975:
            printf("Closest departure times is 04:15 p.m., arriving 5:25 p.m.\n");
            flightCost = 226;
            break;
        case 1035:
            printf("Closest departure times is 05:15 p.m., arriving 6:25 p.m.\n");
            flightCost = 401;
            break;
    }
    printf("\n");

    printf("Would you like a hotel in Montreal - enter 0 for no; 1 for yes? ");
    scanf("%d", &hotelDecision);

    if(hotelDecision == 1){
        printf("There are 3 hotels:\n");
        printf("1. Marriott: $248 per night\n");
        printf("2. Sheraton: $90 per night\n");
        printf("3. Double Tree: $128 per night\n");
        printf("\n");
        printf("Your choice?: ");
        scanf("%d", &hotelChoice);
        printf("How many days in Montreal?");
        scanf("%d", &daysInMontreal);
        printf("Would you like a ride from airport to hotel? enter 0 for no; 1 for yes ");
        scanf("%d", &rideDecision);
    }

    switch(hotelChoice){
        case 1:
            hotelNightPrice = 248;
            ridePrice = 0;
            break;
        case 2:
            hotelNightPrice = 90;
            ridePrice = 25;
            break;
        case 3:
            hotelNightPrice = 128;
            ridePrice = 20;
            break;
    }

    hotelCost = hotelNightPrice * daysInMontreal;

    printf("\n");
    printf("Now enter your day of birth to qualify for discount2: ");
    scanf("%d", &birthday);
    printf("\n");

    firstDigitOfBirthday = birthday / 10;
    secondDigitOfBirthday = birthday % 10;
    sumOfBirthdayDigits = firstDigitOfBirthday + secondDigitOfBirthday;

    printf("Your total cost comes to: \n");
    printf("\n");
    printf("Cost of closest departure flight: $ %d.00 \n", flightCost);
    printf("Cost of Hotel for %d days: $ %d.00 \n", daysInMontreal, hotelCost);
    printf("Cost of Ride: $ %d.00 \n", ridePrice);
    printf("\n");

    totalPriceBfrTax = ridePrice + flightCost + hotelCost;

    printf("Total cost before tax: $ %d.00 \n", totalPriceBfrTax);
    printf("\n");
    
    if(totalPriceBfrTax % 11 == 0){
        discount1 = true;
    }
    if(totalPriceBfrTax % sumOfBirthdayDigits == 0){
        discount2 = true;
    }

    priceWithDiscounts = totalPriceBfrTax;

    if(discount1 == true){
        printf("You get a 5%% discount because the total cost was a multiple of 11 :)\n");
        priceWithDiscounts = priceWithDiscounts * 0.95;
    } else{
        printf("Sorry - you missed out on 5%% discount because the total cost was not a multiple of 11\n");
    }
    if(discount2 == true){
        printf("You get an additional 5%% discount because the total cost after discount1 was a multiple of the sum of digits in your date of birth :)\n");
        priceWithDiscounts = priceWithDiscounts * 0.95;
    } else{
        printf("Sorry - you missed out on the additional 5%% discount because the total after discount1 was not a multiple of the sum of digits in your day of birth\n");
    }
    printf("\n");

    printf("Total cost after discounts 1 and 2: $ %.2f\n", priceWithDiscounts);
    printf("\n");

    priceWithTaxes = priceWithDiscounts * 1.13;

    printf("Finally, your total cost after taxes: $ %.2f\n", priceWithTaxes);
}