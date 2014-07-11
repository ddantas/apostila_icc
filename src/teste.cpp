

#include <iostream>
//#include <stdlib.h>

int f(int x = 3)
{
    return 10*x;    
}


int main(void)
{
    
    printf ("sizeof(int) = %d\n", sizeof(int));
    printf ("sizeof(long) = %d\n", sizeof(long));
    printf ("sizeof(long int) = %d\n", sizeof(long int));
    system("pause");    
    return 0;
    
    
    //int printf = 1;
    int n = 1;0;
    float x = 10;
    float y = x*x;
    char* str = "hello";

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
    
    
    

    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(long long int));
    printf("%d\n", sizeof(short int));
    printf("%d\n", sizeof(double));
    printf("%d\n", sizeof(long double));
//    printf("%d\n", sizeof(short double));
    printf("%s\n", str);
    system("pause");    
    
    return 0;
}
