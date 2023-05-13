#include <iostream>
using namespace std;
struct process
{
    int id;
    int bt;
    int p;
    int wt;
    int tat;
    int ct;
};
void priority(process processes[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (processes[j].p < processes[i].p)
            {
                swap(processes[i], processes[j]);
            }
        }
    }
    int tt = 0;
    cout << "Process\tBurst Time\tPriority\tWaiting Time\tTurnAroundTime\tCompletion Time\n";
        for (int i = 0; i < n; i++)
    {
        cout << processes[i].id << "\t" << processes[i].bt << "\t\t";
        cout << processes[i].p << "\t\t";
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
    }
}
int main()
{
    int n;
    cout << "Enter The Number of Processes Being Scheduled:";
    cin >> n;
    process processes[n];
    cout << "\nEnter Burst time and Priority of the Processes Below:\n";
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        cout << "Enter Process " << i + 1 << " Burst Time:";
        cin >> processes[i].bt;
        cout << "Enter Process " << i + 1 << " Priority:";
        cin >> processes[i].p;
        processes[i].wt= 0;
        processes[i].tat = 0;
        processes[i].ct = 0;
    }
    priority(processes,n);
    return 0;
}