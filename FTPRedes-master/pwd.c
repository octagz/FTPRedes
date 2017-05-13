#include "ftp.h"



void pwdFTP(){
    char buffer[3] = "PWD"; //Espacio al final del comando
    strcat(&buffer,"\n"); //Salto de linea al final de los parametros
    
    if(send(sd, buffer, strlen(buffer), 0) <0){
        printf("%i\n",errno);
    };
    bzero(buffer,3);
    leerRespuesta();
}