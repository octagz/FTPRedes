#include "ftp.h"
#define MAXCOMMAND 50  //Máximo largo del nombre del user

void userFTP(char* user){
    char buffer[MAXCOMMAND] = "USER ";//Espacio al final del comando
    strcat(&buffer,user);
    strcat(&buffer,"\n");//Salto de linea al final de los parametros
    
    if(send(sd, buffer, strlen(buffer), 0) <0){
        printf("%i\n",errno);
    };
    bzero(buffer,MAXCOMMAND);
    leerRespuesta();
}

void passFTP(char *pw){
    char buffer[MAXCOMMAND] = "PASS ";//Espacio al final del comando
    strcat(&buffer,pw);
    strcat(&buffer,"\n");//Salto de linea al final de los parametros
    
    if(send(sd, buffer, strlen(buffer), 0) <0){
        printf("%i\n",errno);
    };
    bzero(buffer,MAXCOMMAND);
    leerRespuesta();
}