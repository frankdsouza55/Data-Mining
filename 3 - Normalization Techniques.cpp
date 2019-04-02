#include<iostream>
#include<math.h>
#include<cmath>
#include<iomanip>
#include<climits>
using namespace std;
int main()
{
    int n;
    float mean=0,sd=0,data[500],min1=INT_MAX,min2,max1=INT_MIN,max2;
    cout<<"Enter no of elements in dataset: ";
    cin>>n;
    cout<<"\nEnter the data points\n";
    for(int i=0;i<n;i++)
    {
        cin>>data[i];
        mean+=data[i];
        if(data[i]>max1)
            max1=data[i];
        if(data[i]<min1)
            min1=data[i];
    }
    mean/=n;
    for(int i=0;i<n;i++)
        sd+=(data[i]-mean)*(data[i]-mean);
    sd=sqrt(sd/n);
    cout<<"\nMean = "<<mean<<"\nStd Dev = "<<sd;

    //Z Score Normalization
    cout<<"\nUsing Z Score Normalization\n\tOld value\tNew Value\n";
    for(int i=0;i<n;i++)
        cout<<"\t "<<noshowpos<<data[i]<<"\t\t "<<setprecision(4)<<showpos<<(data[i]-mean)/sd<<endl;

    //Min-Max Normalization
    cout<<"\n\nEnter new min and new max: ";
    cin>>min2>>max2;
    cout<<"Using Min-Max Normalization\n\tOld value\tNew Value\n";
    for(int i=0;i<n;i++)
        cout<<"\t "<<noshowpos<<data[i]<<"\t\t "<<setprecision(4)<<showpos<<(data[i]-min1)*(max2-min2)/(max1-min1)+min2<<endl;

    //Decimal Scaling
    int f=round(log10(max1));
    cout<<"\nf = "<<f;
    cout<<"\nUsing Decimal Scaling\n\tOld value\tNew Value\n"<<noshowpos;
    for(int i=0;i<n;i++)
        cout<<"\t "<<data[i]<<"\t\t "<<setprecision(4)<<data[i]/pow(10,f)<<endl;
    return 0;
}
/*input
13
24 29 31 32 32 32 37 42 42 44 44 64 68
-2 8

12
150 70 200 120 800 650 700 240 360 310 650 200
-3 5

5
200 300 400 600 1000
0 1
*/
