/* 
 * File:   main.c
 * Author: Gonzalo Arró
 *
 * Created on 9 de mayo de 2017, 08:58
 */

/*
 *  client.c
 *
 *  Simple FTP Client
 *  ====================
 *  Connects the server, and sends a command "Get FILENAME" to retrieve
 *  the file. If the file exists on the server, client retrieves it.
 *
 *  Compile & link  :   gcc client.c -o client
 *  Execute         :   ./client
 *
 *  Ozcan Ovunc <ozcan_ovunc@hotmail.com>
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ftp.h"


int main(int argc , char **argv)
{
    char* ip = "localhost";
    char* puerto = "21";
    printf("%s\t%s\n",ip,puerto);
    openFTP(ip,puerto);
    return 0;
}