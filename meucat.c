//Diego Miranda (2210996)
//Felipe Cancella (2210487)
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  int i;
  char c;
  FILE* arq;
  for(i=1;i<=argc-1;i++){     /*Loop para percorrer todos os argumentos passados*/
    arq=fopen(argv[i],"r");   /*Para cada argumento, abrir o arquivo a qual ela referencia*/
    c=fgetc(arq);             /*Pegar cada um dos caracteres presentes no arquivo*/
    while(c!=EOF){            /*Enquanto nao chegar no fim do arquivo, exibir*/
      printf("%c",c);         
      c=fgetc(arq);
    }
    printf("\n");
    fclose(arq);              
  }    
  return 0;
}