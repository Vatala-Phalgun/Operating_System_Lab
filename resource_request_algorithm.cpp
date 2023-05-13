#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the number of resources: ";
    cin >> m;

    int alloc[n][m], max[n][m], avail[m], need[n][m];

    cout << "Enter the allocation matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> alloc[i][j];
        }
    }

    cout << "Enter the maximum matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> max[i][j];
        }
    }

    cout << "Enter the available matrix: " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> avail[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int work[m];
    for (int i = 0; i < m; i++)
    {
        work[i] = avail[i];
    }

    bool finish[n];
    for (int i = 0; i < n; i++)
    {
        finish[i] = false;
    }

    int safe_seq[n], count = 0;

    int request[m];
    cout << "Enter the request matrix: " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> request[i];
    }

    for (int i = 0; i < m; i++)
    {
        if (request[i] > need[0][i] || request[i] > avail[i])
        {
            cout << "Request cannot be approved" << endl;
            return 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        avail[i] -= request[i];
        alloc[0][i] += request[i];
        need[0][i] -= request[i];
    }

    while (count < n)
    {
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (finish[i] == false)
            {
                int j;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        break;
                    }
                }
                if (j == m)
                {
                    for (int k = 0; k < m; k++)
                    {
                        work[k] += alloc[i][k];
                    }
                    safe_seq[count++] = i;
                    finish[i] = true;
                    flag = true;
                }
            }
        }
        if (flag == false)
        {
            break;
        }
    }

    if (count == n)
    {
        cout << "Safe Sequence: ";
        for (int i = 0; i < n - 1; i++)
        {
            cout << "P" << safe_seq[i] << " -> ";
        }
        cout << "P" << safe_seq[n - 1];
        cout << endl;
    }
    else
    {
        cout << "System is in unsafe state" << endl;
    }
    return 0;
}