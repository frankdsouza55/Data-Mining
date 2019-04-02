//Cosine Similarity
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
void displayTable(string list[100],int tab[10][100],int n,int k)
{
	for(int i=0;list[i]!="";i++)
		cout<<"\t"<<list[i];
	for(int i=0;i<n;i++)
	{
		cout<<"\nDoc"<<i+1;
		for(int j=0;j<k;j++)
			cout<<"\t"<<tab[i][j];
	}
}
bool present(string list[100],string x)
{
	for(int i=0;list[i]!="";i++)
		if(list[i]==x)
			return true;
	return false;
}
int count(string list[100],string x)
{
	int c=0;
	for(int i=0;list[i]!="";i++)
		if(list[i]==x)
			c++;
	return c;
}
float cosine(int d1[100],int d2[100],int k)
{
	float sum=0,sumx=0,sumy=0;
	for(int i=0;i<k;i++)
	{
		sum+=d1[i]*d2[i];
		sumx+=d1[i]*d1[i];
		sumy+=d2[i]*d2[i];
	}
	return sum/(sqrt(sumx)*sqrt(sumy));
}
int main()
{
	string doc[10][100]={""},words[100]={""};
	int n,k=0,bin[10][100]={-1},freq[10][100]={-1};
	cout<<"\nEnter no of documents: ";
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		int j=0;
		cout<<"\nEnter document"<<i+1<<" : ";
		while(cin.peek()!='\n')
		{
			if(cin.peek()==' ')
				cin.ignore();
			cin>>doc[i][j++];
		}
		cin.ignore();
	}
	//Getting all the unique words
	for(int i=0;i<n;i++)
		for(int j=0;doc[i][j]!="";j++)
			if(!present(words,doc[i][j]))
				words[k++]=doc[i][j];
	//Binary Attributes
	for(int i=0;i<n;i++)
		for(int j=0;j<k;j++)
			if(present(doc[i],words[j]))
				bin[i][j]=present(doc[i],words[j]) ? 1 : 0;
	cout<<"\nUsing Binary attributes\n";
	displayTable(words,bin,n,k);
	cout<<"\n\nProximity matrix\n";
	for(int i=0;i<n;i++)
		cout<<"\tDoc"<<i+1;
	for(int i=0;i<n;i++)
	{
		cout<<"\nDoc"<<i+1;
		for(int j=0;j<n;j++)
			cout<<"\t"<<setprecision(2)<<cosine(bin[i],bin[j],k);
	}
	//Term Frequency
	for(int i=0;i<n;i++)
		for(int j=0;j<k;j++)
				freq[i][j]=count(doc[i],words[j]);
	cout<<"\n\nUsing Term Frequency\n";
	displayTable(words,freq,n,k);
	cout<<"\n\nProximity matrix\n";
	for(int i=0;i<n;i++)
		cout<<"\tDoc"<<i+1;
	for(int i=0;i<n;i++)
	{
		cout<<"\nDoc"<<i+1;
		for(int j=0;j<n;j++)
			cout<<"\t"<<setprecision(2)<<cosine(freq[i],freq[j],k);
	}
	return 0;
}
/*
Input
3
illegal mining should be stopped
mining of data is crucial for analysis
data mining and pattern mining is useful

3
ant ant bee
dog bee dog hog dog ant dog
cat gnu dog eel fox
*/
