//progEstrutura02
//Eli Banks - 19/08/2020
//Matriz de estrutura
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
	} aluno1, aluno2, aluno3;  //estas tambem são declarações de variáveis (exemplos não usados)
	int i;
	char a;
	
	//declaração de matriz de estrutura
	struct pessoa MatAlunos[30];   //gera 30 conjuntos de variáveis conforme a estrutura
	
	for (i=1; i <= 3 ; i++)
	{
		printf("\nDigite os dados do Aluno %d\n",i);
		printf("nome: ");
		gets(MatAlunos[i].nome);
		printf("endereço: ");
		gets(MatAlunos[i].ender);
		printf("municipio: ");
		gets(MatAlunos[i].munic);
		printf("Estado: ");
		gets(MatAlunos[i].UF);
		printf("idade: ");
		scanf("%d%c",&MatAlunos[i].idade, &a); //&a é um caracter auxiliar (ISTO É UM ARTIFÍCIO)
//		scanf("%c",&a);   //outra opção
    }

	
	//apresentação dos alunos
	printf("\nApresentação dos alunos\n");

    for (i=1; i <= 3 ; i++)
	{
        printf("\nAluno %d\n",i);	
		printf("%s  (%d anos)\n",MatAlunos[i].nome, MatAlunos[i].idade);
		printf("%s - %s-%s\n", MatAlunos[i].ender, MatAlunos[i].munic, MatAlunos[i].UF);
	}
			
}




