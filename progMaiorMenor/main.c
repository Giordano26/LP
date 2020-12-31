//Stefano Giordano - Turma B

/* Implementar um programa em C que realiza uma alocação de memória dinâmica para armazenar um conjunto de valores inteiros. 
O tamanho do conjunto deverá ser fornecido pelo usuário. 
Após a alocação, o programa deverá armazerna valores aleatórios inteiros na área de memória previamente alocada. 
Esses valores amarzenados na área de memória deverão ser passados para uma função em C que retorna o maior e menor elementos (valores) do conjunto.  
Observe que a função deve retornar ao local da chamada os dois valores. Portanto, você precisará usar passagem de 
parâmetro por referência, já que as funções só podem retornar um único valor.
O resultado da função com o menor e maior valor deve ser exibido na saída padrão do programa. 
 */


#include <stdio.h>
#include <stdlib.h> //lib para random
#include <time.h> //lib para import do time

typedef struct {  //criação  do tipo usado para coletar dados do array

    int maior;
    int menor;

} tipo_numero;

tipo_numero maiorMenor(int *array, int k){

    tipo_numero numero;
    numero.maior = 0; //inicia-se o maior com o menor possivel para haver uma primeira troca
    numero.menor = 1; //aqui qualquer um vale

    for (int i = 0; i < k; i++){

        if(array[i] > numero.maior){ //se for maior que o primeiro valor passado, agora vira o novo maior
            numero.maior = array[i];
        }

        else if(array[i] < numero.menor){ //se for menor que o primeiro valor passado, agora vira o novo menor
            numero.menor = array[i];
        }
    }

    return numero;

}

int main()
{

    int *y;
    int k;

    printf("Tamanho do conjunto é de ?\n");
    scanf("%d", &k);

    srand(time(NULL)); //função de randomização baseada no tempo do computador 
    y = (int*) malloc(k*sizeof (int)); //alocação no ponteiro


    printf("\nNúmeros do conjunto são: \n");
    for(int i = 0; i < k; i++) {

        y[i] = rand()%k; //trava no tamanho listado do array, se forem dois apenas numeros até 2 poderão aparecer, evita possiveis erros...
        printf("%d ", y[i]);
    }

    tipo_numero resultado = maiorMenor(y, k); //chamada da função no array

    printf("\nMaior número é: %d\nMenor número é: %d\n ", resultado.maior, resultado.menor);

    return 0;

}