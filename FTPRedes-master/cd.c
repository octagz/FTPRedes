#include "ftp.h"

#define MAXDIR 50  //Máximo largo del directorio


void cdFTP(char * dir){
    char buffer[MAXDIR] = "CWD "; //Espacio al final del comando
    strcat(&buffer,dir);
    strcat(&buffer,"\n"); //Salto de linea al final de los parametros
    
    if(send(sd, buffer, strlen(buffer), 0) <0){
        printf("%i\n",errno);
    };
    bzero(buffer,MAXDIR);
    leerRespuesta();
}