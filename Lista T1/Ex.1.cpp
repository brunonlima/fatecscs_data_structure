#include<stdlib.h>
#include<stdio.h>
#include<string.h>

 void tira_branco(char *f)
  {
    int j=0;
    for(int i=0;f[i]!='\0';i++)//laço para percorrer o vetor
    {
       if(f[i]!=' ')//condição para colocar caracter diferente de espaço.
       {
         f[j]=f[i];// indexação de J receberá o valor de I.
        j++;
        }      
    
    }
  f[j]='\0';//Para ignorar tudo depois do '\0'
  }
  
 
 void contaCaracteres(char *origem)
  { int letra=0;
     char *palavra,aux;
    //bubble sort para ordenar as letras
      for(int i=0;origem[i]!='\0';i++)
      { 
        for(int j=0;origem[j]!='\0';j++)
         { 
           if(origem[i]<origem[j])//condição para a ordenação.
           { 
            aux=origem[i];
            origem[i]=origem[j];
            origem[j]=aux;       
           }
           }
      }  
 
  //segundo laço para a exibição
  for(int i=0;origem[i]!='\0';i++)
      { 
        for(int j=0;origem[j]!='\0';j++)
         { 
           if(origem[i] == origem[j])//condição para a contagem.
           { 
            letra ++;    //contador.    
           }
           }
      //condição para exibir apenas um caracter e o seu total.
      if (origem[i]!=origem[i+1])
      {printf("\nLetra %c = %d caracteres",origem[i],letra);
      }
      letra=0;//zerar o contador.
      }  
    }                                  
 
 
 
 
 int main()
  {
   char *frase;
    frase=((char*)malloc(sizeof(char)*30));//Cria uma cadeia de caracteres
    printf("Digite frase:\n");
    scanf("%30[^\n]",frase);
   tira_branco(frase);//função que tira o espaço em branco.
   printf("\nPalavra = %s\n",frase);
   contaCaracteres(frase);//função que conta os caracteres.
   system("pause");
  }   
   
