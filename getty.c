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
    char users[20][2][100]; //Base de datos
    char cuser[25]; //current user
    char cpasswd[25]; // current passwd

    FILE *file;
    file=fopen("passwd.txt","r");//abrimos el archivo en modo lectura

    if(file==NULL){
        perror("Error while opening file\n");
        exit(EXIT_FAILURE);
    }

    //leer datos del archivo y guardarlos en arreglo users
    while((ch=fgetc(file))!=EOF){
        if(ch==':'){ //Con ":" identificamos si el caracter pertenece a usuario o passwd
            flag=1;
            nchar=0;
        }else{
            if(flag==0){
            users[nuser][flag][nchar]=ch; //guardamos en users[] en el campo para user
            nchar++;
            }else{
            users[nuser][flag][nchar]=ch;//guardamos en users[] en el campo para la passwd
            nchar++;
            }
        }
        if(ch=='\n'){ //Con "\n" identificamos que existe otro usuario
            lines++;
            flag=0;
           nuser++; 
           nchar=0;
        }
    }

    while(1){ //Mostrar el usuario el prompt de login y passwd para iniciar sesion
    printf("user:");
    fgets(cuser,25,stdin);
    printf("password:");
    fgets(cpasswd,25,stdin);
    int login=0;
    //Verificar el usuario y contraseña
    for(int i=0;i<=lines;i++){
    if(strncmp(cuser,users[i][0],strlen(users[i][0]))==0) { //comparamos usuario ingresado con usuarios existentes
        if(strncmp(cpasswd,users[i][1],strlen(users[i][1]))==0){//comparamos contraseña ingresada con contraseña de usuario
            login=1; //permitimos acceso
        }
    }   
    }
    
    
    if(login){// Si se ingresó, crear proceso hijo
     int pid=fork();
     if (pid==0){
         execlp("./sh","sh",NULL); //proceso hijo sera reemplazado por sesion del shell
     }
      wait(NULL); //Esperar a que cierre el shell
      login=0;
    }else{
        printf("Usuario y/o password incorrecto\n");
    } 
    //Volver a pedir credenciales de login.(while)
    }

}