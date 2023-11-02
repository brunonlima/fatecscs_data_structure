

struct arv{
       int info;
       struct arv *esq;
       struct arv *dir;
  };
  typedef struct arv Arv;

//cria arvore vazia
Arv*  abb_cria()
{
      return NULL;
}

//verifica se a árvore esta vazia
int abb_vazia(Arv* a)
{
    return a == NULL;
}    


        //   inserção interativa  na ABB
Arv  *abb_insere(Arv* a,int c) {
     Arv *p,*q,*r;
     p=(Arv*)malloc(sizeof(Arv));
     p->info = c;
     p->esq = p->dir = NULL;
     
     if (abb_vazia(a)) //1º elem. da árv.
         a=p;
     else {
         q=a;
         while(q!=NULL)  {
             r=q;
             if(c < q->info)
                  q=q->esq;
             else
                  q=q->dir;
         }
     if(c < r->info)
            r->esq=p;
         else
            r->dir=p;
     }
     return a;
 }   

//inserção recursiva na ABB
/*Arv* abb_insere(Arv *a, int v){
    if (a==NULL){
       a=(Arv*) malloc(sizeof(Arv));
		a->info=v;
		a->esq=a->dir=NULL;
     } 
     else if (v< a->info)
                   a->esq=abb_insere(a->esq,v);
             else    
                   a->dir=abb_insere(a->dir,v);
     return a;
} 
*/
//busca um elemento na Abb
 /*Arv* abb_busca(Arv *r, int v){
    if (r==NULL) return NULL;
    else if (r->info > v) 
                return abb_busca(r->esq,v);
            else if (r->info < v)
                        return abb_busca(r->dir,v);
                    else
                        return r; 	
}
//busca um elemento na Abb – outra versão
 Arv* abb_busca(Arv *r, int v){
    if (r==NULL) return NULL;
    if (r->info > v) 
                return abb_busca(r->esq,v);
    if (r->info < v)
                 return abb_busca(r->dir,v);
    return r; 	
}*/
Arv* abb_retira(Arv *r, int v) {
     if (r==NULL) return NULL;
     if(r->info > v) r->esq = abb_retira(r->esq, v);
     else if (r->info < v) r->dir = abb_retira(r->dir, v);
          else {      //achou o elemento 
                if ( r->esq ==NULL && r->dir ==NULL) { // no sem filhos
                     free(r);
                     r=NULL;   } 
                else  if (r->esq ==NULL) { //filho a direita            
                          Arv *t = r;
                          r=r->dir;
                          free(t);      }
                      else if( r->dir ==NULL) { //filho a esquerda
                                 Arv *t=r;
                                 r=r->esq;
                                 free(t);     }
                               else { //tem 2 filhos     
                                      Arv *f=r->esq;
                                      while (f->dir != NULL)f=f->dir;
                                      r->info =f->info;
                                      f->info=v;
                                      r->esq=abb_retira(r->esq,v);    }
                    }
                    return r;                           
}
// percurso em ordem  esq – raiz - dir
void abb_mostraEmOrdem(Arv *a){
    if (a!=NULL){
       abb_mostraEmOrdem(a->esq);
       printf("%d\n", a->info);
	   abb_mostraEmOrdem(a->dir); 	
} 
}
//percurso em preordem  raiz – esq - dir
void abb_mostraPreOrdem(Arv *a){
    if (a!=NULL){
        printf("%d\n", a->info); 
       abb_mostraPreOrdem(a->esq);
       abb_mostraPreOrdem(a->dir); 	
} 
}

// percurso em PosOrdem    esq – dir - raiz
void abb_mostraPosOrdem(Arv *a){
    if (a!=NULL){
       abb_mostraPosOrdem(a->esq);
       abb_mostraPosOrdem(a->dir); 
       printf("%d\n", a->info);
}
} 
//altura da arvore
int max2 (int a, int b)
{
       return (a>b)?a:b;
}       

int abb_altura(Arv *a)
{
       if (abb_vazia(a))
           return -1;
       return 1+ max2(abb_altura(a->esq),abb_altura(a->dir));   
}              


void abb_imprime2(Arv* a)
{
   Arv *aux;/*variável usada para percorrer a arvore */
   printf("\n\nArvore Binaria\n\n");
   for(aux=a;aux!=NULL;aux=aux->dir)
     printf("%d\t", aux->info);
      for(aux=a;aux!=NULL;aux=aux->esq)
     printf("%d\t", aux->info);
}         



/*int main() {
  int num;
  Arv *a=abb_cria();
  int v;
  //insere elementos na abb até que um -1 seja digitado
  do{
     printf("Entre com o valor a ser inserido, ou -1 para finalizar:\n");
     scanf("%d", &num);
     if(num>=0)
           a=abb_insere(a,num);
     }while(num>=0);
     
   abb_imprime2(a); //imprime em ordem
   printf("\n\n");
   system("pause");             
   return 0;
}                                                                                        
*/

