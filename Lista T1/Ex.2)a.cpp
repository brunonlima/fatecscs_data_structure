#include <stdio.h>
#include <stdlib.h>
#define N 10
typedef struct pilha{
        int topo;
        float vet[N];
        }Pilha;

Pilha *pilha_cria(){
      Pilha *p=(Pilha*)malloc(sizeof(Pilha));
      p->topo=-1;
      return p;
} 
int pilha_vazia(Pilha *p){
    return(p->topo==-1);
}
void pilha_push(Pilha *p, float v) {
    if(p->topo==N-1){
      printf("Capacidade da pilha esgotada.\n");
      return;
      }   //insere novo elemento
        p->topo++;
       p->vet[p->topo]=v;
     
}              
float pilha_pop(Pilha *p){
     float v;
     if(pilha_vazia(p)){
         printf("Pilha vazia.\n");
        
     }    //retira o elemento da pilha
  
     v=p->vet[p->topo];  
     p->topo--;
     return v;
}
void pilha_libera(Pilha *p){
     free(p);
}      
void mostra_pilha(Pilha *p) {
     printf("Conteudo da pilha\n");
     for(int i=p->topo;i>=0;i--)
         printf("%0.f\n",p->vet[i]);
     printf("\n");
} 



void intercalaPilhas (Pilha *p1, Pilha *p2,Pilha *p3){ //função
     float aux;//váriavel auxiliar
   while  (!pilha_vazia(p1)){//condição para se a pilha não esteja vazia
            aux=pilha_pop(p1);//pilha auxiliar recebe conteúdo da pilha p1
            pilha_push(p3,aux);//insere elementos da pilha aux na pilha p3
     }
      while  (!pilha_vazia(p3)){//enquanto pilha p3 não estiver vazia
            aux=pilha_pop(p3);//pilha auxiliar recebe conteudo da pilha p3
            pilha_push(p2,aux);//insere elementos da pilha pilha aux em p2 empilhando
     }
     
     }
void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Empilha pilha 1 (push)\n");
     printf("2. Empilha pilha 2 (push)\n");       
     printf("3. Retira (pop)\n");
     printf("4. Mostra a pilha\n");
     printf("5. Empilhar as pilhas\n");
     printf("6. Fim\n");
} 
main(){     
      Pilha *pi=pilha_cria();
      Pilha *p2=pilha_cria();
      int opmenu;
      float item;
      do{
         menu(); 
         scanf("%d", &opmenu);
         switch (opmenu) {
         case 1 : //insere
                printf("Digite o valor a ser empilhado: "); 
                scanf("%f", &item);
                pilha_push(pi,item);
                break;
        
        
         case 2 : //insere
                printf("Digite o valor a ser empilhado: "); 
                scanf("%f", &item);
                pilha_push(p2,item);
                break;
        
        case 3 : //retira
               if(pilha_vazia(pi)){
               printf("Pilha vazia.\n");
               break;
               }else{
                printf("Elemento retirado = %.0f\n",pilha_pop(pi));
                break;}    
        
        case 4 : //mostra
                mostra_pilha(pi);
                mostra_pilha(p2);
                break;  
        
        case 5 : 
                Pilha *p3=pilha_cria();
                intercalaPilhas(pi,p2,p3);
                mostra_pilha(p2);
                break;                  
      
       }  //switch
       printf("\n");
       system("pause"); 
     } while(opmenu!=6);
   } 
