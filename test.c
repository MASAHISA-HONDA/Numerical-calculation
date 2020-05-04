#include<stdio.h>
#include<math.h>
#include"my_func.h"
#define N 2

int main(){

    double a[N][N];
    a[0][0] = 1.0; 
    a[0][1] = 2.0; 
    a[1][0] = 3.0; 
    a[1][1] = 1.0;

    double x[N];
    x[0] = 1.0;
    x[1] = 2.0;

    double out[N];
    int i;
    for(i=0;i<N;i++){
        out[i] = 0.0;
    }

    mxv1(&a[0][0],&x[0],&out[0],N);

    for(i=0;i<N;i++){
        printf("out[%d] = %f\n",i,out[i]);
    }

    double ans_max;
    ans_max = max_d(&a[0][0],N*2);
    printf("a_max = %f\n",ans_max);

    int mm = 994765761;
    int nn = 965365799;

    int ans_gcd;
    printf("ans_gcd = %d\n",gcd(mm,nn));
    
    int ans_lcm;
    printf("ans_lcm = %f\n",lcm(mm,nn));
    
    printf("%d\n",digits(mm));
    
    

return 0;}
