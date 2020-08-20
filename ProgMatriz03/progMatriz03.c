//ProgMatriz02
//Stefano Giordano - 19/08/2020
//Teste com Matriz char

#include <stdio.h>

int main(){
    char str[4] = "PUC"; //equivalente a char str[4] = {'P','U','C','\0'};
    char alo[] = "Alo alunos";
    char texto[200];
    int i, cont;

    printf("%s\n", str);
    printf("%s\n", alo);

    printf("Digite um texto: ");
    gets(texto);

    //a posição do caracter terminador ('\0')
    //determina o tamanho do texto porque a matriz começa com indice 0

    for(i = 0; texto[i] != '\0'; i++);
     printf("O texto digitado possui %d caracteres\n",i);

    cont = 0;
    for(i = 0; texto[i] != '\0'; i++){
        if(toupper(texto[i]) == 'A');
        cont++;
    }
    printf("O texto possui %d letras A\n",cont);


    for(i = 0 ; texto[i] != '\0'; i++){
        printf("%c",texto[i]);
    }
    printf("\n");
    


    return 0;
}