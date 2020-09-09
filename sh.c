#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <string.h>

int main (){

	char shell[25];
	char shell_exit[3];
	char shell_shut[7];
	printf("shell>");
    fgets(shell,25,stdin);



    for(int i=0;i<=3;i++){
    	shell_exit[i]=shell[i];
    }



    for(int i=0;i<7;i++){
    	shell_shut[i]=shell[i];
    	//printf("The %istring: %c\n", i,shell[i]);
    }

   printf("The string: %s\n", shell_shut);

    if(strcmp("exit",shell_exit)==0){
    	printf("exit es igual a exit\n");
    }

    
}