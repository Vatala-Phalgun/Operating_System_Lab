#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the No.of Pages:";
    cin>>n;
    int pages[n];

    cout<<"Enter the Page Numbers:";
    for(int i=0;i<n;i++)
    {
        cin>>pages[i];
    }

    int size;
    cout<<"Enter the Capacity of Frames: ";
    cin>>size;
    int frame[size];

    for(int i=0;i<size;i++)
    {
        frame[i]=-1;
    }
    
    int pg_fault=0,index=0;
    for(int i=0;i<n;i++)
    {
        bool flag=false;
        for(int j=0;j<size;j++)
        {
            if(frame[j]==pages[i])
            {
                flag=true;
                break;
            }
        }
         if(!flag)
        {
            frame[index]=pages[i];
            index=(index+1)%size;
            pg_fault++;
        }
    }
    
    cout<<"The No. of Page Faults that have Occured are: "<<pg_fault;
    return 0;
}