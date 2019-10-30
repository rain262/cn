#include <iostream>
using namespace std;
int main()
{
    int i,j,k,l;
 
    int fs;
    cout<<"\nEnter Size of data:";
    cin>>fs;
     
    int f[20];
     
    cout<<"Enter data:";
    for(i=0;i<fs;i++)
    {
        cin>>f[i];
    }
 
    int gs;
    cout<<"\nEnter key size:";
    cin>>gs;
     
    int g[20];
     
    cout<<"\nEnter key:";
    for(i=0;i<gs;i++)
    {
        cin>>g[i];
    }
 
    cout<<"\nSender Side:";
    cout<<"\n\tdata: ";
    for(i=0;i<fs;i++)
    {
        cout<<f[i];
    }
    cout<<"\n\tkey :";
    for(i=0;i<gs;i++)
    {
        cout<<g[i];
    }
 
    int rs=gs-1;
    cout<<"\nNumber of 0's to be appended:"<<rs;
    for (i=fs;i<fs+rs;i++)
    {
        f[i]=0;
    }
 
    int temp[20];
    for(i=0;i<20;i++)
    {
        temp[i]=f[i];
    }
 
    cout<<"\nMessage after appending 0's:";
    for(i=0; i<fs+rs;i++)
    {
        cout<<temp[i];
    }
 
    for(i=0;i<fs;i++)
    {
        j=0;
        k=i;
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }
    
    int crc[15];
    for(i=0,j=fs;i<rs;i++,j++)
    {
        crc[i]=temp[j];
    }
 
    cout<<"\nCRC bits:";
    for(i=0;i<rs;i++)
    {
        cout<<crc[i];
    }
 
    cout<<"\nTransmitted Frame:";
    int tf[15];
    for(i=0;i<fs;i++)
    {
        tf[i]=f[i];
    }
    for(i=fs,j=0;i<fs+rs;i++,j++)
    {
        tf[i]=crc[j];
    }
    for(i=0;i<fs+rs;i++)
    {
        cout<<tf[i];
    }
 
    cout<<"\nReceiver side : ";
    cout<<"\n\tReceived Frame: ";
    for(i=0;i<fs+rs;i++)
    {
        cout<<tf[i];
    }
 
    for(i=0;i<fs+rs;i++)
    {
        temp[i]=tf[i];
    }
 
    for(i=0;i<fs+rs;i++)
    {
        j=0;
        k=i;
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }
 
    cout<<"\nRemainder:";
    int rrem[15];
    for (i=fs,j=0;i<fs+rs;i++,j++)
    {
        rrem[j]= temp[i];
    }
    for(i=0;i<rs;i++)
    {
        cout<<rrem[i];
    }
 
    int flag=0;
    for(i=0;i<rs;i++)
    {
        if(rrem[i]!=0)
        {
            flag=1;
        }
    }
 
    if(flag==0)
    {
        cout<<"\nRemainder is 0 Hence Message Transmitted From Sender To Receiver is Correct";
    }
    else
    {
        cout<<"\nRemainder is not 0 Hence Message Transmitted From Sender To Receiver Contains Error";
    }
return 0;
}
