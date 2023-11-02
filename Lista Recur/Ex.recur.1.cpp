#include<stdlib.h>
#include<stdio.h>

 /*int soma(int a,int b){
     int soma=0;
     while(a<=b){
       soma=a+soma;
       a++;
       }
       return soma;
       }
   */  

int soma(int a, int b) {
    if(a==b) return a;
    return b+soma(a,b-1);
}

int main(){
    int s,s1=1,s2=10 ;
    s=soma(s1,s2);
    printf("%d\n",s);
    system("PAUSE");
}    
