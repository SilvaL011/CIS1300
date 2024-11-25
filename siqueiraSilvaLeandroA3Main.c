/************************siqueiraSilvaLeandroA3Main.c**************
Student Name: Leandro Siqueira Silva    Email Id: lsiqueir
Due Date: November 23 2024 Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity. 2) I
have completed the Computing with Integrity Tutorial on Moodle; and 3) I have
achieved at least 80% in the Computing with Integrity Self Test.

I assert that this work is my own. I have appropriately acknowledged any and
all material that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for
this course.

Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall
compiling:
gcc -std=c99 -Wall siqueiraSilvaLeandroA3.c siqueiraSilvaLeandroA3Main.c
Running: ./a.out data.txt
OR
gcc -std=c99 -Wall siqueiraSilvaLeandroA3.c siqueiraSilvaLeandroA3Main.c -o assn3
Running the Program: ./assn3 data.txt
********************************************************/

#include "givenA3.h"

int main (int argc, char * argv[]) {

   int data[NUMBER_PLAYERS][6];
   char countryNames [NUMBER_PLAYERS][MAX_LEN_CNAME];
   char playerNames [NUMBER_PLAYERS][MAX_LEN_PNAME];
   char countryChoice[MAX_LEN_CNAME];
   int sameCountryQ = 0;
   char oldOrYoungChoice[10];
   int howManyOldOrYoung;
   int age;
   int firstBound;
   int secondBound;
   int rankTopNChoice;
   int choice;
   int howMany;
   float avg;
   int oldOrYoungChoicePassingInt;
    
    // Reads data from the input file specified in the command-line argument 
    // and populates arrays with player data.
    readFromFile(argv[1], playerNames, countryNames, data);
   
    // Main program loop that displays a menu of options and processes user inputs
    do {
       // Display menu options for the user.
       printf ("\nHere is the menu - enter a number between 1 and 6 \n\n");
       printf ("1.   Given a country name, find the total number of players from that country \n");
       printf ("2.   Based on user's choice, find the age and count of the youngest or oldest player (s) \n");
       printf ("3.   Find the average number of aces among players ranked from x to y \n");
       printf ("4.   Print a vertical histogram of the number of matches played \n");
       printf ("5.   Rank the top N players based on the number of aces, double faults or Service Games Won \n");
       printf ("6.   Exit \n");

       // Get user's choice of action.
       printf ("Enter your choice: ");
       scanf ("%d", &choice);
        
       // Validate user input to ensure it's within the menu range.
       if (choice < 1 || choice > 6) {
           printf("Choice must be between 1 and 6.\n");
       }
       
       // Process user's choice and call the appropriate functions.
        switch (choice) {
            case 1:
                // Find the total number of players from a specified country.
                printf("Which country? ");
                scanf("%s", countryChoice);

                sameCountryQ = howManyFromCountryX(playerNames, countryNames, data, countryChoice);
                printf("\n");
                printf("%s has %d ranked players\n", countryChoice, sameCountryQ);
                break;
            case 2:
                // Determine and display the youngest or oldest player's age and count.
                printf("\nType old for oldest or young for youngest: ");
                scanf("%s", oldOrYoungChoice);

                while (strcmp(oldOrYoungChoice, "young") != 0 && strcmp(oldOrYoungChoice, "old")) {
                    printf("Invalid choice. Type old for oldest or young for youngest: ");
                    scanf("%s", oldOrYoungChoice);
                }
                if(strcmp(oldOrYoungChoice, "young") == 0){
                    oldOrYoungChoicePassingInt = 2;
                } else{
                    oldOrYoungChoicePassingInt = 1;
                }


                age = oldOrYoung(data, oldOrYoungChoicePassingInt, &howManyOldOrYoung);

                if (oldOrYoungChoicePassingInt == 2) {
                    printf("\nThere is %d player(s) who is the youngest, and their age is %d\n", howManyOldOrYoung, age);
                } else {
                    printf("\nThere is %d player(s) who is the oldest, and their age is %d\n", howManyOldOrYoung, age);
                }
                break;
            case 3:
                // Calculate and display the average number of aces for players ranked between specified bounds.
                do {
                    do {
                        printf("\nEnter an integer: ");
                        scanf("%d", &firstBound);
                    } while (firstBound <= 0 || firstBound > 30);

                    do {
                        printf("Enter another integer: ");
                        scanf("%d", &secondBound);
                    } while (secondBound <= 0 || secondBound > 30);
                } while (firstBound > secondBound);
                avg = avgNumberAcesRanksXToY(data, firstBound, secondBound);
                printf("\nAverage of aces for all players ranked %d to %d = %.2f\n", firstBound, secondBound, avg);
                break;
            case 4:
                // Display a vertical histogram of matches played by all players.
                printVerticalHistogramMatches(data);
                break;
            case 5:
                // Rank the top N players based on selected criteria and display their information.
                do {
                    printf("\nEnter 1 if you want to rank top N players based on number of aces, 2 for number of double faults, 3 for number of service games won: ");
                    scanf("%d", &rankTopNChoice);
                } while (rankTopNChoice != 1 && rankTopNChoice != 2 && rankTopNChoice != 3);
                printf("\nHow many players data do you want to see? ");
                scanf("%d", &howMany);
                rankTopN(playerNames, countryNames, data, rankTopNChoice, howMany);
                break;
            
            case 6:
                // Exit the program with a farewell message.
                printf("Goodbye\n");
                break;
        }
        
    } while (choice != 6);
    
   return 0;
}