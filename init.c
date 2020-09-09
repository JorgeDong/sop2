#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/wait.h>


int main (){
    int pid;
    int status;
    printf("hola mundo INIT\n");

    for(int i=0;i<6;i++){
        pid=fork();
		if(pid==0){
           // execlp("./getty","getty",NULL);
           execlp("xterm","xterm","-hold","-e","./getty",NULL);
        }
    }
    
    while (wait(&status)>0){
        pid=fork();
		if(pid==0){
            //execlp("./getty","getty",NULL);
            execlp("xterm","xterm","-hold","-e","./getty",NULL);
        }
    }
    
    for(int i=0;i<6;i++){
		wait(&status);
    }
    
    printf("FIN init");
}