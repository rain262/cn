/*	Assignment No.6
Write a program using UDP Sockets to enable file transfer 
Name:Arpita Devargaonkar
Batch:TEA(2)
Rollno.:34
*/
//server

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

  /*Create UDP socket*/
  udpSocket = socket(PF_INET, SOCK_DGRAM, 0);

  /*Configure settings in address struct*/
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(7891);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  /*Bind socket with address struct*/
  bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  /*Initialize size variable to be used later on*/
  addr_size = sizeof serverStorage;
  
    /* Try to receive any incoming UDP datagram. Address and port of 
      requesting client will be stored on serverStorage variable */
    nBytes = recvfrom(udpSocket,filename,100,0,(struct sockaddr *)&serverStorage, &addr_size);
	f=open(filename,O_RDWR);
        n=read(f,filedata,300);
        printf("\nThe contents of the file: \n\n");
        printf("%s",filedata);
    /*Send uppercase message back to client, using serverStorage as the address*/
    sendto(udpSocket,filedata,n,0,(struct sockaddr *)&serverStorage,addr_size);
  close(udpSocket);
}

/* Output:
ubuntuos@ubuntu:~$ cd Desktop
ubuntuos@ubuntu:~/Desktop$ gcc udpserver.c
ubuntuos@ubuntu:~/Desktop$ ./a.out

The contents of the file: 

//input file udp.txt

R.H.Sapat college of Engineering
Welcome to GESCOE CNlab
This is UDP FileTransfer Program
ubuntuos@ubuntu:~/Desktop$ 
*/
