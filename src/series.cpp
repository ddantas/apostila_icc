/*  Este programa solicita ao usuario que digite um 
    numero inteiro. O numero eh lido e armazenado em 
    uma variavel. Em seguida o programa calcula seu 
    fatorial, seu namero de fibonacci e imprime o 
    resultado.
 */

#include <stdio.h>
#include <cstdlib>

int fibonacci(int val)
{
    if (val == 0)
    {
        return 0;
    }
    else if (val == 1)
    {
        return 1;
    }
    else
    {
      return fibonacci(val - 1) + fibonacci(val - 2);
    }
}

int fatorial(int val)
{
    if (val <= 1)
    {
        return 1;
    }
    else
    {
        return val * fatorial(val - 1);
    }
}

int main()
{   
    int val;
    printf("digite um inteiro:\n");

    int coderr = scanf("%d", &val);
    printf("coderr = %d, val = %d\n", coderr, val);

    int result;

    result = fatorial(val);
    printf("fatorial(%d) = %d\n", val, result);

    result = fibonacci(val);
    printf("fibonacci(%d) = %d\n", val, result);

    system("pause");
}
