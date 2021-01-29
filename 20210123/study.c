#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char **argv){
    /*
        htons(unsigned short); : 호스트 바이트 순서를 네트워크 바이트 순서로 변경(short형)
        htonl(unsigned long);  : 위와 동일하나 long형
        ntohs(unsigned short); : 네트워크 바이트 순서를 호스트 바이트 순서로 변경(short형)
        ntohl(unsigned long);  : 위와 동일하나 long형
    */
    unsigned short t_sock = 0x1234;
    unsigned long t_sock_long = 0x12345678;
    printf("%x\n", htons(t_sock));
    printf("%x\n", htonl(t_sock_long));
}