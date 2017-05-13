#include "ftp.h"
#define MAXUSER 50  //Máximo largo del nombre del user

void userFTP(char* user){
    char buffer[MAXUSER] = "USER ";//Espacio al final del comando
    strcat(&buffer,user);
    strcat(&buffer,"\n");//Salto de linea al final de los parametros
    
    if(send(sd, buffer, strlen(buffer), 0) <0){
        printf("%i\n",errno);
    };
    bzero(buffer,MAXUSER);
    leerRespuesta();
}