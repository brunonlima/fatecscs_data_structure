#include<stdlib.h>
#include<stdio.h>

  /*double juroscompostos(double valor,double taxa,int meses){
       int i=1;
       double j,m,m1;
       j=(taxa/100);
       m=valor;
       while(i<meses){
          m=m+(m*j);
          i ++;
          }                   
       return m;
       }

*/

double juroscompostos(double valor,double taxa,int meses){
 if(0==meses) return valor;
 return taxa+juroscompostos(valor=valor+(valor*taxa),taxa,meses-1);
}


int main(){
    int meses=3 ;
    double valor=1000,taxa=10,juros;
    taxa=(taxa/100);
    
    juros=juroscompostos(valor,taxa,meses);
    
    printf("Juros : %0.lf\n",juros);
    system("PAUSE");
}    
