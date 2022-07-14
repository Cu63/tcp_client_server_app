#include "../header/tcp-client.hpp"


Client::Client(int port) {
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


int Client::send_file(char *fname) {
    char buff[1024] = "Hello\n";
    std::ifstream file;
    int send_bytes;
    file.open(fname);

    if (!file.is_open()) {
        std::cout << "Error: can't open file.\n";
        return -1;
    }

    send_bytes = send(sockfd, buff, 6, 0);
    if (send_bytes == -1) {
        std::cout << "Error: can't send bytes.\n";
        return -1;
    }
    /*
    while (file.get(buff, 1024)) {
        sent_bytes = send(sockfd, buff, );
    }
    */
    file.close();
    return 1;
}


Client::~Client() {
    close(sockfd);
}
