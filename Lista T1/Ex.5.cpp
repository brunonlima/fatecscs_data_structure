#include<stdlib.h>
#include<stdio.h>
#include"Ex.5lista.h"

void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Inserir\n");       
     printf("2. Retirar aluno\n");
     printf("3. Exibir alunos\n");
     printf("4. Buscar aluno\n");
     printf("5. FIM\n");
} 
main(){     
      Lista *li=cria_lista();
      Lista *l=cria_lista();
      int opmenu;
      int item;
      float item2;
      do{
         menu(); 
         scanf("%d", &opmenu);
         switch (opmenu) {
         case 1 : //insere matricula
                printf("Digite o numero da matricula: "); 
                scanf("%d", &item);
                printf("\nDigitem a media deste aluno:");
                scanf("%f",&item2);
                insere_lista(li,item,item2);
                li=insere_ordenado(li,item,item2);
                break;
        
        case 2 : //retira
               if(lista_vazia(li)){
               printf("Lista vazia.\n");
               break;
               }else{
                printf("Digite o numero a ser retirado:\n "); 
                scanf("%d", &item);
                l=li;
                li=retira_lista(li,item,item2);
                if(l!=li)
                 printf("Aluno %d retirado\n",item);
                 else
                    break;
                break;}    
       
        case 3 : //exibe
                exibe_lista(li);
                break;    
        case 4 : //busca
                printf("Digite o aluno a ser buscado:");
                scanf("%d",&item);
                li=busca_lista(li,item);
                if(li==NULL)
                 printf("Aluno não encontrado");
                 else
                  printf("Aluno %d encontrado!",item);
                
                break;                  
       }  //switch
       printf("\n");
       system("pause"); 
     } while(opmenu!=5);
   } 
