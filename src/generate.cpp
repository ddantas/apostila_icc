/* Gera uma lista de numeros aleatorios entre 0 e MAXNUM 
   inclusive. Passar como parametro um inteiro igual a 
   quantitade de numeros a serem gerados.
   Para criar um arquivo com os numeros gerados, suceder
   a chamada ao programa com > e o nome do arquivo.
   Exemplo:
   generate 1000 > saida.txt
*/

#include <stdlib.h>
#include <stdio.h>

#define DEBUG  0
#define MAXNUM 100

int main (int argc, char** argv)
{

  if (DEBUG){
    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
      printf("argv[%d] = %s\n", i, argv[i]);
    }
  }

  if (argc < 2)
  {
    exit(1);
  }

  int size;
  int result = sscanf(argv[1], "%d", &size);

  if (result != 1)
  {
    exit(1);
  }

  for (int i = 0; i < size; i++)
  {
    int number = rand() % MAXNUM + 1;
    printf("%d\n", number);
  }
}
