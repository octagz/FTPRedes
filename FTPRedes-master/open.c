/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   open.c
 * Author: gonzalo
 *
 * Created on 9 de mayo de 2017, 09:44
 */

#include <sys/socket.h>
#include <resolv.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
/*for getting file size using stat()*/
#include<sys/stat.h>
/*for sendfile()*/
#include<sys/sendfile.h>
/*for O_RDONLY*/
#include<fcntl.h>


#include "ftp.h"
#define MAXBUF 3
/*
 * Requiere que el ip del servidor y el puerto sean válidos
 * 
 */
void openFTP(char* serverIP, char* puertoC,char* rta){
    
    /************************************************************/
    /*** Code snippet showing initialization and calling of
    ***/
    /*** the connect() system call.
    ***/
    /************************************************************/
    int port = atoi(puertoC);
    struct sockaddr_in dest;
    int sd;
    sd = socket(PF_INET, SOCK_STREAM, 0);
    /**** Create the socket & do other work ****/
    bzero(&dest, sizeof(dest)); /* start with a clean slate*/
    dest.sin_family = AF_INET; /* select the desired network*/
    if(strcmp(puertoC,"")!= 0)
        dest.sin_port = htons(port); /* select the port*/
    inet_aton(serverIP, &dest.sin_addr);
    /* remote address*/
    if ( connect(sd, &dest, sizeof(dest)) != 0 )
    /* connect!*/
    {
        printf("Error %d",errno);
        abort();
    }
    
    /*Espero la respuesta del servidor, solo leo los primeros
     *3 caracteres que contiene el código de respuesta.
     */
    char buffer[MAXBUF];
    int bytes_read = recv(sd, buffer,MAXBUF,MSG_WAITALL); /* read the message */
    if ( bytes_read < 0 ){
         printf("Error %d",errno);
        abort();
    }
    //Copio en rta la respuesta del servidor
    strcpy(rta,buffer);
    
}