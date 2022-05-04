#include<iostream>
#include<ctime>
#include<cstdlib>
#include<conio.h>
#include<math.h>
using namespace std;
class Selrep{
	public:
		int nf,N,m,no_tr;
		
		Gback(){
			no_tr=0;
		}
		void input();
		void algo();
		void sender(int i);
		int receiver(int i,int x);
		
};
void Selrep::input(){
	cout<<"Enter the number of frames : ";
	cin>>nf;
	cout<<"Enter the value of m : ";
	cin>>m;
	N=pow(2,m)-1;
	cout<<"The Window Size : ";
	cout<<N;
	cout<<endl;	
}
void Selrep::sender(int i){
	for(int j=i;j<i+N && j<=nf;j++)
     {
         cout<<"Sent Frame "<<j<<endl;
         no_tr++;
     }
}
int Selrep::receiver(int i,int x){
	for(int j=i;j<i+N && j<=nf;j++)
     {
         int flag = rand()%2;
         if(!flag)
             {
             		cout<<"\t\t\t\tFrame "<<j<<" Received"<<endl;
             		flag = rand()%2;
         			if(!flag)
             		{
             			cout<<"Acknowledgment for Frame "<<j<<endl;
                 		cout<<" *window Sliding Sending Next Frame"<<endl;
                 		x++;
                 		getch();
					}
             		else{
             			cout<<" *Acknowledgment Not Received"<<endl;
		                 cout<<" *Retransmitting Frame"<<endl;
		                 cout<<"Sent Frame "<<j<<endl;
		         		 no_tr++;
		         		 j--;
		                 getch();
             		}
             }
         else
             {   cout<<"\t\t\t\tFrame "<<j<<" Not Received"<<endl;
                 cout<<" *Retransmitting Frame"<<endl;
                 cout<<"Sent Frame "<<j<<endl;
         		 no_tr++;
         		 j--;
                 getch();
             }
     }
     return x;
}
void Selrep::algo(){
cout<<"\tSender\t\t\t\tReceiver"<<endl;
 int i=1;
 while(i<=nf)
 {
     int x=0;
     sender(i);
     x=receiver(i,x);
     cout<<endl;
     i+=x;
 }
 cout<<"Total number of transmissions : "<<no_tr<<endl;
}
int main()
{
	Selrep s;
	srand(time(NULL));
	s.input();
	s.algo();
 	getch();
 return 0;
}
