#include <stdio.h>

int main(void){
    int aNumber;

    printf("Enter a number\n");
    scanf("%d", &aNumber);

    switch(aNumber % 2 == 0){
        case 1:
            printf("%d is even", aNumber);
            break;
        case 0:
            printf("%d is odd", aNumber);
            break; 
    }
    return 0;
}