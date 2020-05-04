#include<stdio.h>
#include<stdlib.h>

/*****************　　＋とーが交互に現れる数列の収束計算　　*********************/
double eps1(double *in,int size){
	int i,j,r;
    r = size;/*行*/
    double ans = 0.0;
    
    /*temp行列*/
	double *e;
    e = (double *)malloc(sizeof(double)*size*size);

    /*output行列*/
    double *out;
    out = (double *)malloc(sizeof(double)*size);
    
    
	*(e+0) = *(in+0);
	*(e+1) = *(in+1);

	*(e+r*1+0) = 1.0 / (*(e+1) - *(e+0));

	for (j=2;j<size;j++){
		*(e+j) = *(in + j);
		*(e+r*1+(j-1)) = 1.0 / (*(e+j) - *(e+(j-1)));

		for(i=1;i<j;i++){
			*(e+r*(i+1)+(j-i-1)) 
			=*(e+r*(i-1)+(j-i)) + 1.0 / (*(e+r*i+(j-i)) - *(e+r*i+(j-i-1)));
		}
	}
	for(j=0;j<size;j++){
		*(out+j) = *(e+r*j+0);
        /*デバッグ用*/
		/*printf("e[%d][0] = %f\n",j,*(out+j));*/
	}

    ans = *(out+(size-2));
    
    /*メモリ解放*/
    free(e);
    e=NULL;
    free(out);
    out=NULL;

    return ans;
}



/************************　　正方行列とベクトルの積　　*****************************/
void mxv1(double *A,double *x,double *out,int size){

    int row = size;
    int column = size;

    int i,j;
    for(i=0;i<row;i++){

        double temp = 0.0;
        for(j=0;j<column;j++){
            temp += *(A+column*i+j) * *(x+j);
            /*デバッグ用*/
            /*printf("temp%d = %f\n",j,temp);*/
            *(out+i) = temp;
        }

    }
}

/*********************配列を受け取り、最大値をリターンする**************************/
double max_d(double *in,int size){
    double temp;
    int i;
    double ans=0.0;

    for(i=0;i<size;i++){
        if( *(in+i) >= temp){ temp = *(in+i); }
    }

    return temp;
}

/***************２つの引数を取り、最大公約数をリターンする**************************/
int gcd(int a,int b){
 
  int tmp;
  int r;
 
  if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }
 
  /* ユークリッドの互除法 */
  r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
 
  return b;
}

/*****************************整数の桁数をリターンする*****************************/
int digits(int a)
{
  int count = 0;
 
  while(a!=0){
    a = a / 10;
    ++count;
  }
 
  return count;
}


/***************２つの引数を取り、最小公倍数をリターンする**************************/
double lcm(int a,int b){
 
    int tmp;
    int r;

    /*オーバーフロー対策*/
    int keta = digits(a) + digits(b);
    if(keta >= 300){a = 0;}

    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }
 
    double temp = gcd(a,b);

    return a*b/temp;
}



