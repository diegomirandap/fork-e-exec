//Diego Miranda (2210996)
//Felipe Cancella (2210487)
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  int i;
  for(i=1;i<=argc-1;i++)         //Para ler cada argumento passado
    printf("%s%s",argv[i]," ");  //Exibir o argumento em questao
  printf("\n");
  return 0;
}