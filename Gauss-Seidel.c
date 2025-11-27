// Gauss-Seidel method

#include <stdio.h>
#include <stdlib.h>
int main(){
    double a[100][100], b[100], sum=0, x[100];
    int n, i, j, ite, k=0;
    printf("Enter the number of equation: ");
    scanf("%d", &n);
    printf("Enter the number of iteration: ");
    scanf("%d", &ite);
    for(i=0; i<n; i++){
        printf("Enter %d equation:  \n", i+1);
        for(j=0; j<n; j++){
            printf("a[%d][%d] ", i+1, j+1);
            scanf("%lf", &a[i][j]);
        }
        printf("b[%d] ", i+1);
        scanf("%lf", &b[i]);
    }
    printf("Enter the initial value: \n");
    for(i=0; i<n; i++){
        printf("x[%d] ", i+1);
        scanf("%lf", &x[i]);
    }
    while(k<ite){
        printf("Iteration %d: ", k+1);
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(i!=j){
                    sum+=(a[i][j]*x[j]);
                }
            }
            x[i]=(b[i]-sum)/(a[i][i]);
            printf("%lf ,", x[i]);
            sum=0;
        }
        printf("\n");
        k++;
    }
    printf("\nThe final solution is:\n");
    for(i=0; i<n; i++){
        printf("%lf", x[i]);
        printf("\n");
    }
    return(0);
}
