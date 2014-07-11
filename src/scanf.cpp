
#include <stdio.h>
#include <cstdlib>

#define TAM_MAX 10

int main()
{   
    float       f0 = 1000000000;
         double d0 = 1000000000;
    
    printf("float = %f\n", f0);
    printf("doubl = %f\n", d0);
    printf("doubl = %Lf\n", d0);
    printf("doubl = %g\n", d0);
    printf("doubl = %G\n", d0);
    
    system("pause");
    return 0;
    
    int result;
    char c;
    result = scanf("%c", &c);
    printf("result = %d, c = %c\n", result, c);

    int i;
    result = scanf("%d", &i);
    printf("result = %d, i = %d\n", result, i);

    long int li;
    result = scanf("%ld", &li);
    printf("result = %d, li = %ld\n", result, li);

    long long int lli;
    result = scanf("%Ld", &lli);
    printf("result = %d, lli = %Ld\n", result, lli);


    system("pause");
    
    return 0;    
    printf("sizeof float = %d\n", sizeof(float)); 
    printf("sizeof double = %d\n", sizeof(double)); 
    printf("sizeof long double = %d\n", sizeof(long double)); 
    printf("sizeof int = %d\n", sizeof(int)); 
    printf("sizeof long int = %d\n", sizeof(long int)); 
    printf("sizeof long long int = %d\n", sizeof(long long int)); 
    long double f[TAM_MAX];
    int tamanho = 0;
    for (int i = 0; i < TAM_MAX; i++)
    {
        printf("Digite f[%d]: ", i);
        int result = scanf("%Lf", &f[i]);
        if (result != 1)
        {
            break;
        }
        tamanho ++;
        printf("result = %d, f[%d] = %f\n", result, i, f[i]);
    }
    printf("tamanho = %d\n", tamanho);
    
    system("pause");
}
