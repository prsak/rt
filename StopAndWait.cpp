#include<iostream>
#include <windows.h>
#include <time.h>
#include <cstdlib>
#include<ctime>
#include <unistd.h>
using namespace std;
class timer {
    private:
     	unsigned long begTime;
    public:
     	void start() {
      	begTime = clock();
    }
  	unsigned long elapsedTime() {
      	return ((unsigned long) clock() - begTime) / CLOCKS_PER_SEC;
    }
};
void timec(int sec)
{
    Sleep(sec*1000);
}
int main()
{
	int n,count=1;
	cout<<"Enter no. of Frames to send : ";
	cin>>n;

 unsigned long seconds = 3;
 srand(time(NULL));
 timer t;
 cout<<"Sender has to send "<<n<<" frames "<<endl;

 bool delay = false;
 cout<<endl<<"Sender\t\t\t\t\tReceiver"<<endl;
 do
 {
     bool timeout = false;
     cout<<"Sending Frame : "<<count;
     cout<<"\t\t";
     t.start();

    timec(rand()%5);

     if(t.elapsedTime() <= seconds)
     { 
         cout<<"Received Frame : "<<count<<" ";
         if(delay)
         {
             cout<<"Duplicate";
             delay = false;
         }
         cout<<endl<<endl;
         count++;
     }
     else
     {
         cout<<"---"<<endl;
         cout<<"  **Timeout"<<endl;
         timeout = true;
     }
     t.start();
     if(!timeout)
     {
			timec(rand()%5);
         if(t.elapsedTime() > seconds )
         {
             cout<<"  **Delayed Acknowledgment**"<<endl;
             count--;
             delay = true;
         }
         else
             cout<<" Acknowledgement : "<<count-1<<endl<<endl;
             
     }
 }while(count<=n);
 return 0;
}
