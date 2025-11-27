// Simpson's rule for numerical integration.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double func(double x1);
int main(){
    double up, low, intval, h, even, odd, sol, sum;
    int i=0;
    double value[100][1];
    printf("Enter the no. of intervals: ");
    scanf("%lf", &intval);
    // cross check as simpson 1/3 rule only work for the even intervals
    if(fmod(intval,2) != 0){
        printf("Please!! enter even number of intervals");
        exit(0);
    }
    printf("Enter the lower limit: ");
    scanf("%lf", &low);
    printf("Enter the upper limit: ");
    scanf("%lf", &up);
    h = (up+low)/intval;
    while(low<=up){
        value[i][0] = func(low);
        if((i!=0)&&(i!=intval)){
            if(fmod(i,2)!=0){
                odd = odd + value[i][0];
            }
            if(fmod(i,2)==0){
                even = even + value[i][0];
            }
        }
        i++;
        low = low+h;
    }
    sum = (value[0][0]+value[i-1][0]+(odd*4)+(even*2));
    sol = (h/3)*sum;
    printf("Your answer is %lf", sol);
    return(0);
}
double func(double x1){
    return (1/(1+pow(x1,2)));
}
