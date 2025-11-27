// newton forward interpolation

#include <stdio.h>
#include <stdlib.h>
int main(){
    double y[100][100], h, x1, x[100], p[100], xx, pp, yy=0;
    int n, i, j, fact=1, k;
    printf("Enter the number of element: ");
    scanf("%d", &n);
    printf("Enter the difference between x: ");
    scanf("%lf", &h);
    printf("Enter the starting value of x: ");
    scanf("%lf", &x1);
    printf("Enter the value of x in order to get y: ");
    scanf("%lf", &xx);
    for(i=0; i<n; i++){
        printf("y[%lf] = ", x1);
        x[i]=x1;
        scanf("%lf", &y[0][i]);
        x1 += h;
    }
    for(i=1; i<n; i++){
        printf("d%dy: ", i);
        for(j=0; j<(n-i); j++){
            y[i][j]=y[i-1][j+1]-y[i-1][j];
            printf("%lf ", y[i][j]);
        }
        printf("\n");
    }
    p[0]=1;
    j=1;
    p[1]=(xx-x[0])/h;
    pp=p[1];
    for(i=2; i<n; i++){
        pp=pp*(p[1]-j);
        for(k=1; k<=i; k++){
            fact*=k;
        }
        p[i]=(pp/fact);
        fact=1;
        j++;
    }
    for(i=0; i<n; i++){
        yy+=(p[i]*y[i][0]);
    }
    printf("The value of y at x = %lf is %lf. \n", xx, yy);
    return (0);
}
Displaying Bisection method.txt.
