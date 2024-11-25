/************************siqueiraSilvaLeandroA3.c**************
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
gcc -std=c99 -Wall siqueiraSilvaLeandroA3.c siqueiraSilvaLeandroA3Main.c.c
Running: ./a.out data.txt
OR
gcc -std=c99 -Wall siqueiraSilvaLeandroA3.c siqueiraSilvaLeandroA3Main.c -o assn3
Running the Program: ./assn3 data.txt
********************************************************/

#include "givenA3.h"
#include <stdlib.h>

// Task 1: Reads player data from file and populates arrays for player names, countries, and stats.
int readFromFile(char fName[30],
                 char playerNames[NUMBER_PLAYERS][MAX_LEN_PNAME],
                 char countryNames[NUMBER_PLAYERS][MAX_LEN_CNAME],
                 int data[NUMBER_PLAYERS][6]) {
    FILE *file = fopen(fName, "r");

    if(file == NULL){
       return -1;  // Return -1 if file cannot be opened
    } else{
       int n = 0;
       while(n < NUMBER_PLAYERS){
           char firstName[MAX_LEN_PNAME];
           char lastName[MAX_LEN_PNAME];
           
           // Read player data and store in respective arrays
           fscanf(file, "%s %s %s %d %d %d %d %d %d", firstName, lastName, countryNames[n], &data[n][0], &data[n][1], &data[n][2], &data[n][3], &data[n][4], &data[n][5]);
           // Concatenate first and last names into full name
           strcat(firstName, " ");
           strcat(firstName, lastName);
           strcpy(playerNames[n], firstName);  // Store full name in playerNames
           n++;
       }
       return 1;  // Return 1 on success
    }   
}

// Task 2: Counts and displays players from a specific country.
int howManyFromCountryX (char playerNames [NUMBER_PLAYERS][MAX_LEN_PNAME],
                         char countryNames [NUMBER_PLAYERS][MAX_LEN_CNAME],
                         int data [NUMBER_PLAYERS][6],
                         char whichCountry [MAX_LEN_CNAME]){
    int count = 0;  // Initialize player count

    for(int i = 0; i < NUMBER_PLAYERS; i++){
       // Compare country names and print player info if they match
       if(strcmp(countryNames[i], whichCountry) == 0){
           printf("%s, %s, (Rank %d)\n", playerNames[i], whichCountry, data[i][0]);
           count++;  // Increment count for each matching player
       }
    }
    return count;  // Return total count
}

// Task 3: Find youngest or oldest player based on age and return their age.
int oldOrYoung (int data [NUMBER_PLAYERS][6],
                int whichOne,
                int * howMany){
    int youngestAge = 999;  // Initialize youngestAge to high value
    int oldestAge = -1;     // Initialize oldestAge to low value
    (*howMany) = 0;         // Initialize howMany to 0

    if(whichOne == 2){  // Check for youngest player
       for(int i = 0; i < NUMBER_PLAYERS; i++){
           if(data[i][1] < youngestAge){
              youngestAge = data[i][1];  // Update youngestAge
           }
       }

       for(int i = 0; i < NUMBER_PLAYERS; i++){
              if(data[i][1] == youngestAge){
                  (*howMany)++;  // Count players of youngest age
              }
       }

       return youngestAge;  // Return youngest age
    } else{  // Check for oldest player
       for(int i = 0; i < NUMBER_PLAYERS; i++){
           if(data[i][1] > oldestAge){
              oldestAge = data[i][1];  // Update oldestAge
           }
       }

       for(int i = 0; i < NUMBER_PLAYERS; i++){
              if(data[i][1] == oldestAge){
                  (*howMany)++;  // Count players of oldest age
              }
       }

       return oldestAge;  // Return oldest age
    }
}

// Task 4: Calculate and return average number of aces for players ranked between lower and upper ranks.
float avgNumberAcesRanksXToY (int data [NUMBER_PLAYERS][6],
                              int lower,
                              int upper){
    float avgAces;
    int sumAces = 0;  // Initialize sum of aces
    float diff = (upper-lower) + 1;  // Calculate range of ranks

    for(int i = lower - 1; i <= upper - 1; i++){
       sumAces += data[i][3];  // Sum aces for players in the range
    }
    avgAces = sumAces / diff;  // Calculate average aces
    return avgAces;  // Return average
}

