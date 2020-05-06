#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void gauss(double *A,double *B,double *x,int n){
    int i,j,k,kl,imax,jmax;
    double s,p,q,r;
    double *a,*b;
    int *jun;
    double *sf;
    int ak;
    int aik;
    int aj;
    int aij;
    int ai;
    int temp_i,temp_j;

    /*A配列のコピーを作成*/
    a = (double *)malloc(sizeof(double) * n * n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            *(a+n*i+j) = *(A+n*i+j);
        }
    }

    /*B配列のコピーを作成*/
    b = (double *)malloc(sizeof(double) * n);
    for(i=0;i<n;i++){
            *(b+i) = *(B+i);
    }

    /*for(temp_i=0;temp_i<n;temp_i++){
         for(temp_j=0;temp_j<n;temp_j++){
               printf("A[%d][%d] = %f\n",temp_i,temp_j,*(a+n*temp_i+temp_j));
          }
       }
    for(temp_i=0;temp_i<n;temp_i++){
          printf("b[%d] =%f\n",temp_i,*(b+temp_i));
       }
       for(temp_i=0;temp_i<n;temp_i++){
           printf("x[%d] =%f\n",temp_i,*(x+temp_i));
       }*/

    jun = (int *)malloc(sizeof(int) * n);
    sf = (double *)malloc(sizeof(double) * n);


    /*バランシング*/
    for(i=0,ai=0;i<n;i++,ai+=n){
        p = 0.0;
        for(j=0;j<n;j++){
            if( (q = fabs(*(a+ai+j))) > p ){p = q;}
        }
        /*printf("%d行のp = %f\n",i,p);*/
        for(j=0;j<n;j++){
            *(a+ai+j) /= p;
        }
        *(x+i) = *(b+i)/p;
	    /*printf("x[%d] =%f\n",i,*(x+i));*/
    }
        /*for(temp_i=0;temp_i<n;temp_i++){
            for(temp_j=0;temp_j<n;temp_j++){
                printf("A[%d][%d] = %f\n",temp_i,temp_j,*(a+n*temp_i+temp_j));
            }
        }*/


    for(j=0,aj=0;j<n;j++,aj++){
        p = 0.0;
        for(i=0,aij=aj;i<n;i++,aij+=n){
            if( (q = fabs(*(a+aij))) > p ){p = q;} 
        }
        /*printf("%d列のp = %f\n",j,p);*/
        for(i=0,aij=aj;i<n;i++,aij+=n){
            *(a+aij) /= p;
        }
        *(sf+j) = p;
	    /*printf("sf[%d] =%f\n",j,*(sf+j));*/
    }

        /*for(temp_i=0;temp_i<n;temp_i++){
            for(temp_j=0;temp_j<n;temp_j++){
                printf("A[%d][%d] = %f\n",temp_i,temp_j,*(a+n*temp_i+temp_j));
            }
        }
        for(temp_i=0;temp_i<n;temp_i++){
            printf("b[%d] =%f\n",temp_i,*(b+temp_i));
        
        }
        for(temp_i=0;temp_i<n;temp_i++){
            printf("x[%d] =%f\n",temp_i,*(x+temp_i));
        }*/

     for(k=0,ak=0;k<n-1;k++,ak+=n){
        kl = k+1;
        
        /*完全選択法*/
        imax=k;
        jmax=k;
        p=0.0;
        for(i=k,ai=ak;i<n;i++,ai+=n){
            for(j=k;j<n;j++){
                if( (q=fabs(*(a+ai+j)))>p ){
                    p=q;
                    imax=i;
                    jmax=j;
                }
            }
        }
        /*printf("k=%d p=%f imax=%d jmax=%d\n",k,p,imax,jmax);*/
        *(jun+k) = jmax;
        /*printf("jmax[%d] =%d\n",k,jmax);*/
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
                s = *(a+aik);
                *(a+aik) = *(a+aij);
                *(a+aij) = s;
            }
        }

        /*for(temp_i=0;temp_i<n;temp_i++){
            for(temp_j=0;temp_j<n;temp_j++){
                printf("A[%d][%d] = %f\n",temp_i,temp_j,*(a+n*temp_i+temp_j));
            }
        }
        for(temp_i=0;temp_i<n;temp_i++){
            printf("b[%d] =%f\n",temp_i,*(b+temp_i));
        
        }
        for(temp_i=0;temp_i<n;temp_i++){
            printf("x[%d] =%f\n",temp_i,*(x+temp_i));
        }*/

        /* k */
        p = *(a+ak+k);
        for(j=kl;j<n;j++){
            *(a+ak+j) /= p;
        }
        r = *(x+k) /= p;
        /* i */
        for(i=kl,ai=ak+n;i<n;i++,ai+=n){
            q = *(a+ai+k);
            for(j=kl;j<n;j++){
                *(a+ai+j) -= q * *(a+ak+j);
            }
            *(x+i) -= q*r;
        }
    }

    /*for(temp_i=0;temp_i<n;temp_i++){
        for(temp_j=0;temp_j<n;temp_j++){
            printf("A[%d][%d] = %f\n",temp_i,temp_j,*(a+n*temp_i+temp_j));
        }
    }
    for(temp_i=0;temp_i<n;temp_i++){
        printf("b[%d] =%f\n",temp_i,*(b+temp_i));    
    }
    for(temp_i=0;temp_i<n;temp_i++){
        printf("x[%d] =%f\n",temp_i,*(x+temp_i));
    }*/

    /*printf("p = %f\n",p);*/

    /*一番下*/
    *(x+(n-1)) /= *(a+ak+(n-1));
    /*printf("x[1] =%f\n",*(x+1));*/
    
    for(k=n-2,ak=n*(n-2);k>=0;--k,ak-=n){
        /*printf("ak = %d\n",ak);*/
        kl = k+1;
        s= *(x+k);
        /*printf("s = %f\n",s);*/
        for(j=kl;j<n;j++){
            /*printf("a[0][1] = %f\n",*(a+ak+j));
            printf("x[1] = %f\n",*(x+j));*/
            s = s- *(a+ak+j) * *(x+j);
            /*printf("s_aa = %f\n",s);*/
        }
        *(x+k) = s;
        /*printf("x[0] = %f\n",*(x+0));*/
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
    free(b);
    b=NULL;
    
}
