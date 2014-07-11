/* Programa que lanca um dado com tantos lados quanto 
   definidos em LADOS e imprime o valor sorteado. 
   Cada sorteio resulta em um valor maior 
   ou igual a 1 e menor ou igual a LADOS. 
   O numero de sorteios eh definido em SORTEIOS. 
   O programa conta quantas vezes cada 
   lado foi sorteado e imprime a contagem no final.
*/



#include <stdio.h>  // printf, getchar
#include <stdlib.h> // rand, srand
#include <time.h>   // time

#define LADOS 6
#define SORTEIOS 10000

int main(void)
{

    srand(time(NULL));
    int count[LADOS + 1];
 
    for (int i = 0; i <= LADOS; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < SORTEIOS; i++)
    {
        int result = rand() % LADOS + 1;
        printf("valor = %d\n", result % LADOS + 1);
        //getchar();
        count[result]++;
    }

    for (int i = 0; i <= LADOS; i++)
    {
        printf("count[%d] = %d\n", i, count[i]);
    }
}
