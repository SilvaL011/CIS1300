//You will write a .c file, lastnameFirstnameA2.c containing the function implementations detailed below
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

    printf("IP Addr: %d.%d.%d.%d\n", firstNumber, secondNumber, thirdNumber, fourthNumber);
}