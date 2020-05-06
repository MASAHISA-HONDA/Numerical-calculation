#include<stdio.h>
#include<math.h>
#include"my_func.h"
#define N 2

void main(){
    int i,j;

    /*ガウス*/
    /*double a[2][2];
    a[0][0] = 0.0; 
    a[0][1] = 1.0; 
    a[1][0] = 2.0; 
    a[1][1] = 3.0; 

    double x[2];
    x[0] = 1.0;
    x[1] = 5.0;

    double out_gauss[2];
    for(i=0;i<N;i++){
        out_gauss[i] = 0.0;
    }

    gauss(&a[0][0],&x[0],&out_gauss[0],2);
    for(i=0;i<2;i++){
        printf("gauss_out[%d] = %f\n",i,out_gauss[i]);
    }*/

    /*行列積*/
    /*double A[N][N];
    A[0][0] = 1.0; 
    A[0][1] = 1.0; 
    A[1][0] = 2.0; 
    A[1][1] = 5.0;

    double t[N];
    t[0] = 3.0;
    t[1] = 9.0;
    
    double out_b[N];
    for(i=0;i<N;i++){
        out_b[i] = 0.0;
    }
    mxv1(&A[0][0],&t[0],&out_b[0],N);

    for(i=0;i<N;i++){
        printf("out_b[%d] = %f\n",i,out_b[i]);
    }*/

    /***正方行列**/
    /*double out_s[2][2];
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            out_s[i][j] = 0.0;
        }
    }
    mxm2(&A[0][0],&a[0][0],&out_s[0][0],N);
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("out_s[%d][%d] =%f\n",i,j,out_s[i][j]);
    }
    }*/

    /*double ans_max;
    ans_max = max_d(&a[0][0],N*2);
    printf("a_max = %f\n",ans_max);

    int mm = 6786546;
    int nn = 465446553;

    int ans_gcd;
    printf("ans_gcd = %d\n",gcd(mm,nn));
    
    int ans_lcm;
    printf("ans_lcm = %f\n",lcm(mm,nn));
    
    printf("%d",digits(mm));*/

    double array_init_test[10][10];
    array_init(&array_init_test[0][0],10);
    print_a2(&array_init_test[0][0],10);

    double aa = 54546542.423;
    print_d(aa);
    

}
