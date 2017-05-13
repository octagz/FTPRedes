#include <unistd.h>

void closeConnection(int fd) {
    
    close(fd);
    printf("Conexión finalizada.\n");
}
