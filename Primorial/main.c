#include <stdio.h>
#include <math.h>

int isPrime(int n){
    if(n<=1) return 0;
    if(n%2==0) return (n==2);
    for(int div = 3, step = 2, roof = (int) sqrt(n);div<roof;div+=step, step^=6){
        if(n%div == 0) return 0;
    }
    else return 1;
}

int main(){
    unsigned int primorial = 0; int n = 0;
    puts("Escriba el primorial que quiera calcular:")
    scanf("%d",&n);
    if(n>1) primorial=2; 
    for(int i = 3, step=2; i <= n; i+=step, step^=6){
         if(isPrime(i))
             primorial *= i;
    }
    printf("%d# = %u\n",n,primorial);
    return 0;
}
