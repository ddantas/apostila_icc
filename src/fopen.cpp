
#include <stdio.h>
#include <cstdlib>

#define TAM_MAX 10

int main()
{   
    float arr[TAM_MAX];
    FILE* fp;
    fp = fopen("nums.txta", "r");

    printf("fp = %p\n", fp);
    
    int tam = 0;
    for (int i=0; i < TAM_MAX; i++)
    {
        int result = fscanf(fp, "%f", &arr[i]);
        printf("result[i] = %d\n", result);
        if (!result)
	{
            break;
	}
        tam++;
    }

    printf("tamanho = %d\n", tam);
    for (int i=0; i < tam; i++)
    {
      printf("arr[%d] = %f\n", i, arr[i]);
    }
    
    system("pause");
}
