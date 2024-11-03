//You will write a .c file, lastnameFirstnameA2.c containing the function implementations detailed below
#include <stdio.h>
#include <string.h>
#include "givenA2.h"

//write all funtions below, no need for main function, it is included in file "siqueiraSilvaLeandroA2Main.c"

void readIPAddress(char ipAddress []){
    int firstNumber;
    int secondNumber;
    int thirdNumber;
    int fourthNumber;
    
    do{
        printf("Octet#1 - Enter a number - must be  between 0 and 127: ");
        scanf("%d",&firstNumber);
    } while(firstNumber < 0 || firstNumber > 127);

    do{
        printf("Octet#1 - Enter a number - must be  between 0 and 255: ");
        scanf("%d",&secondNumber);
    } while(secondNumber < 0 || secondNumber > 255);

    do{
        printf("Octet#1 - Enter a number - must be  between 0 and 255: ");
        scanf("%d",&thirdNumber);
    } while(thirdNumber < 0 || thirdNumber > 255);

    do{
        printf("Octet#1 - Enter a number - must be  between 0 and 255: ");
        scanf("%d",&fourthNumber);
    } while(fourthNumber < 0 || fourthNumber > 255);
}

long int convertIPToLongNumber (char ipAddress [], int lengthIPAddr){
    char firstOctet[4] = "";
    char secondOctet[4] = "";
    char thirdOctet[4] = "";
    char fourthOctet[4] = "";
    int firstInt;
    int secondInt;
    int thirdInt;
    int fourthInt;
    int octetOneBinary[8];
    int octetTwoBinary[8];
    int octetThreeBinary[8];
    int octetFourBinary[8];
    int binaryAllOctets[32];

    char token = strtok(ipAddress, ".");
    if(token != NULL){
        strcpy(firstOctet, token);
    }

    token = strtok(NULL, ".");
    if(token != NULL){
        strcpy(secondOctet, token);
    }

    token = strtok(NULL, ".");
    if(token != NULL){
        strcpy(thirdOctet, token);
    }

    token = strtok(NULL, ".");
    if(token != NULL){
        strcpy(fourthOctet, token);
    }

    sscanf(firstOctet, "%d",&firstInt);
    sscanf(secondOctet, "%d",&secondInt);
    sscanf(thirdOctet, "%d",&thirdInt);
    sscanf(fourthOctet, "%d",&fourthInt);

    convertToBinary(firstInt, &octetOneBinary[8]);
    combineAllOctets(octetOneBinary[8], 1, &binaryAllOctets[32]);

    convertToBinary(secondInt, &octetTwoBinary[8]);
    combineAllOctets(octetTwoBinary[8], 2, &binaryAllOctets[32]);

    convertToBinary(thirdInt, &octetThreeBinary[8]);
    combineAllOctets(octetThreeBinary[8], 3, &binaryAllOctets[32]);

    convertToBinary(fourthInt, &octetFourBinary[8]);
    combineAllOctets(octetFourBinary[8], 4, &binaryAllOctets[32]);
}