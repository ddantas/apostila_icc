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

int comparacoes = 0;
int trocas      = 0;

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

void copyArray(int* src, int* dst, int size)
{
    for (int i = 0; i < size; i++)
    {
        dst[i] = src[i]; 
    }
}

void bubbleSort(int* arr, int size)
{
    comparacoes = 0;
    trocas = 0;
    for (int maxi = size - 2; maxi >= 1; maxi--)
    {
        for (int i = 0; i <= maxi; i++)
        {
            comparacoes++;
            if (arr[i] > arr[i+1])
            {
                trocas++;
                swap(arr, i, i+1);
            }
        }
    }
}

void selectionSort(int* arr, int size)
{
    for (int maxi = size - 1; maxi >= 1; maxi--)
    {
        int imaxval = 0;
        for (int i = 1; i <= maxi; i++)
        {
            comparacoes++;
            if (arr[i] > arr[imaxval])
            {
                imaxval = i;
            }
        }
        comparacoes++;
        if (imaxval != maxi)
        {
            trocas++;
            swap(arr, maxi, imaxval);
        }
    }
}

void mergeSortMerge(int* arr, int i0, int j0, int i1)
{
    int size = i1 - i0 + 1;
    int* aux = (int*) malloc(size * sizeof (int));
    int i = i0;
    int j = j0;
    for (int k = 0; k < size; k++)
    {
        comparacoes += 3;
        if (  (i < j0) && ( (j > i1) || (arr[i] < arr[j]) )  )
	{
            aux[k] = arr[i];
            i++;
        }
        else
	{
            aux[k] = arr[j];
            j++;
	}

      /*
        if (j > i1)
	{
            aux[k] = arr[i];
            i++;
	}
        else if (i == j0){
            aux[k] = arr[j];
            j++;
	}
        else if(arr[i] < arr[j])
        {
            aux[k] = arr[i];
            i++;
	}
        else
        {
            aux[k] = arr[j];
            j++;
	}
      */
    }
    for (int k = 0; k < size; k++)
    {
        trocas++;
        arr[i0 + k] = aux[k];
    }
    free(aux);
}

void mergeSortRec(int* arr, int i0, int i1)
{
    comparacoes++;
    if(i0 < i1)
    {
        mergeSortRec(arr, i0, (i0+i1)/2);
        mergeSortRec(arr, (i0+i1)/2 + 1, i1);
        mergeSortMerge(arr, i0, (i0+i1)/2 + 1, i1);
    }
}

void mergeSort(int* arr, int size)
{
    comparacoes = 0;
    trocas = 0;
    mergeSortRec(arr, 0, size);
}

double timer(int start)
{
    static timespec t0;
    static timespec t1;

    if (start)
    {
        clock_gettime(CLOCK_REALTIME, &t0);
        //printf("t0 sec  = %ld\n", t0.tv_sec);
        //printf("t0 nsec = %ld\n", t0.tv_nsec);
        return 0.0;
    }
    else
    {
        clock_gettime(CLOCK_REALTIME, &t1);
        //printf("t1 sec  = %ld\n", t1.tv_sec);
        //printf("t1 nsec = %ld\n", t1.tv_nsec);

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

    int arr0[MAXTAM];
    int arr[MAXTAM];

    int size;
    int error = readArrayFromFile(argv[1], arr0, &size);

    if (error)
    {
      exit(1);
    }

    printf("size = %d\n", size);
    //printArray(arr, size);

    printf("CLOCKS_PER_SEC = %ld\n", CLOCKS_PER_SEC);

    double delta;

    copyArray(arr0, arr, size);
    timerStart();
    selectionSort(arr, size);
    delta = timerEnd();
    printf("Bubble sort:\n");
    printf("Comparacoes: %5d\n", comparacoes);
    printf("Trocas:      %5d\n", trocas);
    printf("Time:        %f sec\n", delta);

    copyArray(arr0, arr, size);
    timerStart();
    selectionSort(arr, size);
    delta = timerEnd();
    printf("Selection sort:\n");
    printf("Comparacoes: %5d\n", comparacoes);
    printf("Trocas:      %5d\n", trocas);
    printf("Time:        %f sec\n", delta);

    copyArray(arr0, arr, size);
    timerStart();
    mergeSort(arr, size);
    delta = timerEnd();
    printf("Merge sort:\n");
    printf("Comparacoes: %5d\n", comparacoes);
    printf("Trocas:      %5d\n", trocas);
    printf("Time:        %f sec\n", delta);

    //printArray(arr, size);
}



