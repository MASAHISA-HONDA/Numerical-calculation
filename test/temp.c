#include<stdio.h>
#include<time.h>

int main(){
    
    long int sum=0;
    clock_t start,end;

    start = clock();
    while(sum < 1000000){
        sum += 1;
        printf("%ld\n",sum);
    }
    end = clock();

    printf("実行時間= %.10f秒\n",(double)(end-start)/CLOCKS_PER_SEC);
    
    sum = 0;
    start = clock();
    while(sum < 1800000000){
        sum += 1;
    }
    end = clock();

    printf("sum = %ld\n",sum);
    printf("実行時間= %.10f秒\n",(double)(end-start)/CLOCKS_PER_SEC);
    
    
    
    
    return 0;
    }
