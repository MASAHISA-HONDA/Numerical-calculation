#include<stdio.h>
#include<math.h>
#include"my_func.h"
#define N 20

int main(){
	int i;

	double sum = 0.0;
	double temp = 0.0;
    double ans;

	double a[N];

	for(i=0;i<N;i++){
		temp = pow(-1,i)/(2*i+1);
		sum = sum + temp;
		a[i] = sum*4;
	}

	ans = eps1(&a[0],N);
	printf("eps1.c_ans = %39.38f\n",ans);
	printf("M_PI_ans = %39.38f\n",M_PI);
	printf("delta = %39.38f\n",M_PI - ans);

}
