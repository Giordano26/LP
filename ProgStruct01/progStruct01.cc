//progEstrutura01
//Stefano Giordano - 19/08/2020
//Testes com estruturas


#include <stdio.h>
int main()
{
	struct pessoa   //pessoa é apenas um tipo agregado, não é uma variável!
	{
		char nome[40];
		char ender[40];
		char munic[20];
		char UF[2];
		int idade;
	};
	//declaração da variável aluno do tipo struct pessoa
	struct pessoa aluno;
	struct pessoa aluno2;
	
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
	
	//teste de atribuição de estrutura
	aluno2 = aluno;
	
	//apresentação do aluno2
	printf("\nDados transferidos para o aluno2\n");
	printf("Nome: %s\n",aluno2.nome);
	printf("Endereço: %s\n",aluno2.ender);
	printf("Municipio: %s\n",aluno2.munic);
	printf("UF: %s\n",aluno2.UF);
	printf("Idade: %d\n",aluno2.idade);


			
}