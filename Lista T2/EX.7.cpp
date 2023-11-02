//EXERCÍCIO 7
#include<stdlib.h>
#include<stdio.h>
#include"arvorebinaria.h"

int contaNo(Arv *A){
      int dir=0,esq=0;  
  
      if(A==NULL) return 0;//Se arvore vazia retorna 0                           
 
  if(A->esq != NULL)//se esquerda diferente de NULL
   esq = contaNo(A->esq);  //esq recebe a função apontando para a próxima esquerd a
                 else  
                   esq = 0;  //senão esq recebe 0
                      
  if(A->dir != NULL)  //se direita diferente de NULL
         dir = contaNo(A->dir);  //dir recebe a função apontando para a próxima direita
             else  
                    dir = 0;  //senão dir recebe 0
                      
                  return 1+esq+dir; // acumula em 1 se for diferente de NULL
}     





int buscaArvore(Arv *A, int valor){
    if (A==NULL) return -1;
    if (A->info > valor) 
                return buscaArvore(A->esq,valor);
    if (A->info < valor)
                 return buscaArvore(A->dir,valor);
    return 0; 	


}
Arv *criaArvore(Arv *A, int *vetor, int n){
FILE *F;
      F=fopen("saida.txt","rt");
       while(fscanf(F,"%d\n",&n)!=EOF) {
           A=abb_insere(A,n);
          }
      fclose(F);
   
return A;
}




void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Inserir na Arvore\n");       
     printf("2. Retirar da Arvore\n");
     printf("3. Mostrar a Arvore\n");
     printf("4. Buscar na Arvore\n");
     printf("5. Altura da Arvore\n");
     printf("6. Mostrar NOS\n");
     printf("7. Fim\n");
} 
main(){     
      Arv *a=abb_cria();
      Arv *a2=abb_cria();
      int *vet;
      int opmenu;
      int item,busca;
      int tam=100;
      vet=(int*)malloc(sizeof(int)*tam);
      do{
         menu(); 
         scanf("%d", &opmenu);
         switch (opmenu) {
         case 1 : //insere
                printf("Arvore inserida: "); 
                a=criaArvore(a,vet,item);
                break;
        case 2 : //retira
               if(abb_vazia(a)){
               printf("Arvore vazia.\n");
               break;
               }else{
                printf("Digite o valor a ser retirado:\n "); 
                scanf("%d", &item);
                a=abb_retira(a,item);
                break;}    
       
        case 3 : //exibe
              printf("Exibir:\n");       
              printf("1. Exibir em ordem\n");
              printf("2. Exibir pre ordem\n");
              printf("3. Exibir pos ordem\n");
                scanf("%d",&item);
                printf("\nArvore\n");
                 if(item==1)
                 abb_mostraEmOrdem(a);
                 if(item==2)
                 abb_mostraPreOrdem(a);
                 if(item==3)
                 abb_mostraPosOrdem(a);
                break;    
        case 4 : //busca
                printf("Digite o valor a ser buscado:");
                scanf("%d",&item);
                busca=buscaArvore(a,item);
                if(busca==-1){
                 printf("Valor NAO encontrado");
                 }else
                  printf("Valor %d encontrado!",item);
                
                break;                  
      case 5 : //Altura da arvore
       int altura;
       altura=abb_altura(a);
       printf("\n%d",altura);
       break;
     
      case 6 : //Número de Nós
       int nos;
       nos=contaNo(a);
       printf("\n%d",nos);
       break;
     
     
       }  //switch
       printf("\n");
       system("pause"); 
     } while(opmenu!=7);
   } 
