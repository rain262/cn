#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include<fcntl.h>

int main(){
  int udpSocket, nBytes,f,n;
  char filename[100],filedata[300];
  struct sockaddr_in serverAddr, clientAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size, client_addr_size;
  int i;

  udpSocket = socket(PF_INET, SOCK_DGRAM, 0);

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(7891);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  


  bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  addr_size = sizeof serverStorage;
  
    nBytes = recvfrom(udpSocket,filename,100,0,(struct sockaddr *)&serverStorage, &addr_size);
	f=open(filename,O_RDWR);
        n=read(f,filedata,300);
        printf("\nThe contents of the file: \n\n");
        printf("%s",filedata);
  
    sendto(udpSocket,filedata,n,0,(struct sockaddr *)&serverStorage,addr_size);
  close(udpSocket);
}

