#include<iostream>
using namespace std;

struct process
{
    int id,at,bt,wt,ct,tat,rt;
};
    int tt = 0;
    void robin(process processes[], int n,int ts)
    {
         for (int i = 0; i < n - 1; i++)
    {
        if(processes[i].ct%ts==0)
        {
            processes[i].bt=processes[i].bt-ts;
        }
        else if(processes[i].ct%ts==processes[i].ct)
        {
            continue;
        }
    }
    }
    void rem_burst_time(int arr[],process processes[],n)
    {
        for(i=0;i<n;i++)
        {
            arr[i]=processes[i].bt;
        }
    }
    cout << "Process\tBurst Time\tWaiting Time\tTurnAroundTime\tCompletion Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << processes[i].id << "\t" << processes[i].bt << "\t\t";
        int wt = tt;
        processes[i].wt = wt;
        cout << wt << "\t\t";
        int tat = wt + processes[i].bt;
        processes[i].tat = tat;
        cout << tat << "\t\t";
        int ct = tt + processes[i].bt;
        processes[i].ct = ct;
        cout << ct << endl;
        tt += processes[i].bt;
        int rt=tt-processes[i].
    }
int main()
{
    int n,ts;
    cout <<"Enter The Number of Processes Being Scheduled:";
    cin >> n;
    process processes[n];
    cout<<"Enter The Time Slice:  ";
    cin>>ts;

    cout << "\nEnter Burst time of The Processes Below:\n";
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        cout << "Enter Process " << i + 1 << " Burst Time:";
        cin>>processes[i].bt;
        processes[i].wt= 0;
        processes[i].tat = 0;
        processes[i].ct = 0;
    }
    robin(processes[],n,ts);
    return 0;
}
