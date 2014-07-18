
#include <math.h>
#include <stdio.h>

float poli2(float x, float a, float b, float c)
{
  return a*x*x + b*x + c; 
}

float poli2deriv(float x, float a, float b)
{
  return 2.0*a*x + b; 
}



int main()
{
  float x0 = -10.0;
  float epsilon = 0.001;
  float a = 1.0;
  float b = -3.0;
  float c = -10.0;

  float fx0 = poli2(x0, a, b, c);
  float fx0deriv = poli2deriv(x0, a, b);

  while ( fabs(fx0) > epsilon and fabs(x0 < 1000000.0) )
  {
    printf("f(%f) = %f\n", x0, fx0);
    float x1 = x0 - fx0 / fx0deriv;
    x0 = x1; 
    fx0 = poli2(x0, a, b, c);
    fx0deriv = poli2deriv(x0, a, b);
  }
  printf("f(%f) = %f\n", x0, fx0 );

}
