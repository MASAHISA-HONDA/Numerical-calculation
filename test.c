#include<stdio.h>
#include<math.h>
#include"my_func.h"
#define N 2

int main(){

    double a[N][N];
    a[0][0] = 1.0; 
    a[0][1] = 2.0; 
    a[1][0] = 3.0; 
    a[1][1] = 4.0;

    double b[N][N];
    b[0][0] = 5.0; 
    b[0][1] = 6.0; 
    b[1][0] = 7.0; 
    b[1][1] = 8.0; 

    double x[N];
    x[0] = 1.0;
    x[1] = 2.0;

    double out[N];
    int i;
    int j;
    for(i=0;i<N;i++){
        out[i] = 0.0;
    }

    /*********************/
    double c[N][N];
    c[0][0] = 3.0; 
    c[0][1] = 2.0; 
    c[1][0] = 1.0; 
    c[1][1] = 2.0; 

    double out3[N];
    x[0] = 13.0;
    x[1] = 5.0;

    double x1[N];
    for(i=0;i<N;i++){
        out[i] = 0.0;
    }

    gauss(&c[0][0],&x1[0],&out3[0],N);
    for(i=0;i<N;i++){
        printf("x[%d] = %f\n",i,x[i]);
    }

    /*********************/

    double out2[N][N];
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            out2[i][j] = 0.0;
        }
    }

    mxv1(&a[0][0],&x[0],&out[0],N);

    for(i=0;i<N;i++){
        printf("out[%d] = %f\n",i,out[i]);
    }

    mxm2(&a[0][0],&b[0][0],&out2[0][0],N);

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("out2[%d][%d] = %f\n",i,j,out2[i][j]);
        }
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
