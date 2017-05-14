/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ftp.h
 * Author: gonzalo
 *
 * Created on 9 de mayo de 2017, 10:49
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <string.h>
#include <sys/socket.h>
#include <resolv.h>
#include <netinet/in.h>


void openFTP(char*, char*);
void userFTP(char*);

void leerRespuesta();

void portToHexa(int p, int * a, int * b);

#include <errno.h>
int sd;
