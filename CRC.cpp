#include<iostream>
#include<conio.h>
#include<string.h>
#include <cstdlib>
using namespace std;
class crc
{
	string data,generator,dataword,codeword;
	public:
		void input();
		void dw();
		void sen();
		string modulo(string,string);
		void receiver(string);
};

void crc::input()
{
	cout<<"Enter the  Data : ";
	getline(cin,data);
	cout<<"Enter the Generator : ";
	getline(cin,generator);
	cout<<"\nData : "<<data;
	cout<<"\nGenerator : "<<generator;
}

void crc::dw()
{
	dataword.append(data);
	
	for (int i =0 ;i<(generator.length()-1);i++ )
	{
		dataword+='0';
    }
    cout<<"\ndataword : "<<dataword<<endl;    
}
void crc::sen()
{
	string temp;
	cout<<"  Sender Side "<<endl<<endl;
    temp=modulo(generator,dataword);
    
    codeword.append(data);
    codeword.append(temp);
    cout<<"Codeword : "<<codeword<<endl;
    cout<<endl;
    cout<<" Receiver Side "<<endl<<endl;
    cout<<"1) Without Noise "<<endl<<endl;
    
    receiver(codeword);
    cout<<endl;
    
    cout<<"2) With Noise  "<<endl;
    cout<<endl;
    string codeword2;
	codeword2.append(codeword);
	cout<<"Second Codeword : "<<codeword2<<endl;
    int c = codeword2.length()-1;
    int r= rand() % c;
    cout<<"Bit to change of second codeword : "<<r<<endl;
    for (int i =0 ;i<(codeword.length());i++ )
	{
		if(i== r){
			codeword2[i]=(char) (int(codeword2[i]-48)+1)%2+48;
		}
		   
    }
    cout<<"Second Codeword : "<<codeword2<<endl;
    receiver(codeword2);
    
}

string crc::modulo(string dividend,string divisor)
{ 
    string temp,r;
    int n=dividend.length();
    for(int i=0; i< n ; i++)
    {
    	temp+=divisor[i];
    	r+='0';
	}	 
    for(int j=0 ;j<= (divisor.length()-dividend.length() ) ;j++)
    {
    	if(temp.length()<dividend.length() && (n-1)<divisor.length())
    	{   		
    		n+=1;
    		temp+=divisor[n-1];
		}
		
        string result = "";    
        for(int i = 1; i < temp.length(); i++)
         { 
                if(temp[0]=='1')
                {
                	if (dividend[i] == temp[i])
                        result += "0";
                    else
                        result += "1";
				}
				else
				{
                	if (r[i] == temp[i])
                       result += "0";
                    else
                       result += "1";
				}
         }
         temp=result;  
	}

    cout<<"Remainder = "<<temp<<endl;
    
    return temp;
}
void crc::receiver(string codw)
{
	string temp;
	int n = 0;
	
	temp=modulo(generator,codw);

	for (int i =0 ;i<(temp.length());i++ )
	{
		if(temp[i]!='0')
		    n=1;
    }
	if(n == 0)
	   cout<<"Codeword Correctly Received"<<endl;
	else
	   cout<<"There is an Error in Codeword Received"<<endl;
}
int main()
{
	crc c;
	c.input();
	c.dw();
	c.sen();
	getch();
    return 0;
}

