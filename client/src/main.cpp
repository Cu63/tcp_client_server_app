#include "../header/tcp-client.hpp"


int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << argv[0] << " <file name> ...\n";
        return -1;
    }
    Client client(PORT);
    if (client.send_file(argv[1]) == 1) {
        std::cout << "Success.\n";
    }
    return 0;
}
