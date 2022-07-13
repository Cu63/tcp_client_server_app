#ifndef TCP_SERVER_HPP
#define TCP_SERVER_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>

const int PORT = 54000;

class Server{
    public:
        int port;
    private:
        Server(int port=PORT);
};

#endif
