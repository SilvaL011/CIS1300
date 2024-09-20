#include <stdio.h>

int main(){
    int amount;
    int bill100;
    int bill50;
    int bill20;
    int bill10;
    int bill5;
    int remaining;

    printf ("Enter an amount: ");
    scanf ("%d", &amount);

    bill100 = amount / 100;
    amount = amount % 100;

    bill50 = amount / 50;
    amount = amount % 50;

    bill20 = amount / 20;
    amount = amount % 20;

    bill10 = amount / 10;
    amount = amount % 10;

    bill5 = amount / 5;
    amount = amount % 5;

    remaining = amount;

    printf ("100 bills: %d\n", bill100);
    printf ("50 bills: %d\n", bill50);
    printf ("20 bills: %d\n", bill20);
    printf ("10 bills: %d\n", bill10);
    printf ("5 bills: %d\n", bill5);
    printf ("remaining left: %d\n", remaining);

    return 0;
}