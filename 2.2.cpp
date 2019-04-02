//Euclidean distance and Manhattan distance
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int n,d1[100],d2[100];
	float eDist=0,mDist=0;
	cout<<"\nEnter the no of data points: ";
	cin>>n;
	cout<<"\nEnter the data points in set 1: ";
	for(int i=0;i<n;i++)
		cin>>d1[i];
	cout<<"\nEnter the data points in set 2: ";
	for(int i=0;i<n;i++)
		cin>>d2[i];
	for(int i=0;i<n;i++)
	{
		mDist+=abs(d1[i]-d2[i]);
		eDist+=(d1[i]-d2[i])*(d1[i]-d2[i]);
	}
	eDist=sqrt(eDist);
	cout<<"\nManhattan Distance = "<<mDist<<"\nEuclidean distance = "<<eDist;
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
