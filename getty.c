#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/wait.h>


int main (){
    char ch;
    // FILE *file;
    // file=fopen("passwd.txt","r");
    // if(file==NULL){
    //     perror("Error while opening file\n");
    //     exit(EXIT_FAILURE);
    // }
    execlp("xterm","xterm","-hold",NULL);
    printf("\nhola mundo GETTY\n");
    // while((ch=fgetc(file))!=EOF){
    //     printf("%c",ch);
    // }
    
    //sleep(5);

}