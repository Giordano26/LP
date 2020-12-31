//Stefano Giordano - Turma B
/*
Implementar um programa em C com alocação dinâmica de memória
Solicitar uma quantidade de numeros inteiros a serem digitados
Permitir a digitação de todos esses numeros inteiros.
Eles devem ser armazenados em memoria alocada

Apresentar todos esses numeros horizontalmente (usar tabulação)
Processar uma função que dobra todos esses valores utilizando seus
respectivos ponteiros.
Reapresentar todos esses numeros alterados.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int nComponentes,*listaDinamica;
int aux2;

// Função para dobrar o valor
int dobra(int *lista){
    printf("Numeros dobrados:\n");
    
    for (int i = 0; i <= nComponentes - 1; i++){ //Loop para dobrar cada valor do array
        *(lista + i) = *(lista + i) * 2; //operação de duplicação com ponteiro
        printf("%d\t", *(lista + i)); //imprime de maneira tabulada a lista 
    }
}

int main(void){
    printf("Digite o numero de componentes: ");
    scanf("%d", &nComponentes);

    listaDinamica = (int *)malloc(nComponentes * sizeof(int)); //Aloca na memória

    for (int i = 0; i <= nComponentes - 1; i++){//loop para preencher o array
        printf("Digite um numero: ");
        scanf("%d", &aux2);
        listaDinamica[i] = aux2; //Guarda na memoria
    }

    printf("Numeros originais: \n"); // Printa na tela de forma tabulada componentes da lista original
    for (int i = 0; i <= nComponentes - 1; i++){
        printf("%d\t", listaDinamica[i]);
    }

    printf("\n\n"); 
    dobra(listaDinamica); //função de dobrar numeros é chamada
                         //Lista original tem seus valores dobrados e mostrados em  tabela
}