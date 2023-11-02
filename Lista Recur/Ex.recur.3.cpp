#include<stdlib.h>
#include<stdio.h>

/*int buscavetor(int *vet,int tam,int valor){
 int achou=0;
 for(int i=0;i<tam;i++){
       if (vet[i]==valor)
         achou = 1;
 }
 if(achou==1)
 return valor;
  else
   return -1;
 }*/

int buscavetor(int *vet,int tam,int valor){ 

     if(vet[tam]==valor)return valor;
   
    if(tam<=0) return -1;
   
  return buscavetor(vet,tam-1,valor);
     
}  
 
 int main(){
   int v[4],num=3,n,i;
  for(i=0;i<4;i++){
   v[i]=i+1;
}
n=buscavetor(v,i,num);       
for(i=0;i<4;i++){
   printf("%d\n",v[i]); 
}
printf("%d\n",n);
  system("PAUSE");
}     
