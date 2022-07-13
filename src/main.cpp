#include "../header/tcp-server.hpp"

int main() {
    int sockfd, new_sockfd;

    struct sockaddr_in host_addr, client_addr;
    socklen_t sin_size;
    int recv_length = 1, yes = 1;
    char buffer[1024];

    if ((sockfd = socket(PF_INET, SOCK_STREAM, 0) < 0)) {
        std::cout << "Error in socket.\n";
        return -1;
    }

    /*
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) < 0) {
        std::cout << "Error in SO_REUSEADDR.\n";
        return -1;
    }
    */

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &yes, sizeof(int)) < 0) {
        std::cout << "Error in SO_REUSEADDR.\n";
        return -1;
    }
    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(PORT);
    host_addr.sin_addr.s_addr = 0;
    memset(&(host_addr.sin_zero), '\0', 8);

    if (bind(sockfd, (sockaddr *)&host_addr, sizeof(sockaddr)) == -1) {
        std::cout << "Error in bind socket.\n";
        return -1;
    }

    if (listen(sockfd, 5) == -1) {
        std::cout << "Error in listening socket.\n";
        return -1;
    }

    while (true) {
        sin_size = sizeof(sockaddr_in);
        new_sockfd = accept(sockfd, (sockaddr *)&client_addr, &sin_size);
        if (new_sockfd == -1) {
            std::cout << "Error accept connection.\n";
            return -1;
        }
        std::cout << "Server accept connection " 
                  << inet_ntoa(client_addr.sin_addr) 
                  << ntohs(client_addr.sin_port);
        send(new_sockfd, "Hello, world!\n", 13, 0);
        recv_length = recv(new_sockfd, &buffer, 1024, 0);
        while (recv_length > 0) {
            std::cout << "RECV: " << recv_length << " bytes.\n";
            recv_length = recv(new_sockfd, &buffer, 1024, 0);
        }
        close(new_sockfd);
    }

    return 0;
}
