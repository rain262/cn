/*	Assignment No.6
Write a program using UDP Sockets to enable file transfer 
Name:Arpita Devargaonkar
Batch:TEA(2)
Rollno.:34
*/
//client

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
  int clientSocket, portNum, nBytes,length;
  char filename[100],filedata[500];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  /*Create UDP socket*/
  clientSocket = socket(PF_INET, SOCK_DGRAM, 0);

  /*Configure settings in address struct*/
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(7891);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  /*Initialize size variable to be used later on*/
    addr_size = sizeof serverAddr;    
    printf("Enter the name of the file : ");
    scanf("%s",filename);
    length=strlen(filename);
       
    /*Send message to server*/
    sendto(clientSocket,filename,length,0,(struct sockaddr *)&serverAddr,addr_size);

    /*Receive message from server*/
                nBytes = recvfrom(clientSocket,filedata,500,0,NULL, NULL);

    printf("Received from server: %s\n",filedata);
  close(clientSocket);
}

/* Output:
ubuntuos@ubuntu:~$ cd Desktop
ubuntuos@ubuntu:~/Desktop$ gcc udpclient.c
ubuntuos@ubuntu:~/Desktop$ ./a.out
Enter the name of the file : udpfile.txt
Received from server: //input file udp.txt

R.H.Sapat college of Engineering
Welcome to GESCOE CNlab
This is UDP FileTransfer Program
ubuntuos@ubuntu:~/Desktop$ 
*/

