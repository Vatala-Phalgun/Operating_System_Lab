#include <bits/stdc++.h>
using namespace std;

struct process
{
    int id, at, bt, ct, wt, tat, p, rem;
};

bool compare(process p1, process p2)
{
    return p1.at < p2.at;
}

void pp(process processes[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (compare(processes[j],processes[min]))
            {
                min = j;
            }
        }
        swap(processes[min],processes[i]);
    }

    int t = 0;
    for (int i = 0; i < n; i++)
    {
        t +=processes[i].bt;
    }

    int cur_time = 0;
    while (cur_time <= t)
    {
        int highest_p_idx = -1;
        int highest_p = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (processes[i].at <= cur_time && processes[i].rem > 0 && processes[i].p < highest_p)
            {
                highest_p_idx = i;
                highest_p =processes[i].p;
            }
        }

        if (highest_p_idx == -1)
        {
            cur_time++;
            continue;
        }

       processes[highest_p_idx].rem--;

        if (processes[highest_p_idx].rem == 0)
        {
           processes[highest_p_idx].ct = cur_time + 1;
           processes[highest_p_idx].tat =processes[highest_p_idx].ct -processes[highest_p_idx].at;
           processes[highest_p_idx].wt =processes[highest_p_idx].tat -processes[highest_p_idx].bt;
        }

        cur_time++;
    }
}

int main()
{
    int n;
    cout << "Enter the Number of Processes: ";
    cin >> n;
    process processes[n];

    for (int i = 0; i < n; i++)
    {
       processes[i].id = i + 1;
        cout << "Enter the Arrival Time for Process " << i + 1 << ": ";
        cin >> processes[i].at;

        cout << "Enter the Burst Time for Process " << i + 1 << ": ";
        cin >> processes[i].bt;

       processes[i].ct = 0;
       processes[i].tat = 0;
       processes[i].wt = 0;
       processes[i].rem =processes[i].bt;
       processes[i].p = (rand() % 10) + 1;
    }

    pp(processes,n);
    cout << "\nProcess\tBurst Time\tArrival Time\t\tCompletion Time\tWait Time\tTurn Around Time\t Priority\n";
    for (int i = 0; i < n; i++)
    {
        cout << processes[i].id << "\t\t" <<processes[i].bt<<"\t\t" <<processes[i].at <<"\t\t"<<processes[i].ct << "\t\t" 
        << processes[i].wt << "\t\t" << processes[i].tat <<"\t"<<processes[i].p<< endl;
    }
    return 0;
}

