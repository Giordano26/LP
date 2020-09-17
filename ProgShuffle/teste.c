#include <stdio.h>
#include <time.h>

int * shuffle(){
    static int randomMacaco[28];

    srand(time(NULL));


   for (int k = 0; k < 28; k++)
    {
        randomMacaco[k] = k;
    }

    for (int k = 0; k < 28; k++)
    {
        int temp = randomMacaco[k];
        int randomIndex = rand() % 27;
        randomMacaco[k] = randomMacaco[randomIndex];
        randomMacaco[randomIndex] = temp;
    }

    return randomMacaco;
}

int main() {

   int *p;
   int i;

   p = shuffle();
	
   for ( i = 0; i < 28; i++ ) {
      printf( "*(p + %d) : %d\n", i, *(p + i));
   }


    return 0;
}