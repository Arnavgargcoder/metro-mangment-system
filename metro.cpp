#include<iostream>
#include<string.h>
#include<climits>
using namespace std;
#define INF 999
int mindistance(int distance[],bool stat[])
{
	int minimum=INT_MAX,ind;
	for(int k=0;k<22;k++)
	{
		if(stat[k]==false && distance[k]<=minimum)
		{
			minimum=distance[k];
			ind=k;
		}
	}
	return ind;
}
void metro(int graph[22][22],int source, string stations[21])
{
	int distance[22];
	bool stat[22];
	for(int k=0;k<22;k++)
	{
		distance[k]=INT_MAX;
		stat[k]=false;
	}
	distance[source]=0;
	for(int k=0;k<22;k++)
	{
		int m=mindistance(distance,stat);
		stat[m]=true;
		for(int k=0;k<22;k++)
		{
			if(!stat[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
				distance[k]=distance[m]+graph[m][k];
		}
	}
	cout<<"Minimum Number of Stations from "<<stations[source]<<" To every station"<<endl;
	for(int k=0;k<22;k++)
	{
		cout<<"Minimum Stations from "<<stations[source]<<" To "<<stations[k]<<"  are  "<<distance[k]<<endl;
	}
}
int main()
{
	int graph[22][22]={
			{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}};
	int source;
	string stations[22]={"Munshipulia","Indira Nagar","Bhootnath Market","Lekhraj Market","Badshah Nagar",
							"IT Chauraha","Vishwavidylay","KD Singh Babu Stadium","Hazratganj","Sachivalaya",
							"Hussain Ganj","Charbagh","Durgapuri","Mawaiya","Alambagh Bus Station","Alambagh",
							"Singar Nagar","Krishna Nagar","Transport Nagar","Amausi","Chaudhary Charan Singh International Airport"};
	cout<<"Enter the source station"<<endl;
	for(int i=0;i<21;i++)
	{
		cout<<"Enter "<<i<<" for "<<stations[i]<<endl;
	}
	cin>>source;
	metro(graph,source,stations);
	return 0;
}