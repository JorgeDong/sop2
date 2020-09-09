#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main (){

    execl("/bin/sh","sh","-c","ps",NULL);
    sleep(10);
    
}