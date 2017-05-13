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
#include "ftp.h"
#define MAXBUF 3

/*
 * Requiere que el ip del servidor y el puerto sean válidos
 * 
 */
void openFTP(char* serverIP, char* puertoC) {

    /************************************************************/
    /*** Code snippet showing initialization and calling of
     ***/
    /*** the connect() system call.
     ***/
    /************************************************************/
    int port = atoi(puertoC);
    struct sockaddr_in dest;
    sd = socket(PF_INET, SOCK_STREAM, 0);
    /**** Create the socket & do other work ****/
    bzero(&dest, sizeof (dest)); /* start with a clean slate*/
    dest.sin_family = AF_INET; /* select the desired network*/
    if (strcmp(puertoC, "") != 0)
        dest.sin_port = htons(port); /* select the port*/
    inet_aton(serverIP, &dest.sin_addr);
    /* remote address*/
    if (connect(sd, &dest, sizeof (dest)) != 0)
        /* connect!*/ {
        printf("Error %d", errno);
        abort();
    }

    leerRespuesta();


}

void openDataFTP(char* puertoC) {

    /************************************************************/
    /*** Code snippet showing initialization and calling of
     ***/
    /*** the connect() system call.
     ***/
    /************************************************************/
    int sd2;
    int port = atoi(puertoC);
    struct sockaddr_in dest;
    sd2 = socket(PF_INET, SOCK_STREAM, 0);
    /**** Create the socket & do other work ****/
    bzero(&dest, sizeof (dest)); /* start with a clean slate*/
    dest.sin_family = AF_INET; /* select the desired network*/
    dest.sin_port = htons(port); /* select the port*/
    dest.sin_addr.s_addr = INADDR_ANY;
    if (bind(sd2, &dest, sizeof(dest)) != 0) {
        perror("Bind error");
    }
    if (listen(sd2, 1) != 0) {
        perror("Error listen");
    }


}