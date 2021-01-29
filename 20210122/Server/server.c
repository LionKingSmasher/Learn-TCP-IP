#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(){
    int server_sock;
    struct sockaddr_in server_addr;

    server_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(server_sock == -1) {
        fputs("socket() failed\n", stderr);
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(9999); 
    if(bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr))==-1){
        fputs("bind() failed\n", stderr);
        exit(1);
    }
}