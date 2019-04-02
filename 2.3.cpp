//Jacquards and Simple matching coefficient
#include<iostream>
using namespace std;
int main()
{
	int n,d1[100],d2[100],f00=0,f01=0,f10=0,f11=0;
	float jc=0,smc=0;
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
		if(d1[i]==0 && d2[i]==0)
			f00++;
		if(d1[i]==0 && d2[i]==1)
			f01++;
		if(d1[i]==1 && d2[i]==0)
			f10++;
		if(d1[i]==1 && d2[i]==1)
			f11++;
	}
	smc=float(f11+f00)/(f00+f01+f10+f11);
	jc=float(f11)/(f01+f10+f11);
	cout<<"\nJacquards coefficient = "<<jc<<"\nSimple matching coefficient = "<<smc;
	return 0;
}
/*
Inputs
8
1 1 0 1 1 0 0 1
0 0 0 1 1 1 0 1

4
0 1 0 1
1 0 1 0
*/
