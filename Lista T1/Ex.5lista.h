typedef struct lista {
          		int matricula;
        		float media;
          		struct lista *prox;
 	}Lista;
 //definição da lista

Lista *l; //ponteiro que deve receber o endereço da lista

/* retorna uma lista vazia */
  Lista * cria_lista()
 {
    return NULL;
}

/* insere o novo dado no início da lista , e retorna a lista atualizada*/
Lista * insere_lista(Lista *l, int dado,float m)
{
Lista *novo=(Lista*) malloc (sizeof(Lista));
novo->matricula =dado;
novo->media=m;
novo->prox=l;
return novo;
}           

/* percorre a lista do inicio até o fim mostrando os elementos*/
void exibe_lista(Lista *l)
{     
    //variável usada para percorrer a lista
     Lista *aux; 
      for(aux=l;aux!=NULL;aux=aux->prox)
      {
            printf("\nMatricula: %d\t = = Media :%f", aux->matricula,aux->media);
      }         

/* retorna 1 se vazia ou zero se falso*/
}
int lista_vazia(Lista *l)
{     
    if (l==NULL)
          return 1;
    else
           return 0; 
}         

/* retorna o elemento ou NULL se não achou*/
Lista* busca_lista(Lista *l, int dado)
{     
  //variável usada para percorrer a lista
  Lista *aux; 
   for(aux=l;aux!=NULL;aux=aux->prox)
   { 
     if(aux->matricula == dado) 
     return aux;
   }         
   return NULL;
}
/* retorna o elemento ou a lista original*/
Lista* retira_lista(Lista *l, int dado,float m)
{
      Lista* ant=NULL; //ponteiro para o anterior
      Lista *aux=l;// ponteiro para percorrer a lista  
      //procura o elemento na lista guardando seu anterior
      while(aux!=NULL && aux->matricula!=dado && aux->media!=m)       {
            ant=aux;
            aux=aux->prox;
      }
      //verifica se achou o elemento
      if(aux==NULL) {
           printf("\nNao localizado\n");         
           return l; //não achou - retorna a lista
      }
      //retira o elemento
      if (ant==NULL) //primeiro da lista
         l=aux->prox;
      else
        //retira do meio/fim da lista
        ant->prox=aux->prox;
      free(aux);
      return l;
}

Lista* insere_ordenado(Lista *l, int v,float m)
{
    Lista* ant=NULL;
    Lista* p=l;
    //cria novo elemento
    Lista*  novo=(Lista*)malloc(sizeof(Lista));
    novo->matricula=v;
     novo->media=m;
     //procura posição de inserção
    while (p!=NULL && p->matricula < v) {//ordena pela matricula
          ant=p;
          p=p->prox;
    }     
    //encadeia o elemento
    if(ant==NULL) {//insere no inicio  
         novo->prox=l;
         l=novo;
    }
    else //insere no meio ou no fim da lista
    {
         novo->prox=ant->prox;
         ant->prox=novo;
     }
     return l;
}        
