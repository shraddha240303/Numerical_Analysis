// Gauss Elimination method

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    double a[100][100], inv[100][100], ide[100][100], sum, c, d, d1;
    int i, j, k, l, n;
    printf ("\nEnter the order of matrix: ");
    scanf ("%d", &n);
    // getting matrix value by user
    printf ("Enter the matrix: \n");
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            printf ("Enter the value of x[%d][%d] : ", i+1, j+1);
            scanf ("%lf", &a[i][j]);
        }
    }
    // making identity matrix
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            if (i==j)
                ide[i][j] = 1;
            else
                ide[i][j] = 0;
        }
    }
    // cross check
    if (a[0][0]==0){
        printf ("Please, enter the a[0][0] value other than zero!!");
        exit(0);
    }
    // displaying the enter matrix value
    printf ("\nEnter Matrix\n");
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            printf ("%lf ", a[i][j]);
        }
        printf ("\n");
    }
    // performing gauss elimination method in matrix and the identity
    for (i=0; i<n; i++){
        for (j=i+1; j<n; j++){
            c = -(a[j][i])/a[i][i];
            for (k=0; k<n; k++){
                d = a[i][k]*c;
                d1 = ide[i][k]*c;
                a[j][k] = a[j][k] + d; 
                ide[j][k] = ide[j][k] + d1;
            }
        }
    }
    // performing back substitution
    for (l=0; l<n; l++){
        for (i=n-1; i>=0; i--){
            sum = 0;
            for (j=i+1; j<n; j++){
                sum += a[i][j]*inv[j][l];
            }
            inv[i][l] = (ide[i][l]-sum)/a[i][i];
        }
    }
    // displaying the matrix value after operation
    printf ("\nInverse Matrix\n");
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            printf ("%lf ", inv[i][j]);
        }
        printf ("\n");
    }
    return (0); 
}
