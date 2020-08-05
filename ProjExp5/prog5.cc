#include <iostream>
int main(){
    float fahr, celsius;
    int inicio, fim , incr;
    inicio = 0; fim = 300; incr = 20;
    fahr = inicio;
    while(fahr <= fim){
        celsius = 5*(fahr-32)/9;
        printf("%f\t%f\n", fahr, celsius);
        fahr += incr;
    }
}