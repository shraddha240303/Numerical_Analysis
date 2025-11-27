// Bracket method to solve the non linear equation

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fun(double x1);                                                  // to store the function
double mul(double fxl1, double fxu1);                                   // for multiply it with xm
double bisection(double xl1, double xu1);                               // function for bisection
double false_pos(double xl1, double xu1, double fxl1, double fxu1);     // function for false position

int main(){

    int cho, cho1=0;
    double x, xl, xu, xm_new, xm_old, xm_old1, pro, pro1, root, count=0, error_tol;
    double fxl, fxu, fxm, abs_rel = 100.00;

    printf ("Which Bracket method would you like to choose: \n");
    printf ("1. Bisection method \n");
    printf ("2. False-Position method  \n");
    printf ("Enter your choice: ");
    scanf ("%d", &cho);

    switch (cho){
        case (1): cho1 = 1; break;
        case (2): cho1 = 2; break;
        deafult: printf ("Enter the valid choice!!!"); exit(0);
    }

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

            if (cho1 == 1){
                xm_new = bisection(xl, xu);
            }
            else{
                xm_new = false_pos(xl, xu, fxl, fxu);
            }

            fxm = fun(xm_new); 
            pro = mul(fxl,fxm);
            
            printf ("xl %lf ,", xl);
            printf ("xu %lf ,", xu);
            printf ("xm %lf ,", xm_new);

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

            if (count == 0){
                printf ("\n");
            }

            if (count == 1){
                abs_rel = 0.00;
            }

            if (count >= 1){
                abs_rel = fabs(((xm_new - xm_old)/xm_new)) * 100;
                printf ("abs_rel  %lf \n", abs_rel);
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

    if (cho1 == 1){
        printf ("Your root %lf", xm_old1);
    }
    else{
        printf ("Your root %lf", xm_old);
    }
    
    return (0);
}

double fun(double x1){

    double f;

    f = pow(x1,3) - 0.165 * pow(x1,2) + 3.993 * pow(10,(-4));         // write any desire function you want
    return (f);
}

double mul(double fxl1, double fxu1){

    double pro;

    pro = fxl1*fxu1;
    return (pro);
}

double bisection(double xl1, double xu1){
    return ((xl1+xu1)/2);
}

double false_pos(double xl1, double xu1, double fxl1, double fxu1){
    return (((xu1*fxl1)-(xl1*fxu1))/(fxl1-fxu1));
}
