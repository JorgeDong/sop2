#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <string.h>

int main (){
	int cmd,killer;

	char shell[25]; //arreglo para guardar el comando ingresado
	do{//ciclo
		printf("shell>"); //pedir comando al usuario
		fgets(shell,25,stdin);
		if(strncmp("exit",shell,3)==0){ // si el comando ingresado es exit,termina el proceso shell
			exit(0); 
		}else if(strncmp("shutdown",shell,7)==0){// si el comando es shutdown, apaga procesos del grupo ./init
			execlp("killall","killall","-g","./init",NULL);
		}else{
			cmd=fork(); //proceso hijo que ejecuta el comando ingresado como proceso
			if(cmd==0){
			execl("/bin/sh","sh","-c",shell,NULL); //  [/bin/sh /sh]- enlace shell del sistema [-c]-ejecuta un string como comando.
			}
			wait(NULL);
		}
	}while(1);


    
}