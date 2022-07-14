#ifndef TCP_CLIENT_HPP
#define TCP_CLIENT_HPP

#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fstream>


const int PORT = 54000;


class Client {
    private:
        int sockfd;
        struct sockaddr_in host_addr, client_addr; 
    public:
        Client(int port=PORT);
        int send_file(char *fname);
        ~Client();
};


#endif
