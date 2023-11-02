//EXERCÍCIO 4
#include<stdlib.h>
#include<stdio.h>

void bolha_rec(int *vet,int tam){//procedimento para ordenar vetor
     int i,aux,trocou;
       trocou=0;
      for(i=0;i<tam;i++){
          if(vet[i]>=vet[i+1]){
           aux=vet[i];
           vet[i]=vet[i+1];
           vet[i+1]=aux;
          trocou=1;
           }
     }
     if(trocou==1) bolha_rec(vet,tam--);
}


     
 int buscaBin(int *vet, int indini, int indfim,int pesq){
  int meio;
  
  if(indini>indfim) return -1;//se inicio maior que fim,numero nao encontrado
  
  if(indini<=indfim) meio=(indini+indfim)/2;//se inicio menor igual a fim meio recebe inicio+fim/2
    
  if(pesq==vet[meio])return meio;//se pesq igual a numero do meio a função retorna meio
              
              //se numero pesquisado menor igual a numero do meio,retorna função com fim igual a meio-1
  if(pesq<=vet[meio]) return buscaBin(vet,indini,indfim=meio-1,pesq);
                            
     else{  
          //senão,retorna função com inicio igual a meio+1
          return buscaBin(vet,indini=meio+1,indfim,pesq);
          }       
}
     
     
     
   int  main(){
      int meio,pesq,num,tam=100,*vet,i=0,indini=0,indfim;
      FILE *F;
      vet=(int*)malloc(sizeof(int)*tam);
      F=fopen("saida.txt","rt");
      tam=0;
       while(fscanf(F,"%d\n",&num)!=EOF) {
         vet[tam]=num;
          tam++;
          }
      fclose(F);
      bolha_rec(vet,tam);
      for(i=0;i<=tam;i++){
      printf("%d\t",vet[i]);
      }
      
      printf("\nDigite o número a ser buscado:");
      scanf("%d",&pesq);
      indfim=i;
      meio=buscaBin(vet,indini,indfim,pesq); 
       if(meio!=-1){
                 printf("\nNumero localizado na posicao '%d'\n",meio);
                 }
                 else
                  printf("\nNumero NAO localizado!!\n");
       
       system("pause");
}
