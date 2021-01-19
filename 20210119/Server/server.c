#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handler(const char* message);

int main(int argc, char** argv){
    int server_socket;
    int client_socket;

    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t client_addr_size;
    
    char message[] = "Hello, world!";

    server_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); //socket 함수를 이용하여, 소켓 생성
    /*
        PF_INET: IPv4 프로토콜을 의미
        SOCK_STREAM: 비연결지향형 소켓
        IPPROTO_TCP: TCP 소켓을 의미
    */

    memset(&server_addr, 0, sizeof(server_addr)); //server_addr의 주소를 0으로 초기화
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if(bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr))==-1) //bind함수를 이용하여, 포트와 아이피를 할당
        error_handler("bind() error!");
    
    if(!!listen(server_socket, 5)) //listen 함수를 통하여, 연결 가능으로 변경
        error_handler("listen() error");
    
    client_addr_size = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);
    if(client_socket==-1) error_handler("accept() error");
    write(client_socket, message, sizeof(message));
    close(client_socket);
    close(server_socket);
    return 0;
    
}

void  error_handler(const char * message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}