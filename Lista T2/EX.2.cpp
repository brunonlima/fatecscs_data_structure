//EXERCÍCIO 2
#include<stdlib.h>
#include<stdio.h>
#include<time.h>


void preencheVetor(int tam, int *v){
  
  FILE *fp;
    fp=fopen("saida.txt","wt");//abri arquivo para escrever
      srand(time(NULL));
      int i;	
      tam=rand()%50+3; //Cria um tamanho aleatório para o vetor 
		  v=(int*)malloc(sizeof(int)*tam);
      for(i=0;i<tam;i++) {
            v[i]=rand()%100;//cria numeros para preencher o vetor entre 0 e 100.
            fprintf(fp,"%d\n",v[i]);
       }
      fclose(fp);//fecha arquivo
    printf("arquivo gravado\n");
     }
     
     int main(){
      int tam,*v;
      preencheVetor(tam,v);
       system("pause");
}
