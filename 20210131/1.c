/*
        2021.01.30

        TCP/IP 복습
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char** argv){
    struct sockaddr_in server;
    int server_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    /*
        IPv4 프로토콜을 사용하여, 비연결지향형 TCP 소켓을 생성하고, 생성이 성공하면, 그에 맞는 파일 디스크립터를 server_socket에 저장한다.

        PF_INET : IPv4 프로토콜
        SOCK_STREAM: 비연결 지향형 소켓(TCP)
        SOCK_DGRAM: 연결 지향형 소켓(UDP)
    */
    memset(&server, 0, sizeof(server)); //server라는 변수에 있는 모든 데이터를 0으로 초기화
    server.sin_family = AF_INET; //위에서 주소 소켓의 프로토콜 체계를 IPv4로 하였으므로, 주소 체계또한 IPv4로 설정
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    /*
        htonl은 인텔 기준으로 리틀 엔디안 형식을 빅 엔디안 형식으로 바꾸어줌
        INADDR_ANY는 서버의 IP주소를 자동으로 할당
    */
    server.sin_port = htons(atoi(argv[1])); //네트워크 바이트는 빅 에디안 형식으로 통일 하였으므로, 변환시켜준다.
    bind(server_socket, (struct sockaddr*)&server, sizeof(server)); //주소 할당

}