#include "../header/tcp-server.hpp"

int main(void) {
    Server server(PORT);
    server.server_listen(5);

    return 0;
}
