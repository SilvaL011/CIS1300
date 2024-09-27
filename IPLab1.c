#include <stdio.h>
#include <stdbool.h>

int main (){
    const float PI = 3.14159265
    float radius;
    float area;
    float circumference;

    printf("Input the desired radius of the circle: \n");
    scanf("%f", &radius);

    area = PI * radius * radius;
    circumferene = 2 * PI * radius;

    printf("The circumference of the circle with radius %f is %f \n", radius, circumference);
    printf("The area of the circle with radius %f is %f \n", radius, area);
    return 0;
}