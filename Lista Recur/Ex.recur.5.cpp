#include<stdlib.h>
#include<stdio.h>

/*void bolha_rec(int *vet,int tam){
     int i,aux,trocou;
     do{ 
       tam--;
       trocou=0;
      for(i=0;i<tam;i++){
          if(vet[i]>vet[i+1]){
           aux=vet[i];
           vet[i]=vet[i+1];
           vet[i+1]=aux;
          trocou=1;
           }
     }
     }while(trocou==1);
}*/


void bolha_rec(int *vet,int tam){
     int i,aux,trocou;
       trocou=0;
      for(i=0;i<tam;i++){
          if(vet[i]>vet[i+1]){
           aux=vet[i];
           vet[i]=vet[i+1];
           vet[i+1]=aux;
          trocou=1;
           }
     }
     if(trocou==1) bolha_rec(vet,tam--);
}


int main(){
   int i,v[4];
  for(i=0;i<4;i++){
   printf("Digite o num %d :\n",i+1);
   scanf("%d",&v[i]);
}
bolha_rec(v,i);       
for(i=0;i<4;i++)
   printf("\n%d\n",v[i]); 
  system("PAUSE");
}     
