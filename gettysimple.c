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
    printf("%d",lines);
    printf("user:");
    fgets(cuser,10,stdin);
    printf("password:");
    fgets(cpasswd,8,stdin);

    //printf("%ld",strlen(users[0][0]));

    //Verify login
    if(strncmp(cuser,users[0][0],strlen(users[0][0]))==0) {
        printf("Son iguales");
    }  

    // //sh
     int pid=fork();
     if (pid==0){
         execlp("./sh","sh",NULL);
     }

     wait(NULL);




    
    








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