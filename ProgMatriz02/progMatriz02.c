//ProgMatriz02
//Stefano Giordano - 19/08/2020
//Teste com Matriz bidimensional
//Tabela de multiplicação

#include <stdio.h>

int main(){
    int matBi[30][12];
    int i,j;

    //carrega a matriz

    for(i = 0; i < 30;i++){
        for(j = 0; j < 12; j++){
            matBi[i][j] = (i+1) * (j+1);
        }
    }

    //apresenta a matriz
    printf("\nTabela de mutiplicação\n");

       for(i = 0; i < 30;i++){
        for(j = 0; j < 12; j++){
            printf("%d\t", matBi[i][j]);
        }
        printf("\n");
    }
    return 0;
}