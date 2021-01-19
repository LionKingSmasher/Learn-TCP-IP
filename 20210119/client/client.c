#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handler(const char *message);

int main(int argc, char **argv){
    int sock;
    struct sockaddr_in server_addr;
    char message[256];
    int str_len;

    sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock==-1) error_handler("socket() error");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if(!!connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr))) error_handler("connect() error");
    str_len = read(sock, message, sizeof(message)-1);
    if(str_len == -1) error_handler("read() error");
    printf("Message: %s\n", message);
    close(sock);
    return 0;

}

void error_handler(const char* message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}