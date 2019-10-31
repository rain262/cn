
import java.io.*;
import java.net.*;

public class udpchatserver
{
  public static void main(String args[]) throws IOException 
  {
	 DatagramSocket ss = null; 
	
			
	 ss = new DatagramSocket(9001);  
	
		  
	 byte[] receiveData = new byte[512]; 
	
	 byte[] sendData  = new byte[512]; 
	
	 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));   
	 System.out.println(" UDP Server socket is created and waiting for client");
		
	 while(true) 
	 { 
  		  
	  DatagramPacket receivePacket =new DatagramPacket(receiveData, receiveData.length); 
  
	  ss.receive(receivePacket); 
  
	  String message = new String(receivePacket.getData(), 0, receivePacket.getLength());  //myoperation = istream.readUTF();
	  System.out.println("Client Says: "+message);
	  if(message.equals("end")) break;
	 
	  System.out.println("Enter Server Message:");
	  message = br.readLine();
		  
	  InetAddress IPAddress = receivePacket.getAddress(); 
  
	  int port = receivePacket.getPort(); 
		  
	  sendData = message.getBytes(); 
  
	  DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress,port); 
  
	  ss.send(sendPacket); 
	 
		 	 } 	
    ss.close();
    System.out.println("Server Stopped by User program");
  }
}
/*
import java.io.*;
import java.net.*;

public class udpchatserver
{
  public static void main(String args[]) throws IOException 
  {
	 DatagramSocket ss = null; 
	 //ServerSocket serversocket = null; Socket socket =null;
			
	 ss = new DatagramSocket(9001);  
	 //serversocket = new ServerSocket(8000);
		  
	 byte[] receiveData = new byte[512]; 
	   //DataInputStream istream = new DataInputStream(socket.getInputStream());
	 byte[] sendData  = new byte[512]; 
	 //DataOutputStream ostream = new DataOutputStream(socket.getOutputStream());
	 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));   
	 System.out.println(" UDP Server socket is created and waiting for client");
		
	 while(true) 
	 { 
  		  
	  DatagramPacket receivePacket =new DatagramPacket(receiveData, receiveData.length); 
  
	  ss.receive(receivePacket); 
  
	  String message = new String(receivePacket.getData(), 0, receivePacket.getLength());  //myoperation = istream.readUTF();
	  System.out.println("Client Says: "+message);
	  if(message.equals("end")) break;
	  // To read from console
	  System.out.println("Enter Server Message:");
	  message = br.readLine();
		  
	  InetAddress IPAddress = receivePacket.getAddress(); 
  
	  int port = receivePacket.getPort(); 
		  
	  sendData = message.getBytes(); 
  
	  DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress,port); 
  
	  ss.send(sendPacket); 
	  //ostream.writeUTF(myoperation);
		 	 } 	
    ss.close();
    System.out.println("Server Stopped by User program");
  }
}

*/
