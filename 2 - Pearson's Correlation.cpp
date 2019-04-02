//Correlation
#include<math.h>
#include<iostream>
using namespace std;
int main()
{
	int n,x[100],y[100];
	float x1=0,y1=0,sdx=0,sdy=0,covar=0;
	cout<<"\nEnter the no of data points: ";
	cin>>n;
	cout<<"\nEnter the data points in set 1: ";
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
		x1+=x[i];
	}
	cout<<"\nEnter the data points in set 2: ";
	for(int i=0;i<n;i++)
	{
		cin>>y[i];
		y1+=y[i];
	}
	x1/=n;
	y1/=n;
	for(int i=0;i<n;i++)
	{
		sdx+=(x[i]-x1)*(x[i]-x1);
		sdy+=(y[i]-y1)*(y[i]-y1);
		covar+=(x[i]-x1)*(y[i]-y1);
	}
	sdx=sqrt(sdx/(n-1));
	sdy=sqrt(sdy/(n-1));
	covar/=(n-1);
	cout<<"\nPearson's Correlation = "<<covar/sdx/sdy;
	return 0;
}
/*
Inputs
4
0 -1 0 2
2 0 -1 0
 
4
1 1 2 2
2 2 3 3
*/ 
