//ProgAgendaV1 - Controle de Agenda
//Stefano Giordano - 26/08/2020

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define N 100 //capacidade da Agenda

typedef struct address{
    char logra[70];
    int numero;
    char cep[20];
    char estado[2];
}type_address;

typedef struct contact{
    char nome[50];
    char telefone[30];
    char email[30];
    int idade;
    type_address ende; //Logradouro, cep, estado...
}type_contact;

typedef struct agenda{
    type_contact contacts [N];
    int qtd;
}type_agenda;


//Assinatura para o compilador
void flush_in();
type_agenda cadastrarContato(type_agenda ag);
//


int main(){

    type_agenda agenda;
    char op; //opção do menu

    agenda.qtd = 0;

    do{
        
        printf("\n\nGerenciamento de uma Agenda de contatos pessoais\n");
        printf("================================================\n");
        printf("1 - Cadastrar contato\n");
        printf("2 - Exibir contato\n");
        printf("3 - Localizar contato\n");
        printf("4 - Excluir contato\n");
        printf("5 - Sair \n");

        printf("Opção selecionada: \n");
        op = getchar();
        flush_in();

        switch(op){
            case '1':   printf("Opção Cadastrar Contato selecionada: \n");
                        agenda = cadastrarContato(agenda);
                        break;
            case '2':   printf("Opção Exibir Contato selecionada: \n");
                        break;
            case '3':   printf("Opção Localizar Contato selecionada: \n");
                        break;
            case '4':   printf("Opção Excluir Contato selecionada: \n");
                        break;
            case '5':   printf("Desligando...\n");
                        exit(0);
                        break;
            default:    printf("Opção inválida\n");
                        break;
            }

    }while(true);
}







void flush_in(){
    int ch;

    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){

    }
}

type_agenda cadastrarContato(type_agenda ag){
    char opcao;
    int i;
    bool end = false;

    i = ag.qtd;
    
    printf("========= CADASTRAMENTO DE CONTATOS =========\n");
    do{
        printf("Nome: ");
        fgets(ag.contacts[i].nome,50,stdin);
        printf("Telefone: ");
        fgets(ag.contacts[i].telefone,30,stdin);
        printf("E-email: ");
        fgets(ag.contacts[i].email,20,stdin);
        printf("Idade: ");
        scanf("%d",&ag.contacts[i].idade);
        flush_in();
        printf("Logradouro: ");
        fgets(ag.contacts[i].ende.logra,70,stdin);
        printf("Numero: ");
        scanf("%d",&ag.contacts[i].ende.numero);
        printf("CEP: ");
        flush_in();
        fgets(ag.contacts[i].ende.cep,10,stdin);
        printf("Estado: ");
        fgets(ag.contacts[i].ende.estado,10,stdin);
        i++;
        printf("Deseja Continuar Cadastrando (S/N)? ");
        opcao = getchar();
        flush_in();
        if(toupper(opcao) == 'N') end = true;


    }while(!end && i < N);

    return ag;
}