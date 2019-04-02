//Data smoothing measures
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int mean(int arr[50],int n)
{
	float sum=0;
	for(int i=0;i<n;i++)
		sum+=arr[i];
	return round(sum/n);
}
int med(int arr[50],int n)
{
	if(n%2==1)
		return arr[n/2];
	else
		return (arr[n/2]+arr[n/2+1])/2;
}
int main()
{
	int n,d[100],bin[10][10],k;
	cout<<"\nEnter the no of data points: ";
	cin>>n;
	cout<<"\nEnter the data points: ";
	for(int i=0;i<n;i++)
		cin>>d[i];
	cout<<"\nData set after sorting: ";
	sort(d,d+n);
	for(int i=0;i<n;i++)
		cout<<d[i]<<" ";
	cout<<"\nEnter depth: ";
	cin>>k;
	
	for(int i=0;i<k;i++)
	{
		cout<<"\nBin"<<i+1;
		for(int j=0;j<n/k;j++)
		{
			bin[i][j]=d[k*i+j];
			cout<<"  "<<bin[i][j];
		}
	}
	cout<<"\n\nData Smoothing by Bin Means";
	for(int i=0;i<k;i++)
	{
		cout<<"\nBin"<<i+1;
		int m=mean(bin[i],n/k);
		for(int j=0;j<n/k;j++)
			cout<<"  "<<m;
	}
	cout<<"\n\nData Smoothing by Bin Boundaries";
	for(int i=0;i<k;i++)
	{
		cout<<"\nBin"<<i+1;
		for(int j=0;j<n/k;j++)
			if(bin[i][j]-bin[i][0] < bin[i][n/k-1]-bin[i][j])
				cout<<"  "<<bin[i][0];
			else
				cout<<"  "<<bin[i][n/k-1];
	}
	cout<<"\n\nData Smoothing by Bin Medians";
	for(int i=0;i<k;i++)
	{
		cout<<"\nBin"<<i+1;
		int m=med(bin[i],n/k);
		for(int j=0;j<n/k;j++)
			cout<<"  "<<m;
	} 
	int w=ceil(float(d[n-1] - d[0])/k);
	cout<<"\n\nPartitioning into bins using equal width approach";
	for(int i=0;i<k;i++)
	{
		cout<<"\nBin"<<i+1<<" : ["<<d[0]+i*w<<","<<d[0]+(i+1)*w<<")";
		for(int j=0;j<n;j++)
			if(d[j]>=d[0]+i*w && d[j]<d[0]+(i+1)*w)
				cout<<"  "<<d[j];
	} 
	return 0;
}
/*
Inputs
9
0 4 12 16 16 18 24 26 28

15
32 64 44 42 37 32 29 55 52 31 32 42 68 24 44

12
150 70 200 120 800 650 700 240 360 310 650 200
*/
