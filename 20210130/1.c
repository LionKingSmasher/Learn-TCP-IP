#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

void error_message(const char* message);

int main(int argc, char **argv){
    char* internet_address = "1.1.2.2";
    unsigned long conv_address = inet_addr(internet_address);
    /*
        inet_addr 함수의 역할: 문자열로 보여진 아이피 주소를 변환해서 리턴함
    */
    if(conv_address == INADDR_NONE) //주소 할당에 실패하였을때
        error_message("Error!");
    else 
        printf("address: 0x%lx\n", conv_address);
    return 0;
}

void error_message(const char* message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}