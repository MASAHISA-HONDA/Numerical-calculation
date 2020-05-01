#include<stdio.h>
#include<math.h>
#define N 6000000

int main(){
	int i;

	double sum = 0;
	double temp = 0;	

	for(i=0;i<N;i++){
		temp = pow(-1,i)/(2*i+1);
		sum = sum + temp;
		printf("No.%d %39.38f\n",i,sum*4.0);
	}
}
