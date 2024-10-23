#include <stdio.h>

int convertDecimalToBinary(int);

int main(){
    int decimalNumber;
    int binaryNumberLength;

    printf("Input a decimal number: ");
    scanf("%d", &decimalNumber);

    binaryNumberLength = convertDecimalToBinary(decimalNumber);

    printf("Length of binary number: %d \n", binaryNumberLength);

    return 0;
}

int convertDecimalToBinary(int num){
    int i;
    int remainder;
    printf("Converted Number: ");

    do{
        i++;
        remainder = num % 2;
        num = num / 2;
        printf("%d", remainder);
    } while(num != 0);

    printf("\n");
    return i;
}