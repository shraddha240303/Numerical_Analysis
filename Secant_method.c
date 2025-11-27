// Secant method

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double fun(double x1);
int main(){
    double x, xn, xn1;
    double fx, fxn;
    printf ("Enter the first approximation value: ");
    scanf ("%lf", &x);
    printf ("Enter the second approximation value: ");
    scanf ("%lf", &xn);
    fx = fabs(fun(x));
    fxn = fabs(fun(xn));
    xn1 = ((fxn*x)-(xn*fx))/(fxn-fx);
    while (fabs(fun(xn)) >= 0.0006){
        x = xn;
        xn = xn1;
        fx = fun(x);
        fxn = fabs(fun(xn));
        xn1 = ((fxn*x)-(xn*fx))/(fxn-fx);
    }
    printf ("The root is %lf", xn);
    return (0);
}
double fun(double x1){
    return (pow(x1,3) - x1 - 4);
}
