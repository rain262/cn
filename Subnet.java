import java.util.Scanner;
class Subnet{
public static void main(String args[])

{
Scanner sc = new Scanner(System.in);
System.out.print("Enter the ip address: ");
String ip = sc.nextLine();
String split_ip[] = ip.split("\\."); 
String split_bip[] = new String[4]; 
String bip = "";

for(int i=0;i<4;i++)
{
split_bip[i] = appendZeros(Integer.toBinaryString(Integer.parseInt(split_ip[i]))); // "18" => 18 => 10010 => 00010010
bip += split_bip[i];
}

System.out.println("IP in binary is "+bip);
System.out.print("Enter the number of addresses: ");
int n = sc.nextInt();


int bits = (int)Math.ceil(Math.log(n)/Math.log(2)); 
System.out.println("Number of bits required for address = "+bits);
int mask = 32-bits;
System.out.println("The subnet mask is = "+mask);


int fbip[] = new int[32];
for(int i=0; i<32;i++) fbip[i] = (int)bip.charAt(i)-48; 
for(int i=31;i>31-bits;i--)
fbip[i] &= 0;
String fip[] ={"","","",""};
for(int i=0;i<32;i++)
fip[i/8] = new String(fip[i/8]+fbip[i]);
System.out.print("Subnet address is = ");
for(int i=0;i<4;i++){
System.out.print(Integer.parseInt(fip[i],2));
if(i!=3) System.out.print(".");
}
System.out.println();

int lbip[] = new int[32];
for(int i=0; i<32;i++) lbip[i] = (int)bip.charAt(i)-48; 
for(int i=31;i>31-bits;i--)
lbip[i] |= 1;
String lip[] = {"","","",""};
for(int i=0;i<32;i++)
lip[i/8] = new String(lip[i/8]+lbip[i]);
System.out.print("Broadcast address is = ");
for(int i=0;i<4;i++){
System.out.print(Integer.parseInt(lip[i],2));
if(i!=3) System.out.print(".");
}
System.out.println();
}
static String appendZeros(String s)
{
String temp = new String("00000000");
return temp.substring(s.length())+ s;
}
}
/*
OUTPUT
gescoe@gescoe-OptiPlex-3020:~/Desktop/cnl_2015_pattern/4subnetting$ javac Subnet.java 
gescoe@gescoe-OptiPlex-3020:~/Desktop/cnl_2015_pattern/4subnetting$ java Subnet
Enter the ip address: 192.168.2.10
IP in binary is 11000000101010000000001000001010
Enter the number of addresses: 256
Number of bits required for address = 8
The subnet mask is = 24
Subnet address is = 192.168.2.0
Broadcast address is = 192.168.2.255
*/
