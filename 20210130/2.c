#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

void error_message(const char* message);

int main(int argc, char **argv){
    char *test_address = "1.1.2.2";
    struct sockaddr_in addr;
    if(!inet_aton(test_address, &addr.sin_addr)) error_message("Error!!");
    else printf("구조체 내 아이피 주소 확인: 0x%x", addr.sin_addr.s_addr);
    return 0;
    /*
        inet_aton(const char* string, struct in_addr* addr): sockaddr_in 구조체에 IP를 할당할 경우 이용
        보통은

        sock.sin_family = AF_INET; //IPv4 프로토콜 주소 체계
        sock.sin_addr.s_addr = inet_addr({IP 주소});
        sock.sin_port = htons({포트 번호});

        이런식으로 입력을 하여, 할당하지만, inet_aton을 이용할경우

        sock.sin_family = AF_INET;
        inet_aton({IP 주소}, &sock.sin_addr);
        sock.sin_port = htons({포트 번호});

        이런식으로 가능하다

        참고로 sockaddr_in 구조체는

        struct sockaddr_in {
            struct sa_family_t sin_family;
            uint16_t sin_port;
            struct in_addr sin_addr;
        };

        이런식으로 되어있기에, sin_addr을 넣는것
    */
}

void error_message(const char* message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}