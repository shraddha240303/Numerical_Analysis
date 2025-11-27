// Divided Difference

#include <stdio.h>
#include <stdlib.h>
int main(){
    double y[100][100], x[100], p[100], xx, pp=1, yy=0;
    int n, i, j;
    printf("Enter the number of element: ");
    scanf("%d", &n);
    printf("Enter the value of x in order to get y: ");
    scanf("%lf", &xx);

    for(i=0; i<n; i++){
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[0][i]);
        printf("\n");
    }
    for(i=1; i<n; i++){
        printf("d%dy: ", i);
        for(j=0; j<(n-i); j++){
            y[i][j]=(y[i-1][j+1]-y[i-1][j])/(x[j+i]-x[j]);
            printf("%lf ", y[i][j]);
        }
        printf("\n");
    }
    p[0]=1;
    for(i=1; i<n; i++){
        pp=pp*(xx-x[i-1]);
        p[i]=pp;
    }
    for(i=0; i<n; i++){
        yy+=(p[i]*y[i][0]);
    }
    printf("The value of y at x = %lf is %lf. \n", xx, yy);
    return (0);
}
