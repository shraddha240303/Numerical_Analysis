// Birge-Vieta method

#include <stdio.h>
#include <stdlib.h>
int main(){
    double a[100], b[100], c[100], ini, p=0;
    int n, ite, i, j, k;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &n);
    for(i=0; i<n+1; i++){
        printf("Enter the coefficient of degree a[%d]: ", i);
        scanf("%lf", &a[i]);
        b[i]=a[i];
    }
    printf("Enter the initial value: ");
    scanf("%lf", &ini);
    printf("Enter the number of iteration: ");
    scanf("%d", &ite);
    for(i=0; i<ite; i++){
        for(k=n; k>=0; k--){
            b[k]=a[k]+p;
            p=ini*b[k];
        }
        p=0;
        for(k=n; k>=0; k--){
            c[k]=b[k]+p;
            p=ini*c[k];
        }
        ini=ini-(b[0]/c[1]);
        printf("\nValue at %d iteration: %lf", i+1, ini);
        p=0;
    }
    return(0);
}
