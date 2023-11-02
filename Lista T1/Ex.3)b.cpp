#include <stdio.h>
#include <stdlib.h>
#define N 5
typedef struct fila{
        int n;
        int ini;
        float vet[N];
        }Fila;

Fila *fila_cria(){
      Fila *f=(Fila*)malloc(sizeof(Fila));
      f->n=0;
      f->ini=0; 
      return f;
} 
int fila_vazia(Fila *f){
    return(f->n==f->ini);
}
void fila_insere (Fila *f, float v) {
    if(f->n==N){ //fila cheia
      printf("Capacidade da fila esgotada.\n");
      return; //retorna ao programa 
     }   
     //insere novo elemento
      f->vet[f->n]=v;
      f->n++; 
}
float fila_retira(Fila *f){
     float v;
    //retira o elemento da fila
     v=f->vet[f->ini];
     for(int i=0;i<f->n;i++)
     {f->vet[i]=f->vet[i+1];
     }
     f->n--;
     return v;
}
void duplicaFilas (Fila *F1, Fila *F2)//função duplica filas
{  F2->n=0;
   F2->ini=0;
   F2->vet[N]=0;
     for(int i=0;i<F1->n;i++)//percorre a fila até o final
    
     {F2->vet[F2->n]=F1->vet[i];//copia o valor da primeira fila para a segunda
      F2->n++;//contador da segunda fila
     }

}

void fila_libera(Fila *f){
     free(f);
}                           
void mostra_fila(Fila *f){
     printf("Conteúdo da fila\n");
     int i;
     for(i=f->ini;i<f->n;i++)
              printf("%0.f\n",f->vet[i]);
     printf("\n");
}               
void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Enfileira\n");       
     printf("2. Retira \n");
     printf("3. Mostrar a fila \n");
     printf("4. Mostrar a fila copiada\n");
     printf("5. Copiar fila\n");
     printf("6. Fim\n");
}
main(){
 Fila *fi=fila_cria();
 Fila *f2=fila_cria();
   int opmenu;  
   float item;
 do{
    menu(); 
    scanf("%d", &opmenu);
    switch (opmenu){
    case 1 : //insere
          printf("Digite o valor a ser enfileirado: ");
          scanf("%f", &item);
          fila_insere(fi,item); 
          break;
    case 2 : //retira
          if(fila_vazia(fi)) 
              printf("fila vazia.\n");
          else
              printf("Elemento retirado = %.0f\n",fila_retira(fi));
          break;    
    case 3 : //mostra
          mostra_fila(fi);  
          break;      
    case 4 : //mostra
          mostra_fila(f2);  
          break;      
    
    case 5 : //Copiar
          duplicaFilas(fi,f2); 
          break;                              
   }//switch
   printf("\n"); system("pause"); 
 } while(opmenu!=6);
}
