//Implementation of Apriori algorithm


//This code has bugs


#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
using namespace std;
int countItems(string items[50])    //counts no of items in a string array
{
    int i;
    for(i=0;items[i]!="";i++);
    return i;
}
bool present(string list[100],string x) //checks if x is present in list
{
	for(int i=0;list[i]!="";i++)
		if(list[i]==x)
			return true;
	return false;
}
void reset(string t[100][50])
{
    for(int i=0;i<100;i++)
        for(int j=0;j<50;j++)
            t[i][j]="";
}
/*
Reference Link
https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n
arr[] ---> Input Array
data[] ---> Temporary array to store current combination
start & end ---> Staring and Ending indexes in arr[]
index ---> Current index in data[]
r ---> Size of a combination to be printed
*/
string t[100][50]={""};
int pos=0;
void combination(string arr[], string data[],int start, int end,int index, int r,string t[100][50])
{
    // Current combination is ready to be printed, print it
    if (index == r)
    {
        for (int j = 0; j < r; j++)
            t[pos][j]=data[j];
        pos++;
        return;
    }
    // replace index with all possible elements. The condition "end-i+1 >= r-index"
    // makes sure that including one element at index will make a combination with
    // remaining elements at remaining positions
    for (int i = start; i <= end && end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        combination(arr, data, i+1,end, index+1, r,t);
    }
}
bool isSubset(string arr1[], string arr2[], int m, int n)
{
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            if(arr2[i] == arr1[j])
                break;
        if (j == m)
            return false;
    }
    return true;
}
int main()
{
    int n,minSC,minC,k=0;
    string items[100][50]={""},c1[100][2]={""},l1[100][2]={""},x[100]={""};
    string c2[100][3]={""},l2[100][3]={""},c3[100][4]={""},l3[100][4]={""};
    cout<<"\nEnter no of transactions: ";
    cin>>n;
    cin.ignore();
	for(int i=0;i<n;i++)
	{
		int j=0;
		cout<<"\nEnter items in transaction"<<i+1<<" : ";
		while(cin.peek()!='\n')
		{
			if(cin.peek()==' ')
				cin.ignore();
			cin>>items[i][j++];
		}
		cin.ignore();
	}
	//Sorting the items in each transaction
	for(int i=0;i<n;i++)
        sort(items[i],items[i]+countItems(items[i]));
	cout<<"\nSorted dataset\n";
	for(int i=0;i<n;i++)
	{
        cout<<"\nT"<<i+1<<"\t";
        for(int j=0;items[i][j]!="";j++)
            cout<<" "<<items[i][j];
	}
	cout<<"\n\nEnter minimum support count and confidence: ";
	cin>>minSC>>minC;
	for(int i=0;i<n;i++)    //stores all unique transactions in x
		for(int j=0;items[i][j]!="";j++)
			if(!present(x,items[i][j]))
				x[k++]=items[i][j];
    sort(x,x+countItems(x));

    //Generating C1 and L1
	int sc,a=0;
	for(int i=0;i<countItems(x);i++)
    {
        sc=0;
        c1[i][1]=x[i];
        for(int j=0;j<n;j++)
            if(present(items[j],x[i]))
                sc++;
        c1[i][0]=to_string(sc);
        if(sc>=minSC)
        {
            l1[a][1]=x[i];
            l1[a++][0]=to_string(sc);
        }
    }
    cout<<"\nL1";
    cout<<"\nItem Set\tSupport Count\n";
    for(int i=0;l1[i][0]!="";i++)
        cout<<l1[i][1]<<"\t\t\t"<<l1[i][0]<<"\n";

    //Generating C2 and L2
    reset(t);
    string data[100]={""};
    int it=0;
    combination(x,data,0,countItems(x)-1,0,2,t); //stores all combinations in t
    for(int i=0,j=0;t[i][j]!="";i++)
    {
        for (j=0;t[i][j]!="";j++);
        j=0;
        it++;
    }
    //copy t into C2
    a=0;
	for(int i=0;i<it;i++)
    {
        sc=0;
        for(int j=0;j<it;j++)   //get support count for each item
            if(isSubset(items[j],t[i],countItems(items[j]),countItems(t[i])))
                sc++;
        c2[i][0]=to_string(sc);
        if(sc>=minSC)
            l2[a][0]=to_string(sc);
        for(int j=0;t[i][j]!="";j++)
        {
            c2[i][j+1]=t[i][j];
            if(sc>=minSC)
                l2[a][j+1]=t[i][j];
        }
        if(sc>=minSC)
            a++;
    }
    cout<<"\nL2\nItem Set\tSupport Count\n";
    for(int i=0,j=0;l2[i][j]!="";i++)
    {
        for (j=1;j<3;j++)
            cout<<l2[i][j]<<" ";
        cout<<"\t\t\t"<<l2[i][0]<<"\n";
        j=0;
    }

    //Generating C3 and L3
    reset(t);
    string data1[100]={""};
    it=pos=0;
    combination(x,data,0,countItems(x)-1,0,3,t); //stores all combinations in t
    for(int i=0,j=0;t[i][j]!="";i++)
    {
        for (j=0;t[i][j]!="";j++);
        j=0;
        it++;
    }
    //copy t into C3
    a=0;
	for(int i=0;i<it;i++)
    {
        sc=0;
        for(int j=0;j<it;j++)
            if(isSubset(items[j],t[i],countItems(items[j]),countItems(t[i])))
                sc++;
        c3[i][0]=to_string(sc);
        if(sc>=minSC)
            l3[a][0]=to_string(sc);
        for(int j=0;t[i][j]!="";j++)
        {
            c3[i][j+1]=t[i][j];
            if(sc>=minSC)
                l3[a][j+1]=t[i][j];
        }
        if(sc>=minSC)
            a++;
    }
    cout<<"\nL3\nItem Set\tSupport Count\n";
    for(int i=0,j=0;l3[i][j]!="";i++)
    {
        for (j=1;j<4;j++)
            cout<<l3[i][j]<<" ";
        cout<<"\t\t "<<l3[i][0]<<"\n";
        j=0;
    }

    //Generation of association rules
    cout<<"\n\nAssociation rules are\n  Rule\t\tConfidence\n";
    string a1[50][5]={""},b1[50][5]={""};
    int w=0,x1=0,y=0,q=0;       //q->total no of rules
    for(int i=0;i<a;i++)        //Generating LHS and RHS of rules from frequent item sets
    {
        for(int j=1;j<4;j++)
        {
            y=0;
            a1[w][0]=l3[i][j];
            for(int k=1;k<4;k++)
            {
                if(l3[i][j]!=l3[i][k])
                    b1[w][y++]=l3[i][k];
            }
            w++;
            for(int j=0;b1[w-1][j]!="";j++)
                a1[w][j]=b1[w-1][j];
            for(int j=0;a1[w-1][j]!="";j++)
                b1[w][j]=a1[w-1][j];
            w++;
            q+=2;
        }
    }
    for(int i=0;i<q;i++)        //Display all rules and confidence
    {
        int lhs,rhs,p=0;        //stores no of items on lhs and rhs
        string temp[50]={""};   //stores union of lhs and rhs
        for(lhs=0;a1[i][lhs]!="";lhs++)
        {
            cout<<a1[i][lhs]<<" ";
            temp[p++]=a1[i][lhs];
        }
        cout<<"-> ";
        for(rhs=0;b1[i][rhs]!="";rhs++)
        {
            cout<<b1[i][rhs]<<" ";
            temp[p++]=b1[i][rhs];
        }
        float conf,num=0,den=0;
        for(int j=0;l3[j][0]!="";j++)   //finding support count of numerator
            if(isSubset(l3[j],temp,4,p))
                num=stoi(l3[j][0]);         //stoi() converts string to int
        //finding support count of denominator
        if(lhs==1)
            for(int j=0;l1[j][0]!="";j++)
                if(isSubset(l1[j],a1[i],2,lhs))
                    den=stoi(l1[j][0]);
        if(lhs==2)
            for(int j=0;l2[j][0]!="";j++)
                if(isSubset(l2[j],a1[i],3,lhs))
                    den=stoi(l2[j][0]);
        conf=num/den*100;
        cout<<setprecision(2)<<fixed<<"\t"<<conf<<" %  \t=> ";
        if(conf>=minC)
            cout<<"STRONG RULE";
        else
            cout<<"WEAK RULE";
        cout<<endl;
    }
    return 0;
}
/*Tested Inputs
9
I1 I2 I5
I2 I4
I2 I3
I1 I2 I4
I1 I3
I2 I3
I1 I3
I1 I2 I3 I5
I1 I2 I3
2 70

10
a d e
a b c e
a b d e
a c d e
b c e
b d e
c d
a b c
a d e
a b e
3 80
*/
