//Diego Miranda (2210996)
//Felipe Cancella (2210487)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>


void type_prompt(void){
	printf("\n ->> ");
}

void read_command(char *cmd, char *params[]) {  /*Guarda cmd em argv[0], e params em argv[...]*/
  int cont=0;
  char input[81],*token;  
  fgets(input,sizeof(input),stdin);             /*Obtem toda a linha escrita*/
  token=strtok(input," \n");                    /*Separa os textos em ' ' e em '\n'*/
  strcpy(cmd,token);
  
  while(token!=NULL){                           /*Copiando os tokens para params[]*/
    params[cont++]=strdup(token);
    token=strtok(NULL," \n");
  }
  params[cont]=NULL;
}

int main(int argc, char *argv[]) {
  char comando[256],*parametros[10];
  int i,status,pidfilho;
  
  for(i=0;i<=argc;i++)                          /*Aloca espaco para os parametros*/
	 parametros[i]=malloc(sizeof(char)*256);

  while (1){                                    /*Executa em loop*/
    type_prompt(); /* display prompt */
    read_command(comando,(char**)parametros);   /*Obtem os parametros*/
    /*comando é a instrucao (echo, cat, etc)*/
    /*parametro é o argv*/
    pidfilho=fork();
    if(pidfilho!=0){                            /*É pai*/
      waitpid(-1,&status,0);                    /*Espera o filho*/
    }
    else{
      execvp(comando,parametros);              /*Executa o comando com os parametros*/
    }
    for(i=0;parametros[i]!=NULL;i++)           /*Libera a memoria alocada dos parametros*/
    	free(parametros[i]);
  }
  return 0;
}
