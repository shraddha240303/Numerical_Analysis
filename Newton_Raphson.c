// Newton-Raphson method

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double fun(double x1);
double der_fun(double x1);
int main(){
    double x, xn;
    double fx, der_fx;
    printf ("Enter the approximation value: ");
    scanf ("%lf", &x);
    fx = fabs(fun(x));
    der_fx = der_fun(x);
    xn = x - (fx / der_fx);
    while (fabs(fun(xn)) >= 0.0006){
        x = xn;
        fx = fun(xn);
        der_fx = der_fun(x);
        xn = x - (fx / der_fx);
    }
    printf ("The root is %lf: ", xn);
    return (0);
}
double fun(double x1){;
    return (pow(x1,3) - x1 - 4);
}
double der_fun(double x1){
    return ((3*pow(x1,2)) - 1);
}
