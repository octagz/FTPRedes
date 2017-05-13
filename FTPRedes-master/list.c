#include "ftp.h"

#define MAXCOMMAND 50  //Máximo largo del nombre del user


void listFTP(char * dir){
    
    char buffer2[MAXCOMMAND] = "PORT 127,0,0,1,54,93";
    strcat(&buffer2,"\n");
    send(sd,buffer2, strlen(buffer2), 0);
    
    leerRespuesta();
    
    char buffer[MAXCOMMAND] = "LIST "; //Espacio al final del comando
    strcat(&buffer,dir);
    strcat(&buffer,"\n"); //Salto de linea al final de los parametros
    
    if(send(sd, buffer, strlen(buffer), 0) <0){
        printf("%i\n",errno);
    };
    bzero(buffer,MAXCOMMAND);
    leerRespuesta();
}