

#include <stdio.h>

#include <cstdlib>
//#include <iostream>

int f(int x = 3)
{
    return 10*x;    
}


int main(void)
{
    
    printf ("sizeof(char) = %ld\n", sizeof(char));
    printf ("sizeof(int) = %ld\n", sizeof(int));
    printf ("sizeof(long) = %ld\n", sizeof(long));
    printf ("sizeof(long int) = %ld\n", sizeof(long int));
    printf ("sizeof(float) = %ld\n", sizeof(float));
    printf ("sizeof(double) = %ld\n", sizeof(double));
    printf ("sizeof(long double) = %ld\n", sizeof(long double));
    system("pause");    
    return 0;
    
    
    //int printf = 1;
    int n = 1;0;
    float x = 10;
    float y = x*x;

    int tiny, huge;
    
    int i;
    i = 0.1;
    printf("%d\n", i);
    i = 0.9;
    printf("%d\n", i);
    i = -.1;
    printf("%d\n", i);
    i = -0.9; 
    printf("%d\n", i);
    
    
    

    printf("%ld\n", sizeof(int));
    printf("%ld\n", sizeof(long long int));
    printf("%ld\n", sizeof(short int));
    printf("%ld\n", sizeof(double));
    printf("%ld\n", sizeof(long double));
//    printf("%d\n", sizeof(short double));
    system("pause");    
    
    return 0;
}
