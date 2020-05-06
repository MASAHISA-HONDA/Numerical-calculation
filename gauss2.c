#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void gauss(double *A,double *X,double *b,int n){
    int i,j,k,kl,imax,jmax;
    double s,p,q,r;
    double *a,*x;
    int *jun;
    double *sf;
    int ak;
    int aik;
    int aj;
    int aij;
    int ai;

    /*A配列のコピーを作成*/
    a = (double *)malloc(sizeof(double) * n * n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            *(a+n*i+j) = *(A+n*i+j);
        }
    }

    /*for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%f\n",*(a+n*i+j));
        }
    }*/

    /*X配列のコピーを作成*/
    x = (double *)malloc(sizeof(double) * n);
    for(i=0;i<n;i++){
            *(x+i) = *(X+i);
    }
    /*for(i=0;i<n;i++){
        printf("%f\n",*(x+i));
    }*/


    jun = (int *)malloc(sizeof(int) * n);
    sf = (double *)malloc(sizeof(double) * n);


    /*バランシング*/
    for(i=0,ai=0;i<n;i++,ai+=n){
        p = 0.0;
        for(j=0;j<n;j++){
            if( (q = fabs(*(a+ai+j))) > p ){p = q;}
        }
        for(j=0;j<n;j++){
            *(a+ai+j) /= p;
        }
        *(x+i) = *(b+i)/p;
	printf("%f\n",*(x+i));
    }

    for(j=0,aj=0;j<n;j++,aj+=n){
        p = 0.0;
        for(i=0,aij=aj;i<n;i++,aij+=n){
            if( (q = fabs(*(a+aij))) > p ){p = q;}   
        }
        for(i=0,aij=aj;i<n;i++,aij+=n){
            *(a+aij) /= p;
        }
        *(sf+j) = p;
	printf("%f\n",*(sf+j));
    }

/********************/
     for(k=0,ak=0;k<n-1;k++,ak+=n){
        kl = k+1;
        /*完全選択法*/
        jmax=k;
        imax=k;
        p=0.0;

        for(i=k,ai=ak;i<n;k++,ai+=n){
            for(j=k;j<n;j++){
                if( (q=fabs(*(a+ai+j)))>p ){
                    p=q;
                    imax=i;
                    jmax=j;
                }
            }
        }
        *(jun+k) = jmax;
        if(imax != k){
            ai = imax*n;
            for(j=k;j<n;j++){
                s = *(a+ak+j);
                *(a+ak+j) = *(a+ai+j);
                *(a+ai+j) = s;
            }
            s = *(x+k);
            *(x+k) = *(x+imax);
            *(x+imax) = s;
        }
        if(jmax != k){
            for(i=0,aik=k,aij=jmax;i<n;i++,aik+=n,aij+=n){
                s = (*(a+aik));
                (*(a+aik)) = (*(a+aij));
                (*(a+aij)) = s;
            }
        }
        /* k */
        p = *(a+ak+k);
        for(j=kl;j<n;j++){
            *(a+ak+j) /= p;
        }
        r = (*(x+k)) /= p;
        /* i */
        for(i=kl,ai=ak+n;i<n;i++,ai+=n){
            q = *(a+ai+k);
            for(j=kl;j<n;j++){
                *(a+ai+j) -= q * (*(a+ak+j));
            }
            *(x+i) -= q*r;
        }
    }
/********************/
    *(x+(n-1)) /= *(a+ak+(n-1));
    for(k=n-2,ak=n*(n-2);k>=0;--k,ak-=n){
        kl = k+1;
        s= (*x+k);
        for(j=kl;j<n;j++){
            s -= *(a+ak+j) * (*x+j);
        }
        *(x+k) = s;
        ak -= n;
    }
    for(k=n-2;k>=0;--k){
        j= *(jun+k);
        s = *(x+k);
        *(x+k) = *(x+j);
        *(x+j) =s;
    }
    for(j=0;j<n;j++){
        *(x+j) /= *(sf+j);
    }
    free(jun);
    jun = NULL;
    free(sf);
    sf=NULL;
    free(a);
    a=NULL;
    free(x);
    x=NULL;
    
}
