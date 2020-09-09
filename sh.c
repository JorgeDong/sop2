#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <string.h>

int main (){
	int cmd,killer;

	char shell[25];
	do{
		printf("shell>");
		fgets(shell,25,stdin);
		if(strncmp("exit",shell,3)==0){ // si el comando ingresado es exit,termina el hijo
			printf("shell es igual a exit\n");
			exit(0); 
		}else if(strncmp("shutdown",shell,7)==0){
			printf("shell es igual shutdown\n");
			killer=fork();
			if(killer==0){
			execlp("killall","killall","-g","./init",NULL);
			}
		}else{
			cmd=fork(); //proceso hijo ejecuta el comando 
			if(cmd==0){
			printf("es cualquier otro comando %s\n",shell);
			execl("/bin/sh","sh","-c",shell,NULL); //  [/bin/sh /sh]- enlace shell del sistema [-c]-ejecuta un string como comando.
			}
			wait(NULL);
		}
	}while(1);


    
}