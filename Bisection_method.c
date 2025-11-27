// Bisection method

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double fun(double x1);                                                  
double mul(double fxl1, double fxu1);                                   
double bisection(double xl1, double xu1);
int main(){
    double xl, xu, xm_new, xm_old, xm_old1, pro, root, count=0, error_tol;
    double fxl, fxu, fxm, abs_rel = 100.00;
    printf ("Enter the lower range: ");
    scanf ("%lf", &xl);
    printf ("Enter the upper range: ");
    scanf ("%lf", &xu);
    printf ("Enter the error tolerance: ");
    scanf ("%lf", &error_tol);
    printf ("\n");
    root = mul(fun(xl), fun(xu));
    if (root < 0){
        while (abs_rel > error_tol){
            fxl = fun(xl);
            fxu = fun(xu);    
            xm_new = bisection(xl, xu);
            fxm = fun(xm_new); 
            pro = mul(fxl,fxm);
            printf ("xl = %lf ,", xl);
            printf ("xu = %lf ,", xu);
            printf ("xm = %lf ,", xm_new);
            if (pro < 0){
                xu = xm_new;
                xl = xl;
            }
            else if (pro > 0){
                xl = xm_new;
                xu = xu;
            }
            else{
                printf ("Your root %lf", xm_new);
                exit(0);
            }
            if (count == 0)
                printf ("\n");
            if (count >= 1){
                abs_rel = fabs(((xm_new - xm_old)/xm_new)) * 100;
                printf ("abs_rel = %lf \n", abs_rel);
            }
            xm_old1 = xm_old;
            xm_old = xm_new;
            count++;
        }
    }
    else{
        printf ("There is no root exist in this range");
        exit (0);
    }
    printf ("Your root %lf", xm_old1);
    return (0);
}
double fun(double x1){ 
    return (pow(x1,3) - x1 - 4);
}
double mul(double fxl1, double fxu1){
    return (fxl1*fxu1);
}
double bisection(double xl1, double xu1){
    return ((xl1+xu1)/2);
}
