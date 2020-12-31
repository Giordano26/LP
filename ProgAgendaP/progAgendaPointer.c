//Stefano Giordano - Turma B
//Refatoração prog agenda utilizando passagem por referencia 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define N 100 // capacidade de contados na agenda

//def bool
#define TRUE 1
#define FALSE 0

typedef int booleano;

void flush_in();

typedef struct Endereco
{
    char logra[70];
    int numero;
    char cep[10];
    char estado[3];
} tipo_Endereco;

typedef struct Contato
{
    char nome[50];
    char telefone[30];
    char email[20];
    int idade;
    tipo_Endereco ende;
} tipo_Contato;

typedef struct Agenda
{
    tipo_Contato *contatos;
    int qtd;
} tipo_Agenda;

int cadastrarContatosAgenda(tipo_Agenda *ag);
void excluirContatoAgenda(tipo_Agenda *agenda);
void exibirAgenda(tipo_Agenda *agenda);
void localizarContatoAgenda(tipo_Agenda *agenda);

void main()
{

    tipo_Agenda agenda[1];
    booleano fim = FALSE;
    int n, qtdUser;
    char opcao;

    agenda[0].qtd = 0;

    printf("Digite o numero de usuarios para cadastro: \n");
    scanf("%d", &qtdUser);
    flush_in();

    agenda[0].contatos = (tipo_Contato *)malloc(qtdUser * sizeof(tipo_Contato));

    do
    {
        printf("Sistema de Gerenciamento de Contatos Pessoais (SGCP) PUC-SP\n");
        printf("(1) - Cadastrar Contato\n");
        printf("(2) - Exibir Agenda Contato\n");
        printf("(3) - Localizar Contato\n");
        printf("(4) - Excluir Contato\n");
        printf("(5) - Sair do Programa\n");
        printf("Selecione a opção Desejada: ");
        opcao = getchar();
        flush_in();
        switch (opcao)
        {
            case '1':
                n = cadastrarContatosAgenda(&agenda[0]);
                agenda[0].qtd = n;
                break;
            case '2':
                exibirAgenda(&agenda[0]);
                break;
            case '3':
                localizarContatoAgenda(&agenda[0]);
                break;
            case '4':
                excluirContatoAgenda(&agenda[0]);
                break;
            case '5':
                printf("Opção sair do programa\n");
                fim = TRUE;
                break;
        }
    } while (!fim);
}

int cadastrarContatosAgenda(tipo_Agenda *ag)
{

    booleano fim = FALSE;
    int i = (*ag).qtd;
    char op;

    printf("Cadastramento de contatos: \n");
    do
    {
        printf("Nome: ");
        fgets(ag->contatos[i].nome, 50, stdin); // -> = (*var).atributo
        printf("Telefone: ");
        fgets(ag->contatos[i].telefone, 30, stdin);
        printf("E-mail: ");
        fgets(ag->contatos[i].email, 20, stdin);
        printf("Idade: ");
        scanf("%d", &ag->contatos[i].idade);
        flush_in();
        printf("Logradouro: ");
        fgets(ag->contatos[i].ende.logra, 70, stdin);
        printf("Numero: ");
        scanf("%d", &ag->contatos[i].ende.numero);
        printf("CEP: ");
        fgets(ag->contatos[i].ende.cep, 10, stdin);
        flush_in();
        printf("Estado: ");
        fgets(ag->contatos[i].ende.estado, 2, stdin);
        flush_in();
        i++;
        printf("Deseja cadastra outro contato (S/N)? ");
        op = getchar();
        flush_in();
        if (toupper(op) == 'N')
            fim = TRUE;
    } while (!fim && i < N);

    return i;
}

void exibirAgenda(tipo_Agenda *agenda)
{

    int i;
    int qtd = (*agenda).qtd;

    if (qtd > 0)
    {
        for (i = 0; i < qtd; i++)
        {
            printf("Contato #%d\n", i + 1);
            printf("Nome: %s", agenda->contatos[i].nome);
            printf("Telefone: %s", agenda->contatos[i].telefone);
            printf("Email: %s", agenda->contatos[i].email);
            printf("Idade: %d\n", agenda->contatos[i].idade);
            printf("Logradouro: %s", agenda->contatos[i].ende.logra);
            printf("Numero: %d\n", agenda->contatos[i].ende.numero);
            printf("CEP: %s", agenda->contatos[i].ende.cep);
            printf("Estado: %s\n", agenda->contatos[i].ende.estado);
            printf("------------------------------------------------------------------\n");
        }
    }
    else
        printf("Agenda vazia!\n");
}

void localizarContatoAgenda(tipo_Agenda *agenda)
{

    int i;
    int qtd = (*agenda).qtd;
    booleano achou = FALSE;
    char email[20];

    if (qtd > 0)
    {
        printf("Entre com o e-mail do contato: ");
        fgets(email, 20, stdin);
        for (i = 0; i < qtd && !achou; i++)
            if (!strcmp(email, agenda->contatos[i].email))
                achou = TRUE;
    }

    if (achou)
    {
        i--;
        printf("Contato #%d\n", i + 1);
        printf("Nome: %s", agenda->contatos->nome);
        printf("Telefone: %s", agenda->contatos[i].telefone);
        printf("Email: %s", agenda->contatos[i].email);
        printf("Idade: %d\n", agenda->contatos[i].idade);
        printf("Logradouro: %s", agenda->contatos[i].ende.logra);
        printf("Numero: %d\n", agenda->contatos[i].ende.numero);
        printf("CEP: %s", agenda->contatos[i].ende.cep);
        printf("Estado: %s\n", agenda->contatos[i].ende.estado);
        printf("------------------------------------------------------------------\n");
    }
    else
        printf("Contato não localizado na agenda! \n");
}

void excluirContatoAgenda(tipo_Agenda *agenda)
{

    int i, pos;
    char op;
    int achou = FALSE;
    char email[20];
    int qtd = (*agenda).qtd;

    if (qtd > 0)
    {
        printf("Entre com o e-mail do contato: ");
        fgets(email, 20, stdin);
        for (i = 0; i < qtd && !achou; i++)
            if (!strcmp(email, agenda->contatos[i].email))
            {
                achou = TRUE;
                pos = i;
            }
    }

    if (achou)
    {
        printf("Deseja realmente excluir o contato %s  (S/N)?", agenda->contatos[pos].nome);
        scanf(" %c", &op);
        if (toupper(op) == 'S')
        {
            for (i = pos; i < agenda->qtd - 1; i++)
                agenda->contatos[i] = agenda->contatos[i + 1];
            agenda->qtd--;
        }
    }
}

// funcao auxiliar para limpeza do buffer do teclado
void flush_in()
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
    }
}