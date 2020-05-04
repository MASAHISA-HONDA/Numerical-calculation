#include<stdio.h>
#include"my_func.h"

double array_add(double *a,double *b,double *ans,int size){
	int i;
	for(i=0;i<size;i++){
		*(ans+i) = *(a+i) + *(b+i);
	}
}
