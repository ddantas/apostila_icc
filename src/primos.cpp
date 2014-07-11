/*  Este programa solicita ao usuario que digite um 
    numero inteiro. O numero eh lido e armazenado em 
    uma variavel. Em seguida o programa calcula seus
    fatores primos e os imprime.
 */

#include <stdio.h>
#include <cstdlib>

int main()
{   
    int val;
    printf("digite um inteiro:\n");
    int result = scanf("%d", &val);
    printf("result = %d, val = %d\n", result, val);

    int quociente = val;
    for (int i = 2; i <= val; i++)
    {
        int resto;
        do
        {
            resto = quociente % i;
            //printf("resto = %d, quoc = %d, i = %d\n", resto, quociente, i);
            if (resto == 0)
            {
                printf("fator: %d\n", i);
                quociente = quociente / i;
            }
        }
        while (resto == 0);
    }

    system("pause");
}
