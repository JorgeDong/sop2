#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <string.h>

int main (){
    char ch;
    int lines=0;
    int nuser=0;
    int nchar=0;
    int flag=0;
    char users[20][2][100];
    char cuser[25];
    char cpasswd[25];
    FILE *file;
    file=fopen("passwd.txt","r");

    if(file==NULL){
        perror("Error while opening file\n");
        exit(EXIT_FAILURE);
    }

    //save Login credentials
    while((ch=fgetc(file))!=EOF){
        
        if(ch==':'){
            flag=1;
            nchar=0;
        }else{
            if(flag==0){
            users[nuser][flag][nchar]=ch;
            nchar++;
            }else{
            users[nuser][flag][nchar]=ch;
            nchar++;
            }
        }
        // printf("%c [%d][%d][%d]\n",ch,nuser,flag,nchar);
        if(ch=='\n'){
            lines++;
            flag=0;
           nuser++; 
           nchar=0;
        }
    }

    while(1){
    printf("user:");
    fgets(cuser,25,stdin);
    printf("password:");
    fgets(cpasswd,25,stdin);
    //printf("%ld",strlen(users[0][0]));
    int login=0;
    //Verify login
    for(int i=0;i<=lines;i++){
    if(strncmp(cuser,users[i][0],strlen(users[i][0]))==0) {
        //printf("Usuario Correcto");
        if(strncmp(cpasswd,users[i][1],strlen(users[i][1]))==0){
            login=1;
            //printf("Acceso Correcto\n");
        }
    }   
    }
    
    //sh
    if(login){
     int pid=fork();
     if (pid==0){
         execlp("./sh","sh",NULL);
     }
    //printf("Esperando");
      wait(NULL);
      //exit(0);
      login=0;
    }else{
        printf("Usuario y/o password incorrecto\n");
    } 
    
    }


    // CHECK PASSWD.TXT
    // for(int i=0;i<2;i++){
    //     for(int j=0;j<2;j++){
    //         printf("\n");
    //         for(int k=0;k<12;k++){
    //             printf("%c",users[i][j][k]);
    //         }
    //     }
    // }


}