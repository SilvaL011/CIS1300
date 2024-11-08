/************************siqueiraSilvaLeandroA2.c**************
Student Name: Leandro Siqueira Silva     Email Id: lsiqueir
Due Date: November 8 2024        Course Name: CIS 1300
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
gcc -std=c99 -Wall siqueiraSilvaLeandroA2.c siqueiraSilvaLeandroA2Main.c -lm
Running: ./a.out
OR
gcc -std=c99 -Wall siqueiraSilvaLeandroA2.c siqueiraSilvaLeandroA2Main.c -o assn2 -lm
Running the Program: ./assn2
********************************************************/

#include "givenA2.h"
#include <math.h>

int main(){
    char ipAddress[16];
    int lengthIPAddress = 0;
    int numDigits = 0;
    long int decimalRep;
    char class;

    //Calls readIPAddress and prints the user input
    printf("Testing Task 1 in main\n");
    printf("\n");
    readIPAddress (ipAddress);
    printf("IP Addr: %s\n", ipAddress);
    printf("\n");
    printf("Task 1 ends\n");
    printf("\n");

    //stores the length of the ipAddress in lengthIPAddress
    lengthIPAddress = strlen(ipAddress);

    //calls convertIPToLongNumber and saves return to decimalRep, then prints it and the number Of digits(numDigits)
    printf("Testing task 2 in main\n");
    printf("\n");
    decimalRep = convertIPToLongNumber (ipAddress, lengthIPAddress, &numDigits);
    printf("ipDecimal = %ld\n", decimalRep);
    printf("Number of digits = %d\n", numDigits);
     printf("Task 2 ends\n");
    printf("\n");

    //calls classifyIPAddress and prints the returned class
    printf("Testing task 3 in main\n");
    printf("\n");
    printf("Class for %s = ", ipAddress);
    class = classifyIPAddress(ipAddress);
    printf("%c\n", class);
    printf("Task 3 ends\n");
    printf("\n");

    return 0;
}