/************************siqueiraSilvaLeandroA1.c**************
Student Name: Leandro Siqueira Silva    Email Id: lsiqueir
Due Date: 04/10/2024                    Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic
integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self
Test.
I assert that this work is my own. I have appropriately acknowledged any
and all material that I have used, whether directly quoted or
paraphrased. Furthermore, I certify that this assignment was prepared by
me specifically for this course.

Compiling the program:
    The program should be compiled using the following flags: -std=c99 -Wall

compiling:
    gcc siqueiraSilvaLeandroA1.c -std=c99 -Wall
                        OR
    gcc lastnameFirstnameA1.c -std=c99 -Wall -o assn1
Running the Program:
    Running: ./a.out
********************************************************/

#include <stdio.h>
#include <stdbool.h>

int main(){
    int timeFormatChoice;
    int flightHour;
    int flightMinute;
    char dayPeriod;
    int convertedFlightHour;
    int totalTimeInMin;
    int flightDepartures[8] = {435, 495, 555, 615, 675, 915, 975, 1035}; //Time of flights from table given were converted to total minutes
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

    //Prompts the user to select between 12 and 24 format and stores choice in the variable timeFormatChoice
    printf("Would you like to enter the time in 12-hour format (enter 1) or 24-hour format (enter 2)? ");
    scanf("%d", &timeFormatChoice);

    //If the user picks 1, run code for 12 hour format; if user picks 2, run code for 24 hour format
    if(timeFormatChoice == 1){
        //Asks user for time info of desired flight and stores the hour in flightHour, the minutes in flightMinute and period in dayPeriod
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

        //If user picks afternoon, run print statements formatted to p.m. times; if user picks morning, run print statements formatted to a.m. times
        if(dayPeriod == 'p'){
            //Prints the selected afternoon time in 12 hour format
            if(flightHour < 10 && flightMinute < 10){
                printf("You entered 0%d:0%d pm\n ", flightHour, flightMinute);
            } else if(flightHour < 10 && flightMinute >= 10){
                printf("You entered 0%d:%d pm\n", flightHour, flightMinute);
            } else if(flightHour >= 10 && flightMinute < 10){
                printf("You entered %d:0%d pm\n", flightHour, flightMinute);
            } else{
                printf("You entered %d:%d pm\n", flightHour, flightMinute);
            }

            //Converts the hour of the flight to 24 hour time
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
                    convertedFlightHour = 12;
                    break;
                default:
                    convertedFlightHour = flightHour;
                    break;
            }

            //prints the time entered in 24 hour format
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
            //Prints the selected morning time in 12 hour format
            if(flightHour < 10 && flightMinute < 10){
                printf("You entered 0%d:0%d am\n", flightHour, flightMinute);
            } else if(flightHour < 10 && flightMinute >= 10){
                printf("You entered 0%d:%d am\n", flightHour, flightMinute);
            } else if(flightHour >= 10 && flightMinute < 10){
                printf("You entered %d:0%d am\n", flightHour, flightMinute);
            } else{
                printf("You entered %d:%d am\n", flightHour, flightMinute);
            }

            //Prints the selected morning time in 24 hour format
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

        //Converts the time of flight from hours and minutes to only minutes
        totalTimeInMin = convertedFlightHour * 60 + flightMinute;
    } else{
        //Asks user for time info of desired flight and stores the hour in flightHour, the minutes in flightMinute
        printf("\n");
        printf("Enter time in 24 hour format\n");
        printf("\n");
        printf("Enter a value between 0 and 23 for hour: ");
        scanf("%d", &flightHour);
        printf("Enter a value between 0 and 60 for minutes: ");
        scanf("%d", &flightMinute);
        printf(" ---------------------------\n");

        //Prints the selected time in 24 hour format
        if(flightHour < 10 && flightMinute < 10){
            printf("You entered 0%d:0%d\n", flightHour, flightMinute);
        } else if(flightHour < 10 && flightMinute >= 10){
            printf("You entered 0%d:%d\n", flightHour, flightMinute);
         } else if(flightHour >= 10 && flightMinute < 10){
            printf("You entered %d:0%d\n", flightHour, flightMinute);
        } else{
            printf("You entered %d:%d\n", flightHour, flightMinute);
        }

        //Converts hour from 24 hour format to 12 hour format
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
                convertedFlightHour = 00;
                break;
            default:
                convertedFlightHour = flightHour;
                break;
        }

        //Prints the selected time in the correct formating, using pm and am when appropriate
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
        totalTimeInMin = flightHour * 60 + flightMinute;
    }
    printf("---------------------------\n");

    //initializes closestFlight to the first flight as default and initializes the samllestDiff variable, 
    //which will be used to compare what flight has the smallest difference to the hour given
    closestFlight = flightDepartures[0];
    smallestDiff = totalTimeInMin - closestFlight;

    //Gets the absolute value of the difference, in case it is negative
    if(smallestDiff < 0){
        smallestDiff = -smallestDiff;
    }

    //Cycles through the array with flight times and picks out the flight with the smallest time difference 
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

    //prints the time of the closest time in 12 hour format and sets the cost of the flight, 
    //price was given on table of assignment introduction
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

    //Asks if user needs a hotel in Montreal and stores decision in the variable hotelDecision
    printf("Would you like a hotel in Montreal - enter 0 for no; 1 for yes? ");
    scanf("%d", &hotelDecision);

    //if the user does need a hotel, gives out info about hotels and asks what hotel choice the user wishes to book
    //asks for how many days the user will stay in the hotel 
    if(hotelDecision == 1){
        printf("There are 3 hotels:\n");
        printf("1. Marriott: $248 per night\n");
        printf("2. Sheraton: $90 per night\n");
        printf("3. Double Tree: $128 per night\n");
        printf("\n");
        printf("Your choice?:");
        scanf("%d", &hotelChoice);
        printf("How many days in Montreal?");
        scanf("%d", &daysInMontreal);
        printf("\n");
        printf("Would you like a ride from airport to hotel? enter 0 for no; 1 for yes ");
        scanf("%d", &rideDecision);
    }

    //Assigns the price of the hotel according to user choice, as well as ride
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

    hotelCost = hotelNightPrice * daysInMontreal; //calculates the total cost of hotel stay by multiplying the days * price/night

    //Asks user for date of birth and store it in birthday
    printf("\n");
    printf("Now enter your day of birth to qualify for discount2: ");
    scanf("%d", &birthday);
    printf("\n");

    //Separates the two digits for birthday, then adds them up
    firstDigitOfBirthday = birthday / 10;
    secondDigitOfBirthday = birthday % 10;
    sumOfBirthdayDigits = firstDigitOfBirthday + secondDigitOfBirthday;

    //displays the total cost as well as the breakdown of the cost(Cost of flight, cost of hotel and cost ofride to hotel)
    printf("Your total cost comes to: \n");
    printf("\n");
    printf("Cost of closest departure flight: $ %d.00 \n", flightCost);
    printf("Cost of Hotel for %d days: $ %d.00 \n", daysInMontreal, hotelCost);
    printf("Cost of Ride: $ %d.00 \n", ridePrice);
    printf("\n");

    totalPriceBfrTax = ridePrice + flightCost + hotelCost; //calculates the total cost

    //displays the total cost
    printf("Total cost before tax: $ %d.00 \n", totalPriceBfrTax);
    printf("\n");
    
    //checks if discounts are applicable
    if(totalPriceBfrTax % 11 == 0){
        discount1 = true;
    }
    if(totalPriceBfrTax % sumOfBirthdayDigits == 0){
        discount2 = true;
    }

    //stores the total price before taxes to price with discounts so changes can be made 
    //on the price, without affecting the price without taxes
    priceWithDiscounts = totalPriceBfrTax;

    //if discounts are applicable, apply them to total cost
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

    //Displays the total cost with discounts applied
    printf("Total cost after discounts 1 and 2: $ %.2f\n", priceWithDiscounts); 
    printf("\n");

    //Applies taxes to total cost (13%)
    priceWithTaxes = priceWithDiscounts * 1.13; 

    //Displays total cost with taxes applied
    printf("Finally, your total cost after taxes: $ %.2f\n", priceWithTaxes);
    return 0;
}