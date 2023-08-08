#include <stdio.h>
#include <stdlib.h>

typedef double (*function)(double);

double f (double x)
{
    return log10(1/(3+2*cos(x)));
}

double integral(function f, double a, double b, int n)
{
    double integ, h, x;
    int i;

    h = (b-a)/n;
    integ = h/2 * (f(a) + f(b));
    x = a+h;

    for (i=1; i<n; ++i)
    {
        integ += f(x)*h;
        x += h;
    }
    return integ;
}

int main()
{


    double a = 0.;
    double b = 3.14, n =10;
    printf ("integral = %.10f\n", integral(f, a, b, n));
}
