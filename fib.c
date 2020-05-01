#include<stdio.h>
int fibonacci(int);

int main(void){
    //フィボナッチ数列を求める
    int h ,i;
    printf("フィボナッチ数列を第n項まで求める\n")
    printf("nを入力↓\n");
    scanf("%d",&h);

    for(i=0;i<=h;i++){
        printf("第%d項= %d\n",i,fibonacci(i));
    }
    return 0;
}

int fibonacci(int n){
    int fibonacci(int);
    return n<2 ? n : fibonacci(n-1)+fibonacci(n-2);
}