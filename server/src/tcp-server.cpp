#include "../header/tcp-server.hpp"

Server::Server(int port) {
    int yes = 1;

    if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == 1) {
        std::cout << "Error";
        return;
    }
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR,
                   &yes, sizeof(int)) == -1){
        std::cout << "Error";
        return;
    }

    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(PORT);
    host_addr.sin_addr.s_addr = 0;
    memset(&(host_addr.sin_zero), '\0', 8);
    if (bind(sockfd, (struct sockaddr *)&host_addr,
                sizeof(struct sockaddr)) == -1) {
        std::cout << "Error";
        return;
    }
}

void Server::server_listen(int count) {
    int new_sockfd;
    socklen_t sin_size;
    int recv_length = 1;
    char buffer[1024];
    if (listen(sockfd, count) == -1) {
        std::cout << "Error";
        return;
    }
    while (1) {
        sin_size = sizeof(struct sockaddr_in);
        new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);
        if (new_sockfd == -1) {
            std::cout << "Error";
            return;
        }
        printf("server: connect %s port %d\n",
                inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        send(new_sockfd, "Hello, world!\n", 14, 0);
        while (recv_length > 0) {
            printf("RECV: %d bytes\n", recv_length);
            recv_length = recv(new_sockfd, &buffer, 1024, 0);
        }
        close(new_sockfd);
    }
}

Server::~Server() {
    close(sockfd);
}
