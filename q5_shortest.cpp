#include<iostream>
#include<climits>
#include<conio.h>
using namespace std;

class Dijkstra
{   int n,cost[15][15];
    char router[15];
    
    public:
    	void input();
    	int distance(int[],bool[]);
    	void calculate();
		void output(int[]);    
	
};
void Dijkstra::input()
{  cout<<"\nEnter number of routers : ";
   cin>>n;
   cout<<"\nEnter name of routers : ";
   for(int i=0;i<n;i++)
   {
   	cout<<" router "<<i+1<<" : ";
   	cin>>router[i];
   }
   cout<<"\nEnter cost of routers : ";
   for(int i=0;i<n;i++)
   {
   	 for(int j=0;j<n;j++)
   	 {
   	 	if(i<j)
   	 	{
   	 		cout<<"between("<<router[i]<<","<<router[j]<<") : ";
   	 		cin>>cost[i][j];
		}
		else if (i>j)
		{  
		   cost[i][j]=cost[j][i];
		 
		}
		else{
			cost[i][j]=0;
		}
	 }
   }
   calculate(); 
}
int Dijkstra :: distance(int dist[],bool visit[])
{
	int val,min=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(visit[i]==false && dist[i]<=min)
		{
			min=dist[i];
			val=i;	
		}
	}
	return val;
}
void Dijkstra::calculate()
{
	int dist[n];
	bool visit[n];
	char source;
	cout<<"\nenter source router: ";
	cin>>source;
	for(int i=0;i<n;i++)
	{
		if(source==router[i])
		{ 
			source =i;//storeing index of source router in source
		}
	}
	for(int i=0;i<n;i++)
	{
		dist[i]=INT_MAX;//every dist is set to int_max, since we have not visited so visit=false
		visit[i]=false;
	}
	dist[source]=0;
	for(int i=0;i<n-1;i++)
	{
		int u=distance(dist,visit);
		visit[u]=true;
		for(int v=0;v<n;v++)
		{ 
			if(!visit[v] && cost[u][v] && dist[u]!= INT_MAX && dist[u]+cost[u][v]<dist[v]) 
			{ 
				dist[v]=dist[u]+cost[u][v];
			}
		}
	}
	output(dist);
}
void Dijkstra :: output(int dist[])
{
	cout<<"\nrouter \tdistance from source\n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<router[i]<<"\t\t\t\t"<<dist[i]<<"\n";
	}
}
int main()
{ cout<<"DIJKSTRA ALGORITHM";
   	Dijkstra d;
   	d.input();
   getch();
   return 0;
}
