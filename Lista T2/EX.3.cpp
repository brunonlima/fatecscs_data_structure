//EXERCÍCIO 3
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"lista.h"


Lista *montaLista(FILE *F, Lista *L){
 int i;
    F=fopen("saida.txt","rt");//abri arquivo para leitura
while(fscanf(F,"%d\n",&i)!=EOF) {//enquanto não for fim de arquivo ele insere dado na lista
        L=insere_ordenado(L,i);
     }

fclose(F);//fecha arquivo
return L;
      }

void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Inserir\n");       
     printf("2. Retirar\n");
     printf("3. Mostrar a Lista\n");
     printf("4. Buscar\n");
     printf("5. Preencher Lista\n");
     printf("6. Fim\n");
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
                l=li;
                li=retira_lista(li,item);
                if(l!=li)
                 printf("Valor %d retirado\n",item);
                 else
                    break;
                break;}    
       
        case 3 : //exibe
                exibe_lista(li);
                break;    
        case 4 : //busca
                printf("Digite o valor a ser buscado:");
                scanf("%d",&item);
                li=busca_lista(li,item);
                if(li==NULL)
                 printf("Valor nao encontrado");
                 else
                  printf("Valor %d encontrado!",item);
                
                break;                  
       case 5 : //insere na lista do arquivo
          FILE *fp;
          li=montaLista(fp,l);
          printf("Lista criada");
          break; 
          }//switch
       printf("\n");
       system("pause"); 
     } while(opmenu!=6);
   } 
