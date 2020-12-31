// Stefano Giordano - Primeira Atividade com ponteiros
/*
    Implementar um programa em C que inverta uma cadeia de caracteres (string) 
    fornecida pelo usuário (exemplo: "bom dia", gerar: "aid mob"). 
    O programa deve ter um loop para digitar diversas frases, terminando com a 
    frase "fim". Após a digitação o programa deverá apresentar a frase 
    (cadeia de caracteres) fornecida de forma invertida, USAR PONTEIO 
    para acessar a cadeia de caracteres. 

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void flush_in(){ //função para limpar buffer 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}


int main(){

    char *fraseIn,*fraseFim, locale; //um ponteiro para o inicio da frase e um para o final, uma variavel para armazenar chars para troca
    char string[50]; // a propria frase
    char saida; //sentinela para saida do programa 
    int tamanho; // str len
    bool fim; //sentinela do loop


    do{

        printf("Digite a frase a ser invertida: \n");
        fgets(string,sizeof(string),stdin); 

        tamanho = strlen(string); // aramzena tamanho da string

        fraseIn = string; 
        fraseFim = string + tamanho - 1; //indicar o final da frase

        for(int i = 0; i < tamanho /2; i++){
        locale  = *fraseFim; //atribui o local ao final
        *fraseFim = *fraseIn; //inverte o começo com fim
        *fraseIn = locale; // agora o local armazena o inicio 

        fraseIn++;
        fraseFim--;
        }

        printf("%s\n", string); //imprime a string invertida 
        printf("Sair? (s/n)\n");
        scanf("%c",&saida); //pega a opção de saida ou não
        flush_in();
        if(toupper(saida) == 'S'){
            fim = true; //encerra o loop caso in == 's'
        }

    }while(!fim);

    
    
    return 0;
}