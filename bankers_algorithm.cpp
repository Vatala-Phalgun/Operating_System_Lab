#include <iostream>
using namespace std;
int main()
{
    int n,r,x,i,j;
    cout<<"Enter the Number of Processes: "<<endl;
    cin>>n;
    cout<<"Enter the Number of Resources Allocated: "<<endl;
    cin>>r;
    int allocate[n][r];
    int max[n][r];
    int available[r];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<r;j++)
        {
            cout<<"Enter The Allocation Matrix for "<<i+1<<"th row & "<<j+1<<"th column: "<<endl;
            cin>>allocate[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<r;j++)
        {
            cout<<"Enter The Max Matrix for "<<i+1<<"th row & "<<j+1<<"th column: "<<endl;
            cin>>max[i][j];
        }
    }
    for(int i=0;i<r;i++)
    {
        cout<<"Enter The Available Resources at "<<i+1<<"th Index: "<<endl;
        cin>>available[i];
    }
    int f[n],res[n],ind=0;
    for(x=0;x<n;x++) 
    {
        f[x]=0;
    }
    int needed[n][r];
    for (i=0;i<n;i++)
    {
        for (j=0;j<r;j++)
        {
            needed[i][j]=max[i][j]-allocate[i][j];
        }
    }
    int y=0;
    for(x=0;x<5;x++) 
    {
        for (i=0;i<n;i++)
        {
            if (f[i]==0) 
            {
                int flag=0;
                for(j=0;j<r;j++)
                {
                    if (needed[i][j]>available[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if (flag==0)
                {
                    res[ind++]=i;
                    for(y=0;y<r;y++)
                    {
                        available[y]+=allocate[i][y];
                        f[i]=1;
                    }
                }
            }
        }
    }
int flag=1;
for(int i=0;i<n;i++)
{
    if(f[i]==0)
	{
		flag=0;
		cout<<"The Given Sequence is Not a Safe One";
		break;
	}
}
if(flag==1)
{
	cout <<"This Following is the Safe Sequence: " << endl;
	for (i=0;i<n-1;i++)
    cout<<" P"<<res[i]<< " ->";
	cout<<" P"<<res[n-1]<<endl;
}
return 0;
}
