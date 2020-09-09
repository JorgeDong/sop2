#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/wait.h>


int main (){
    int pid;
    int status;

    for(int i=0;i<6;i++){ //Crear 6 procesos hijos 
        pid=fork();
		if(pid==0){
           execlp("xterm","xterm","-e","./getty",NULL); //imagen remplazada por procesos getty
        }
    }
    
    while (wait(&status)>0){ //Si un proceso hijo (getty) es terminado por el usuario.(Mantener 6)
        pid=fork();
		if(pid==0){
            execlp("xterm","xterm","-e","./getty",NULL); // crear un nuevo proceso getty. 
        }
    }
}