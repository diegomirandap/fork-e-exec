//Diego Miranda (2210996)
//Felipe Cancella (2210487)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX 10000

int main(void) {
  int n=3, i, status;
  
  int pidfilho=fork();     //cria o novo processo
  if (pidfilho!=0){        //É PAI
    for(i=0;i<MAX;i++){
      n++;
    }
    printf("processo pai-> pid=%d, n=%d\n",getpid(),n);
    waitpid(-1,&status,0); //espera que o processo do filho acabe
  }
  else{                    //É FILHO
    for(i=0;i<MAX;i++){
      n+=10;
    }
    printf("processo filho-> pid=%d, n=%d\n",getpid(),n);
    exit(1);               //sem o exit ele vai executar mais uma vez o que segue no codigo
  }
}