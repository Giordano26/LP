//Prog 6 - cabeçalho, f de 0 a 1000 de 10 em 10, inverter colunas da tabela, adicionado kelvin
//Stefano Giordano - 05/08/2020

#include <iostream>

int main(){
    float fahr, celsius, kelvin;
    int inicio, fim, incr;
    inicio = 0; fim = 1000; incr = 10;
    fahr = inicio;
    printf("=========================================\n");
    printf("Celsius        Fahrenheint       Kelvin\n");
    printf("=========================================\n");
    while(fahr <= fim){
        celsius = 5*(fahr-32)/9;
        kelvin = celsius + 273.15;
        printf("%f\t%f\t%f\n",celsius,fahr,kelvin);
        fahr += incr;
}
}