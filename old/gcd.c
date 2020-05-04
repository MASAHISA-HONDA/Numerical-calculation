#include <stdio.h>
 
int gcd(int a,int b)
{
  int r, tmp;
  
  if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }
  
  r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
 
  return b;
}

int main(){

	int N;
	int a =2;

	scanf("%d",&N);

	int ans = gcd(N,a);

	printf("gcd= %d\n",ans);
	

}
