#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>


int main(int argc, char *argv[]){
    
    if (argc <=1){
        printf("Usage: ./dnslookup address\n");
        return 1;
    }


    struct addrinfo hints;
    struct addrinfo *ai0;
    int x;
    

    for(int i =1; i < argc ; i++){
        memset(&hints, 0, sizeof(hints));
        hints.ai_family = PF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        if((x = getaddrinfo(argv[i],"80", &hints, &ai0)) !=0){
            printf("Error: unable to lookup IP address: %s", gai_strerror(x));
        }

    char ipv4[INET_ADDRSTRLEN];
    struct sockaddr_in *addr4;
    

    char ipv6[INET6_ADDRSTRLEN];
    struct sockaddr_in6 *addr6;

    
    for (;ai0 != NULL; ai0 = ai0->ai_next) {
        if (ai0->ai_addr->sa_family == AF_INET) {
            addr4 = (struct sockaddr_in *) ai0->ai_addr;
            inet_ntop(AF_INET, &addr4->sin_addr, ipv4, INET_ADDRSTRLEN);
            printf("%s IPV4: %s\n", argv[i], ipv4);
        }
        else if (ai0->ai_addr->sa_family == AF_INET6) {
            addr6 = (struct sockaddr_in6 *) ai0->ai_addr;
            inet_ntop(AF_INET6, &addr6->sin6_addr, ipv6, INET6_ADDRSTRLEN);
            printf("%s IPV6: %s\n", argv[i], ipv6);
        }
        }
    }

    
       
    






}