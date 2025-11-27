// Milnes_method

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fun(double x1, double y1);

int main(){
    double x[4], y[4], f[4], h, h1, yp, x1, yc, f1;
    int i, j;
     double TOL = 0.000001; 
    printf("Enter the data of x and y\n");
    for (i = 0; i < 4; i++) {
        printf("(%d) -  ", i + 1);
        scanf("%lf", &x[i]);
        scanf("%lf", &y[i]);
    }

    h = x[1] - x[0];
    for (j = 0; j < 3; j++) {
        h1 = x[j + 1] - x[j];
        if (fabs(h1 - h) > TOL) { 
            printf("Intervals are not equal. Please enter proper interval values!\n");
            exit(0);
        }
    }

    printf("Enter the value of x ");
    scanf("%lf", &x1);

    for (i = 0; i < 4; i++) {
        f[i] = fun(x[i], y[i]);
    }

    printf("x\ty\tf\n");
    for (i = 0; i < 4; i++) {
        printf("%lf %lf %lf\n", x[i], y[i], f[i]);
    }

    yp = y[0] + ((4 * h * (2 * f[1] - f[2] + 2 * f[3])) / 3);
    f1 = fun(x1, yp);
    yc = y[3] + ((h * (f[2] + 4 * f[3] + f1)) / 3); 

    printf("Predictor: %lf and Corrector: %lf\n", yp, yc);
    printf("The value of f at x=%lf is %lf\n", x1, f1);

    return 0;
}

double fun(double x1, double y1) {
    return (pow(x1, 2) + pow(y1, 2)-2);
}
