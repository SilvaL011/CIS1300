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

void extractOctets(char ipAddress [], int *octet1Int, int *octet2Int, int *octet3Int, int *octet4Int);

void readIPAddress (char ipAddress []){
    char octet1[4];
    char octet2[4];
    char octet3[4];
    char octet4[4];
    int octet1Integer;
    int octet2Integer;
    int octet3Integer;
    int octet4Integer;

    //Requests user for input on each octet, uses do-while loop to check for miss input
    do{
        printf("Octet#1 - Enter a number - must be between 0 and 127: ");
        scanf("%s", octet1);
        sscanf(octet1, "%d", &octet1Integer);
    }while(octet1Integer < 0 || octet1Integer > 127);
    
    do{
        printf("Octet#2 - Enter a number - must be between 0 and 255: ");
        scanf("%s", octet2);
        sscanf(octet2, "%d", &octet2Integer);
    }while(octet2Integer < 0 || octet2Integer > 255);

    do{
        printf("Octet#3 - Enter a number - must be between 0 and 255: ");
        scanf("%s", octet3);
        sscanf(octet3, "%d", &octet3Integer);
    }while(octet3Integer < 0 || octet3Integer > 255);

    do{
        printf("Octet#4 - Enter a number - must be between 0 and 255: ");
        scanf("%s", octet4);
        sscanf(octet4, "%d", &octet4Integer);
    }while(octet4Integer < 0 || octet4Integer > 255);

    //copies an empty string to ipAddress, then concatenates each octet separating them by '.'
    strcpy(ipAddress, "");
    strcat(ipAddress, octet1);
    strcat(ipAddress, ".");
    strcat(ipAddress, octet2);
    strcat(ipAddress, ".");
    strcat(ipAddress, octet3);
    strcat(ipAddress, ".");
    strcat(ipAddress, octet4);
}

long int convertIPToLongNumber ( char ipAddress [], int lengthIPAddr, int *numDigits){
    int octet1Binary[8];
    int octet2Binary[8];
    int octet3Binary[8];
    int octet4Binary[8];
    int octet1Int;
    int octet2Int;
    int octet3Int;
    int octet4Int;
    int binaryAllOctets[32];
    long int decimalRepresentation = 0;
    long int digitCounter = 0;

    //calls the function extractOctets, which divides the ipAddress and returns each octet by call by reference
    //Then it calls the function convertToBinary which converts each octet to binary
    extractOctets(ipAddress, &octet1Int, &octet2Int, &octet3Int, &octet4Int);
    convertToBinary(octet1Int, octet1Binary);
    convertToBinary(octet2Int, octet2Binary);
    convertToBinary(octet3Int, octet3Binary);
    convertToBinary(octet4Int, octet4Binary);
    
    //initializes all indexes in binaryAllOctets to be zero
    for (int i = 0; i < 32; i++) {
        binaryAllOctets[i] = 0;
    }

    //calls combineAllOctets, which adds each binary representation of the octets to binaryAllOctets depending on their position 
    combineAllOctets (octet1Binary, 1, binaryAllOctets);
    combineAllOctets (octet2Binary, 2, binaryAllOctets);
    combineAllOctets (octet3Binary, 3, binaryAllOctets);
    combineAllOctets (octet4Binary, 4, binaryAllOctets);

    //calls convertBinaryToDecimal which converts binaryAllOctets to decimal and stores it in decimalRepresentation
    //This value is then also saved in digitCounter, so the cnages made later do not affect decimalRepresentation, which will be the returned value
    decimalRepresentation = convertBinaryToDecimal(binaryAllOctets);
    digitCounter = decimalRepresentation;

    //digitCounter is modified and in the process the number of digits in the decimal representation is counted
    while(digitCounter != 0){
        (*numDigits)++;
        digitCounter/= 10;
    }

    return decimalRepresentation;
}

