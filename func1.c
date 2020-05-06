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
    /*for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            printf("%f\n",*(A+size*i+j));
        }
    }
    for(i=0;i<size;i++){
        printf("%f\n",*(x+i));
    }*/
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
/************************　　正方行列同士の積　　********************************/
void mxm2(double *a,double *b,double *out,int size){
    double s;
    int i,j,k;
    /*デバッグ用*/
    /*printf("%f\n",*(a+0));*/
    /*printf("%f\n",*(b+0));*/
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            s = 0.0;
            for(k=0;k<size;k++){
                s += *(a+size*i+k) * *(b+size*k+j);
            }
            *(out+size*i+j) = s;
            /*printf("%f\n",s);*/
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
/***************************10進数整数を引数に取り、桁数をリターンする*****************************/
int digits(int a)
{
  int count = 0;
 
  while(a!=0){
    a = a / 10;
    ++count;
  }
  return count;
}
/*****************************２つの引数を取り、最小公倍数をリターンする****************************/
double lcm(int a,int b){
 
    int tmp;
    int r;

    /*オーバーフロー対策*/
    int keta = digits(a) + digits(b);
    if(keta >= 20){a = 0;}

    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }
    double p = a;
    double q = b;
    double temp_d = gcd(a,b);

    return p*q/temp_d;
}
/**************************配列初期化*******************************/
void array_init(double *out,int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            *(out+n*i+j) = 0.0;
        }
    }
}
/**************************配列print関数*******************************/
void print_a1(double *out,int n){
    int i;
    for(i=0;i<n;i++){
        printf("[%d] = %f\n",i,*(out+i));
    }
}
void print_a2(double *out,int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("[%d][%d] = %f\n",i,j,*(out+i));
        }
    }
}
void print_d(double a){
    printf("%f\n",a);
}
void print_i(int a){
    printf("%d\n",a);
}
