#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <string.h>


int main (){
    char ch;
    int rows=0;
    int nuser=0;
    int nchar=0;
    int flag=0;
    char users[20][2][100];
    printf("\nhola mundo GETTY\n");
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
        //printf("%c [%d][%d][%d]\n",ch,nuser,flag,nchar);
        if(ch=='\n'){
            flag=0;
           nuser++; 
           nchar=0;
        }
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<12;k++){
                printf("%c",users[i][j][k]);
            }
        }
    }


    // printf("%d",rows);
    // while((ch=fgetc(file))!='\n'){
    //     users[0][1][i]
    //     printf("%c",ch);
    // }
    //sleep(5);

}