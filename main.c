#include<stdio.h>
#include<math.h>
#include"my_func.h"
#define N 30

int main(){
	int i;

	long double sum = 0.0;
	long double temp = 0.0;	

	long double a[N];
	long double out[N];

	/*配列の初期化*/
	for(i=0;i<N;i++){
		*(out+i) = 0.0;
	}

	for(i=0;i<N;i++){
		temp = pow(-1,i)/(2*i+1);
		sum = sum + temp;
		a[i] = sum*4;
	}

	eps1(&a[0],&out[0],N);
	printf("ans = %39.38Lf\n",out[N-2]);
	printf("ans = %39.38f\n",M_PI);
	printf("ans = %39.38Lf\n",M_PI - out[N-2]);

}
