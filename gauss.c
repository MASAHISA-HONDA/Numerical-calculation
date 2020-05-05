#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void gauss(double *A,double *x,double *b,int n){
    int i,j,k,kl,imax,jmax;
    double s,p,q,r;
    double *a,*ai,*aj,*ak,*aik,*aij;
    int *jun;
    double *sf;

    /*A配列のコピーを作成*/
    a = (double *)malloc(sizeof(double) * n * n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            *(a+n*i+j) = *(A+n*i+j);
        }
    }

    jun = (int *)malloc(sizeof(int) * n);
    sf = (double *)malloc(sizeof(double) * n);

    /*バランシング*/
    for(i=0,ai=a;i<n;i++,ai+=n){
        p = 0.0;
        for(j=0;j<n;j++){
            if( (q = fabs(ai[j])) > p ){p = q;}
        }
        for(j=0;j<n;j++){
            ai[j] /= p;
        }
        *(x+i) = *(b+i)/p;
    }
    for(j=0,aj=a;j<n;j++,aj+=n){
        p = 0.0;
        for(i=0,aij=aj;i<n;i++,aij+=n){
            if( (q = fabs(*aij)) > p ){p = q;}   
        }
        for(i=0,aij=aj;i<n;aij+=n){
            (*aij) /= p;
        }
        sf[j] = p;
    }
    for(k=0,ak=a;k<n-1;k++,ak+=n){
        kl = k+1;
        /*完全選択法*/
        jmax=k;
        imax=k;
        p=0.0;
        for(i=k,ai=ak;i<n;k++,ak+=n){
            for(j=k;j<n;j++){
                if( (q=fabs(ai[j]))>p ){
                    p=q;
                    imax=i;
                    jmax=j;
                }
            }
        }
        jun[k] = jmax;
        if(imax != k){
            ai = a+imax*n;
            for(j=k;j<n;j++){
                s = ak[j];
                ak[j] = ai[j];
                ai[j] = s;
            }
            s = *(x+k);
            *(x+k) = *(x+imax);
            *(x+imax) = s;
        }
        if(jmax != k){
            for(i=0,aik=a+k,aij=a+jmax;i<n;i++,aik+=n,aij+=n){
                s = (*aik);
                (*aik) = (*aij);
                (*aij) = s;
            }
        }
        /* k */
        p = ak[k];
        for(j=kl;j<n;j++){
            ak[j] /= p;
        }
        r = (*(x+k)) /= p;
        /* i */
        for(i=kl,ai=ak+n;i<n;i++,ai+=n){
            q = ai[k];
            for(j=kl;j<n;j++){
                ai[j] -= q*ak[j];
            }
            *(x+i) -= q*r;
        }
    }
    *(x+(n-1)) /= ak[n-1];
    for(k=n-2,ak=a+n*(n-2);k>=0;--k,ak-=n){
        kl = k+1;
        s= (*x+k);
        for(j=kl;j<n;j++){
            s -= ak[j] * (*x+j);
        }
        *(x+k) = s;
    }
    for(k=n-2;k>=0;--k){
        s = *(x+k);
        *(x+k) = *(x+(j=jun[k]));
        *(x+j) =s;
    }
    for(j=0;j<n;j++){
        *(x+j) /= sf[j];
        printf("%f\n",*(x+j));
    }
    free(jun);
    jun = NULL;
    free(sf);
    sf=NULL;
    free(a);
    a=NULL;
    
}