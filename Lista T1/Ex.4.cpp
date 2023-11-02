//fila Circular
#include <stdio.h>
#include <stdlib.h>
#define N 5

//EXERCÍCIO 4
typedef struct { 
    int *Vetor; //ponteiro p/ o vetor
    int tamVetor;
    int tamFila;/*saber o tamanho da fila*/
    int inicio; /* indexa o início da Fila */
    int fim;   /*indexa o final da Fila */
   }Fila;
   
//função que aloca a estrtutura da fila na memoria   
Fila *fila_cria(void){
      Fila *f=(Fila*)malloc(sizeof(Fila));
      f->inicio=0;
      f->fim=0;
      f->tamFila=(int)malloc(sizeof(int)*N);
      f->Vetor=(int*)malloc(sizeof(int)*N);
      f->tamVetor=f->tamFila;
      return f;
}      

void compacta(Fila *f){
     int i,t;
     t=f->fim - f->inicio;//calcula o numero de elementos
     for(i=0;i<=t;i++)
        f->Vetor[i]=f->Vetor[f->inicio+i];
     f->fim=t;
     f->inicio=0;
}         
void fila_insere(Fila *f, int v){
    if((f->fim==f->tamFila)&&(f->fim - f->inicio<f->tamFila)){
       f->fim == 0;
            return;
         }
      else
      {   // compacta(f);
      
      }//insere novo elemento
      f->Vetor[f->fim]=v;
      f->fim++; 
  
} 
int fila_vazia(Fila *f){
    return((f->fim-f->inicio)==0);
}

int fila_retira(Fila *f){
     int v;
     //retira o elemento da fila
     v=f->Vetor[f->inicio];
     f->inicio++;
     return v;
}
void fila_libera(Fila *f){
     free(f);
}                           
void mostra_fila(Fila *f){
     printf("Conteúdo da fila\n");
     int i;
   //mostra na tela todos os valores da fila se inicio menor que o fim
     if(f->inicio<f->fim)
    { 
            for(i=f->inicio;i<f->fim;i++)
              {printf("%d\n",f->Vetor[i]);
              }
    }
    //mostra na tela todos os valores da fila se inicio maior que o fim
      else
     {
         for(i = f->inicio; i < f->tamFila; i++)
         {
              printf("%.0f\n" , f->Vetor[i]);
         }
         
         for(i = 0; i < f->fim; i++)
         {
              printf("%.0f\n" , f->Vetor[i]);
         }
     }
   printf("\n");

}               
void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Enfilera\n");       
     printf("2. Retira \n");
     printf("3. Mostra a fila\n");
     printf("4. Fim\n");
}     
main(){
//programa principal
    Fila *mf;
    mf=fila_cria();
    int opmenu, item;
    do{
     menu();
     scanf("%d",&opmenu);
     switch(opmenu){
        case 1: 
              //if(!filacheia(mf)){
                   printf("Informe o item que deseja adicionar: ");
                   scanf("%d",&item);
                   fila_insere(mf, item); 
              break;
        case 2:                              
              if(!fila_vazia(mf))
                   printf("Elemento retirado = %d\n",fila_retira(mf));
              else
                  printf("Fila vazia");
              break;
       case 3: 
            mostra_fila(mf);
            break;
               

   }//fim switch
   printf("\n");
   system("pause");
  }while(opmenu!=4);
}
