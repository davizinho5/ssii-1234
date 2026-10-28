#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <iostream>

int main(int argc, char **argv) {
    int pipe;
    char buffer[1024];

    // borrar FIFO por si existiera previamente
    unlink("TuberiaLogger");

    /* crear el FIFO */
    if (mkfifo("TuberiaLogger", 0600)<0) {
        perror("No puede crearse el FIFO");
        return(1);
    }
    /* Abrir el FIFO */
    if (pipe=open("TuberiaLogger", O_RDONLY)<0) {
        perror("No puede abrirse el FIFO");
        return(1);
    }
    /* Leer de la FIFO */
    while (read(pipe, buffer, sizeof(buffer)) > 0) {
        std::cout<<"leido"<<std::endl;
    	std::cout<<buffer<<std::endl;
    }
    close(pipe);
    std::cout<<"CIERRA FIFO"<<std::endl;
    unlink("TuberiaLogger");
    return(0);
}
