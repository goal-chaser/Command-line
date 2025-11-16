#include <winsock2.h>
#include <ws2tcpip.h>      
#include <windows.h>
#include<stdio.h>

unsigned short calculate_checksum(unsigned short *buffer, int size){
        unsigned long sum = 0;

        while(size > 1){
            sum += *buffer++;
            size -= 2;
        }

        if(size == 1){
            sum += *(unsigned char*)buffer;
        }

        sum = (sum >> 16) + (sum & 0xFFFF);
        sum += (sum >> 16);

        return (unsigned short)(~sum);
    }

int ping_f(char x[]){

    WSADATA wsadata;
    if(WSAStartup(MAKEWORD(2, 2), &wsadata) != 0){
        printf("Error in starting windows networking.");
        return 1;
    }
    SOCKET s = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(s == INVALID_SOCKET){
        printf("error in creating a socket");
        WSACleanup();
        return 1;
    }
    int timeout = 2000;
    if(setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout)) != 0){
        printf("Error in set socket");
        closesocket(s);
        WSACleanup();
        return 1;
    }
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = 0;

    if(inet_pton(AF_INET, x, &dest_addr.sin_addr) != 1){
        printf("Error in converting the DNS");
        closesocket(s);
        WSACleanup();
        return 1;
    }
    typedef struct{
        unsigned char type;
        unsigned char code;
        unsigned short checksum;
        unsigned short id;
        unsigned sequence;
    }ICMP_HEADER;


    char packet[sizeof(ICMP_HEADER) + 32];
    ICMP_HEADER *icmp = (ICMP_HEADER*)packet;
    icmp->type = 8;
    icmp->code = 0;
    icmp->checksum = 0;
    icmp->id = GetCurrentProcessId();
    icmp->sequence = 1;

    icmp->checksum = calculate_checksum((unsigned short*)packet, sizeof(packet));

    LARGE_INTEGER frequency, start, end;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    int sent = sendto(s, packet, sizeof(packet), 0, (struct sockaddr*)&dest_addr, sizeof(dest_addr));

    if(sent == SOCKET_ERROR){
        printf("send failed");
        closesocket(s);
        WSACleanup();
        return 1;
    }
    char reply[1024];
    int recv = recvfrom(s,reply, sizeof(reply), 0, NULL, NULL);

    if(recv == SOCKET_ERROR){
        int error = WSAGetLastError();
        if(error == WSAETIMEDOUT){
            printf("request time out");
        }
        else{
            printf("recieve error");
        }
    }
    else{
        printf("got %d bytes\n",recv);
    }

    QueryPerformanceCounter(&end);

    double milliseconds = (double)(end.QuadPart - start.QuadPart) * 1000.0/ frequency.QuadPart;

    printf("ms = %.2lf", milliseconds);

    ICMP_HEADER *reply_icmp = (ICMP_HEADER*)(reply + 20);

    if(reply_icmp->type == 0){
        printf("Ping successful\n");
    }
    else{
        printf("Got ICMP type %d\n",reply_icmp->type);
    }
    closesocket(s);
    WSACleanup();
    return 0;

}

int main(){
    char addr[] = "8.8.8.8";
    while(1==1){
        ping_f(addr);
        Sleep(1000);
    }
}

