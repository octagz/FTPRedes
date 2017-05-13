#include "ftp.h"

#define MAXCOMMAND 100  //Máximo largo del nombre del user


void cdFTP(char * dir){
    char buffer[MAXCOMMAND] = "CWD "; //Espacio al final del comando
    strcat(&buffer,dir);
    strcat(&buffer,"\n"); //Salto de linea al final de los parametros
    
    if(send(sd, buffer, strlen(buffer), 0) <0){
        printf("%i\n",errno);
    };
    bzero(buffer,MAXCOMMAND);
    leerRespuesta();
}