//progStruct03
//Stefano Giordano - 19/08/2020
//Passagem de estrutura inteira para função

#include <stdio.h>

//esta declaração de estrutura DEVE ser GLOBAL, isto é: fora da função main

	struct pessoa   //pessoa é apenas um tipo agregado, não é uma variável!
	{
		char nome[40];
		char ender[40];
		char munic[20];
		char UF[2];
		int idade;
	} aluno;   //aluno é uma variavel do tipo struc pessoa
	
void funcPrint(struct pessoa pes);  //protótipo da função (OBRIGATÓRIO neste caso)


int main()
{

	printf("Digite o nome do aluno: ");
	gets(aluno.nome);
	printf("Digite o endereço: ");
	gets(aluno.ender);
	printf("Digite o municipio: ");
	gets(aluno.munic);
	printf("Digite o Estado: ");
	gets(aluno.UF);
	printf("Digite a idade: ");
	scanf("%d",&aluno.idade);
	
	funcPrint(aluno);   //passagem de toda a estrutura para a função (por valor)
}


void funcPrint(struct pessoa pes)
   { 
    printf("\nDados apresentados pela função\n");
   	printf("%s  (%d anos)\n",pes.nome, pes.idade);
	printf("%s - %s-%s\n", pes.ender, pes.munic, pes.UF);
   }
