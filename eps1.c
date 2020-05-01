#include<stdio.h>

void eps1(long double *in,long double *out,int size){
	int i,j;
	long double e[size][size];

	e[0][0] = *(in + 0);
	e[0][1] = *(in + 1);

	e[1][0] = 1.0 / (e[0][1] - e[0][0]);

	for (j=2;j<size;j++){
		e[0][j] = *(in + j);
		e[1][j-1] = 1.0 / (e[0][j] - e[0][j-1]);

		for(i=1;i<j;i++){
			e[i+1][j-i-1] 
			=e[i-1][j-i] + 1.0 / (e[i][j-i] - e[i][j-i-1]);
		}
	}
	for(j=0;j<size;j++){
		*(out+j) = e[j][0];
		printf("e[%d][0] = %Lf\n",j,*(out+j));
	}
}
