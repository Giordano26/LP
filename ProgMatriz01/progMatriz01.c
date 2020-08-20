//ProgMatriz01
//Stefano Giordano - 19/08/2020
//Teste com Matriz unidimensional
//Os 40 primeiros elementos da serie de fibonacci

#include <stdio.h>
int main(){
    int mat[40];
    int cont, a = 0, b = 1,c;
    //carrega a matriz

    mat[0] = a;
    mat[1] = b;
    cont = 2;

    while (cont < 40)
    {
        c = a + b;
        mat[cont] = c;
        cont++;
        a = b;
        b = c;
    }

    //apresenta a matriz

    printf("\nSérie de Fibonacci\n");
    for(int i = 0; i<40;i++){
        printf("%d.\t%d\n", i+1,mat[i]);
    }
        printf("\n");

    return 0;
}