// Task 5: Print a vertical histogram of the number of matches played by each player.
void printVerticalHistogramMatches (int data [NUMBER_PLAYERS][6]){
    int minVal = data[0][2];  // Initialize min value for matches
    int dummy[NUMBER_PLAYERS];  // Temporary array to hold match data
    int maxHeight = 0;  // Initialize max height of histogram

    // Initialize dummy array with match data
    for(int i = 0; i < NUMBER_PLAYERS; i++){
       dummy[i] = data[i][2];
    }
    
    // Find minimum value in dummy array
    for(int i = 0; i < NUMBER_PLAYERS; i++){
       if(dummy[i] < minVal){
              minVal = dummy[i];
       }
    }

    // Normalize values by subtracting (minVal - 1)
    for(int i = 0; i < NUMBER_PLAYERS; i++){
       dummy[i] = dummy[i] - (minVal - 1);
    }

    // Find maximum height of histogram
    for(int i = 0; i < NUMBER_PLAYERS; i++){
       if(dummy[i] > maxHeight){
           maxHeight = dummy[i];
       }
    }

    // Print match data
    for(int i = 0; i < NUMBER_PLAYERS; i++){
       printf("%d  ", data[i][2]);
    }
    printf("\n");

    // Print the histogram vertically
    for(int i = maxHeight; i > 0; i--){
       for(int j = 0; j < NUMBER_PLAYERS; j++){
              if(dummy[j] >= i){
                  printf("*   ");
              } else{
                  printf("    ");
              }
       }
       printf("\n");
    }

    // Print player indices below the histogram
    for(int i = 1; i <= NUMBER_PLAYERS; i++){
       if(i < 10){
           printf("%d   ", i);  
       } else{
           printf("%d  ", i);
       }
    }
}

// Task 6: Define struct to store player information and statistics for sorting and ranking.
typedef struct {
    char playerName[MAX_LEN_PNAME];  // Player's full name
    char countryName[MAX_LEN_CNAME]; // Player's country name
    int statisticValue;              // Value of the selected statistic
    int rank;                        // Player's rank
} Player;

// Comparison function for sorting players by a specific statistic (used with qsort).
// Code inspired by Portfolio Courses on Youtube
//Found at https://www.youtube.com/watch?v=rHoOWG6Ihs4&t=455s
int comparePlayers(const void* xVoid, const void* yVoid){
    Player playerX = *(Player*)xVoid;
    Player playerY = *(Player*)yVoid;
    return playerY.statisticValue - playerX.statisticValue;  // Sort in descending order of statistic value
}

// Task 6: Rank and display top N players based on a selected statistic.
void rankTopN (char playerNames [NUMBER_PLAYERS][MAX_LEN_PNAME],
               char countryNames [NUMBER_PLAYERS][MAX_LEN_CNAME],
               int data [NUMBER_PLAYERS][6],
               int whichOne,
               int n){
    Player players[NUMBER_PLAYERS];  // Array to store players
    int statisticPicked;

    // Determine which statistic to rank players by
    if(whichOne == 1){
      printf("\nTop %d players ranked on Aces\n\n", n);
       statisticPicked = 3;  // Rank by aces
    } else if(whichOne == 2){
      printf("\nTop %d players ranked on Double faults\n\n", n);
       statisticPicked = 4;  // Rank by double faults
    } else{
      printf("\nTop %d players ranked on Matches played\n\n", n);
       statisticPicked = 5;  // Rank by matches played
    }

    // Populate players array with player details and selected statistic
    for(int i = 0; i < NUMBER_PLAYERS; i++){
       strcpy(players[i].playerName, playerNames[i]);
       strcpy(players[i].countryName, countryNames[i]);
       players[i].statisticValue = data[i][statisticPicked];
       players[i].rank = data[i][0];
    }

    // Sort players by statistic value in descending order
    // Code inspired by Portfolio Courses on Youtube
    //Found at https://www.youtube.com/watch?v=rHoOWG6Ihs4&t=455s
    qsort(players, NUMBER_PLAYERS, sizeof(Player), comparePlayers);

    // Print top N ranked players
    for(int i = 0; i < n; i++){
       printf("%s, %s, %d (Rank %d)\n", players[i].playerName, players[i].countryName, players[i].statisticValue, players[i].rank);
    }
}
