#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <string.h>

int main (){

	char shell[25];
	printf("shell>");
    fgets(shell,25,stdin);


    if(strncmp("exit",shell,3)==0){
    	printf("shell es igual a exit\n");
    }else if(strncmp("shutdown",shell,7)==0){
		printf("shell es igual shutdown\n");
    }else{
		printf("es cualquier otro comando %s\n",shell);
    }


    
}