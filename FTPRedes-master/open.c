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
extern int errno;
/*
 * 
 */
int openFTP(char* serverIP, char* puertoC){
    
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
    if ( connect(sd, &dest, sizeof(dest)) == 0 )
    /* connect!*/
    {
        printf("Conexión establecida\n");
        abort();
    }
    else{
        printf("Error %d",errno);
        abort();
    }
  /*Creación Socket
  struct sockaddr_in server;
  int sock,puerto,k;
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if(sock == -1)
    {
      printf("Creación de socket fallida");
      exit(1);
    }
  
  puerto = atoi(puertoC);
  server.sin_family = AF_INET;
  server.sin_port = htons(puerto);
  server.sin_addr.s_addr = 0;

  k = connect(sock,(struct sockaddr*)&server, sizeof(server));
  if(k == -1)
    {
      printf("Connect Error");
      exit(1);
    }
  else{
      printf("exito\n");
  }
  
    */
}