void convertToBinary(int octet, int octetBinary[8]) {
    int remainder;
    int j = 7;

    //initializes all indexes in octetBinary to be zero
    for (int i = 0; i < 8; i++) {
        octetBinary[i] = 0;
    }

    //Converts octet to binary and saves the result in octetBinary. 
    //array is filled from end to beginning because of how binary conversion works
    do {
        remainder = octet % 2;
        octetBinary[j] = remainder;
        j--;
        octet = octet / 2;
    } while (octet != 0 && j >= 0);
}

void combineAllOctets(int octetBinary[8], int pos, int binaryAllOctets[32]){
    //Writes the octet, depending on the position, in binaryAllOctets
    if(pos == 1){
        for(int i = 0; i < 8; i++){
            binaryAllOctets[i] = octetBinary[i];
        }
    } else if(pos == 2){
        for(int i = 0; i < 8; i++){
            binaryAllOctets[i + 8] = octetBinary[i];
        }
    } else if(pos == 3){
        for(int i = 0; i < 8; i++){
            binaryAllOctets[i + 16] = octetBinary[i];
        }
    } else if(pos == 4){
        for(int i = 0; i < 8; i++){
            binaryAllOctets[i + 24] = octetBinary[i];
        }
    }
}

long int convertBinaryToDecimal (int binaryAllOctets [32]){
    long int decimalConversion = 0;

    //Uses the pow function to convert a binary number to decimal
    for(int i = 0; i < 32; i++){
        decimalConversion += binaryAllOctets[i] * pow(2, 31 - i);
    }
    
    return decimalConversion;
}

char classifyIPAddress (char ipAddress []){
    int octet1Int;
    int octet2Int;
    int octet3Int;
    int octet4Int;
    char class;

    //calls the function extractOctets, which divides the ipAddress and returns each octet by call by reference
    extractOctets(ipAddress, &octet1Int, &octet2Int, &octet3Int, &octet4Int);

    //Depending on the second octet(returned by extractOctets) appropriately classifies the IP address 
    if(octet2Int >= 0 && octet2Int <= 127){
        class = 'A';
    } else if(octet2Int >= 128 && octet2Int <= 191){
        class = 'B';
    } else if(octet2Int >= 192 && octet2Int <= 223){
        class = 'C';
    } else if(octet2Int >= 224 && octet2Int <= 239){
        class = 'D';
    } else if(octet2Int >= 240 && octet2Int <= 255){
        class = 'E';
    }

    return class;
}

void extractOctets(char ipAddress [], int *octet1Int, int *octet2Int, int *octet3Int, int *octet4Int){
    int lengthIPAddr = strlen(ipAddress);
    char modifiedStr[lengthIPAddr];
    char *token;
    char octet1[4];
    char octet2[4];
    char octet3[4];
    char octet4[4];

    //Tokenization approach inspired by GeeksForGeeks tutorial on strtok usage
    //URL: https://www.geeksforgeeks.org/strtok-strtok_r-functions-c-examples/
    //Copy the input IP address string into modifiedStr to avoid modifying the original string
    strcpy(modifiedStr, ipAddress);

    //Use strtok to tokenize modifiedStr based on the "." delimiter, extracting the first octet
    token = strtok(modifiedStr, ".");

    //Copy the first octet (up to 3 characters) from token into octet1 and add a null terminator
    strncpy(octet1, token, 3);
    octet1[3] = '\0';

    //Extract the second octet by continuing the tokenization from the previous position
    token = strtok(NULL, ".");
    strncpy(octet2, token, 3);
    octet2[3] = '\0';

    //Extract the third octet
    token = strtok(NULL, ".");
    strncpy(octet3, token, 3);
    octet3[3] = '\0';

    //Extract the fourth octet
    token = strtok(NULL, ".");
    strncpy(octet4, token, 3);
    octet4[3] = '\0';

    //Convert each octet string to an integer using sscanf
    //Each octet string (octet1 to octet4) is parsed as an integer and stored in corresponding integer pointers
    sscanf(octet1, "%d", &*octet1Int);
    sscanf(octet2, "%d", &*octet2Int);
    sscanf(octet3, "%d", &*octet3Int);
    sscanf(octet4, "%d", &*octet4Int);
}