#include <stdio.h>

int main () {
    int input;
    int numHours;
    int numMinutes;

    printf ("Input an integer value: ");
    scanf ("%d", &input);

    numHours = input / 60;
    numMinutes = input % 60;

    printf ("Number of hours: %d\n", numHours);
    printf ("Number of minutes: %d\n", numMinutes);

    return 0;
}