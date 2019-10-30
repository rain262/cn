
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
  int clientSocket, portNum, nBytes,length;
  char filename[100],filedata[500];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  clientSocket = socket(PF_INET, SOCK_DGRAM, 0);
  
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(7891);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

    addr_size = sizeof serverAddr;    
    printf("Enter the name of the file : ");
    scanf("%s",filename);
    length=strlen(filename);
      
    sendto(clientSocket,filename,length,0,(struct sockaddr *)&serverAddr,addr_size);

                nBytes = recvfrom(clientSocket,filedata,500,0,NULL, NULL);

    printf("Received from server: %s\n",filedata);
  close(clientSocket);
}
