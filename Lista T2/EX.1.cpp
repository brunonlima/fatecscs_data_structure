//EXERCÍCIO 1
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void preencheVetor(int tam, int *v){
     
    srand(time(NULL));
      int i;	
      tam=rand()%13;//Cria um tamanho aleatório para o vetor 
		  v=(int*)malloc(sizeof(int)*tam);
      for(i=0;i<tam;i++) {
            v[i]=rand()%100;//cria numeros para preencher o vetor entre 0 e 100.
            printf("%d\t",v[i]);
       }
       printf("\n\n");
     }
     
     int main(){
      int tam,*v;
      preencheVetor(tam,v);
       system("pause");
}
