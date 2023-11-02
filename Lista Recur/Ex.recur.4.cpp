#include<stdlib.h>
#include<stdio.h>
#include"listarecur.h"

void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Inserir\n");       
     printf("2. Retirar\n");
     printf("3. Mostrar a Lista\n");
     printf("4. Buscar\n");
     printf("5. Fim\n");
} 
main(){     
      Lista *li=cria_lista();
      Lista *l=cria_lista();
      int opmenu;
      int item;
      do{
         menu(); 
         scanf("%d", &opmenu);
         switch (opmenu) {
         case 1 : //insere
                printf("Digite o valor a ser inserido: "); 
                scanf("%d", &item);
                insere_lista(li,item);
                li=insere_ordenado(li,item);
                break;
        case 2 : //retira
               if(lista_vazia(li)){
               printf("Lista vazia.\n");
               break;
               }else{
                printf("Digite o valor a ser retirado:\n "); 
                scanf("%d", &item);
                li=retira_lista(li,item);
                break;}    
       
        case 3 : //exibe
                exibe_lista(li);
                break;    
        case 4 : //busca
                printf("Digite o valor a ser buscado:");
                scanf("%d",&item);
                l=busca_lista(li,item);
                if(l==NULL){
                 printf("Valor não encontrado");
                 }else
                  printf("Valor %d encontrado!",item);
                
                break;                  
       }  //switch
       printf("\n");
       system("pause"); 
     } while(opmenu!=5);
   } 
