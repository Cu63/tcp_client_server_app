#ifndef TCP_SERVER_HPP
#define TCP_SERVER_HPP

#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>


const int PORT = 54000;


class Server{
    private:
        int sockfd; 
        struct sockaddr_in host_addr, client_addr; 
    public:
        Server(int port=PORT);
        void server_listen(int count=5);
        ~Server();

};


#endif
