//Prog 04
//Stefano Giordano - 05/08/2020

#include <iostream>
int main(){
    int fahr;
    printf("\n Entre com a temperatura da água em graus Fahrenheit: ");
    scanf("%d",&fahr);
    if(5*(fahr-32)/9 <= 0) printf("\n Estado sólido\n");
    else if(5*(fahr-32)/9 <= 100) printf("\n Estado líquido\n");
    else printf("\n Estado gasoso\n");
}

