//Prog 6 - cabeçalho, fahrenheit de 0 a 1000 de 10 em 10, inverter colunas da tabela, adicionado kelvin
//Stefano Giordano - 05/08/2020

#include <iostream>

int main(){
    float fahr, celsius, kelvin; //inicialização das variaveis para as temperaturas 
    int inicio, fim, incr; //inicialização das variaveis de sentinela 
    inicio = 0; fim = 1000; incr = 10;
    fahr = inicio;
    printf("=========================================\n"); //cabeçalho
    printf("Celsius        Fahrenheint       Kelvin\n");
    printf("=========================================\n");
    while(fahr <= fim){
        celsius = 5*(fahr-32)/9; //formula fahrenheit p/ celsius
        kelvin = celsius + 273.15; //formula celsius para kelvin
        printf("%f\t%f\t%f\n",celsius,fahr,kelvin); //tabulação das temperaturas calculadas
        fahr += incr; //incremento do loop
}
}