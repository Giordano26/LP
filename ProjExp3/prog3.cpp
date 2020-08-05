//Prog 03
//Stefano Giordano - 05/08/2020

#include <iostream>

int main()
{
    float fahrenheit;
    printf("Temperatura Fahrenheit: ");
    scanf("%f",&fahrenheit);
    printf("%f graus fahrenheit equivalem a %f graus Celcius", fahrenheit, (5*(fahrenheit - 32)/9));

    return 0;
}