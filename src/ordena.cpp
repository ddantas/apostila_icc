/*  Este programa recebe como parametro um nome 
    de arquivo com um inteiro em cada linha.
    Le o arquivo, armazena os inteiros em um 
    vetor e os ordena, imprimindo o tempo 
    gasto na ordenacao.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXTAM 1000000

#define swap(arr, a, b)        \
{                              \
    int __swap_buf__ = arr[a]; \
    arr[a] = arr[b];           \
    arr[b] = __swap_buf__;     \
}

int readArrayFromFile(char* filename, int* arr, int* size)
{
    FILE* fp = fopen(filename, "r");
 
    if (fp == 0)
    {
      return 1;
    }

    int result;
    int i = 0;
    do
    {
        result = fscanf(fp, "%d", &arr[i]);    
        i++;
    }
    while (result == 1);
    *size = i - 1;

    return 0;
}

void printArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("arr[%7d] = %7d\n", i, arr[i]); 
    }
}

void bubbleSort(int* arr, int size)
{
    for (int maxi = size - 2; maxi >= 1; maxi--)
    {
        for (int i = 0; i <= maxi; i++)
        {
            if (arr[i] > arr[i+1])
            {
                swap(arr, i, i+1);
            }
        }
    }
}

double timer(int start)
{
    static timespec t0;
    static timespec t1;

    if (start)
    {
        clock_gettime(CLOCK_REALTIME, &t0);
        printf("t0 sec  = %ld\n", t0.tv_sec);
        printf("t0 nsec = %ld\n", t0.tv_nsec);
        return 0.0;
    }
    else
    {
        clock_gettime(CLOCK_REALTIME, &t1);
        printf("t1 sec  = %ld\n", t1.tv_sec);
        printf("t1 nsec = %ld\n", t1.tv_nsec);

        double delta =   (t1.tv_sec - t0.tv_sec) + 
                       ( (t1.tv_nsec - t0.tv_nsec) / 1000000000.0 );

        return delta;
    }

}

void timerStart(void)
{
    timer(1);
}

double timerEnd(void)
{
  return timer(0); 
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        exit(1);
    }

    int arr[MAXTAM];

    int size;
    int error = readArrayFromFile(argv[1], arr, &size);

    if (error)
    {
      exit(1);
    }

    printf("size = %d\n", size);
    //printArray(arr, size);

    printf("CLOCKS_PER_SEC = %ld\n", CLOCKS_PER_SEC);

    timerStart();
    bubbleSort(arr, size);
    double delta = timerEnd();

    printf("delta = %f sec\n", delta);
    //printArray(arr, size);
}



