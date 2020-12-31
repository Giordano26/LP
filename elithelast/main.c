//Stefano Giordano - TURMA B
/*
Implementar um programa em C que utiliza alocação dinâmica de memória e vetor de ponteiros. Uma estrutura (struct) deverá ser definida contendo as notas das provas (vetor de float tamanho 5) e o nome de um aluno. O programa deverá permitir ao usuário cadastrar e exibir as informações do aluno (nome e notas). Um menu simples deverá ser implementado com as seguintes opções:

 1.Incluir

 2.Mostrar

 3. Calcular Média das Notas

 4. Sair

A cada inclusão dos dados de um aluno, o programa deverá alocar dinamicamente uma área de memória do tamanho da estrutura específica para esse aluno. Portanto, essa área será usada para guardar todas as informações do aluno fornecidas pelo usuário. O vetor de ponteiros deverá guardar a referência (endereço) a cada uma das áreas de memória alocadas dinamicamente sob demanda (controlar a inclusão de informações do aluno dentro da opção 1).  A opção 2 mostra as informações dos alunos cadastrados. A opção 3 calcula a média das notas e mostra na tela o resultado.  

Antes de finalizar o programa, opção 4, todas as áreas que foram alocadas dinamicamente deverão ser liberadas.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int contador = 0;
int op;
float notaB;
float auxNota;
char name[32];


// Struct do aluno
typedef struct aluno {
    float nota[5];
    char nome[32];
} tipo_aluno;



tipo_aluno *listaDinamica; //lista auxiliar
tipo_aluno *alunos[100]; //lista de alunos



int main(void)
{
    while(1){
        printf("\n1.Incluir\n2.Mostrar\n3.Calcular Média das Notas\n4.Sair\n");
        scanf("%d", &op);
        
        switch(op){
            case 1:{
                
                tipo_aluno auxAl; //cria um auxiliar pro tipo aluno
                
               
                listaDinamica = (tipo_aluno *)malloc(sizeof(struct aluno));  //Aloca o espaço correto para a lista

                
                printf("Digite o nome do aluno: ");
                scanf("%s", name); 
                fflush(stdin); // Limpa o buffer do teclado, usado por causa do scanf
                
                
                sprintf(auxAl.nome, "%s", name); //guarda a string do aluno no auxiliar  
                
                
                for(int i = 0; i < 5; i++){
                    printf("Digite a %dº nota do aluno: ", i + 1); //aloca cada nota no array de notas //.nota
                    scanf("%f", &notaB);
                    auxAl.nota[i] = notaB;
                }
                
                
                *listaDinamica = auxAl; //aloca o valor do auxiliar na memoria previamente alocada
                
                
                alunos[contador] = listaDinamica;  //adiciona esse ponteiro na lista de alunos
                
                 
                contador = contador + 1; //incremento no contador de alunos
                
                break;
            }
            case 2:{
                 printf("\n ===ALUNOS===\n");

                
                for (int i = 0; i < contador; i++){ //utiliza do contador pra mostrar cada aluno e printar suas notas e nome
                    printf("Nome do aluno: %s\n", alunos[i]->nome);
                    for (int notas = 0; notas < 5; notas++){
                        printf("Nota %d -> %.2f \n",notas + 1, alunos[i]->nota[notas]);
                    }
                    printf(" ---------------------------------- \n");
                }
                break;
            }
            case 3:{
                printf("\n ===MÉDIAS===\n");
                
                for (int i = 0; i < contador; i++){//utiliza do contador pra mostrar a média de cada aluno 
                    printf("Nome do aluno: %s\n", alunos[i]->nome);
                    
                    for (int notas = 0; notas < 5; notas++){
                        auxNota += alunos[i]->nota[notas]; //guarda suas notas no auxiliar pra fazer o calculo de media depois
                    }
                    auxNota = auxNota / 5;
                    printf("Média = %.2f \n", auxNota);
                    auxNota = 0;
                    printf("\n ---------------------------------- \n");
                }
                break;
            }
            case 4: {
                
                free(listaDinamica); // Libera o espaço da lista.
                exit(0);
            }
        }
    }
}