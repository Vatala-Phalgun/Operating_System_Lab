#include <iostream>
using namespace std;

struct queue
{
    int id, at, bt, wt, ct, tat;
    queue *next;
};

class FCFS
{
private:
    queue *front;
    queue *rear;

public:
    FCFS()
    {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    queue addnode(int id, int at, int bt)
    {
        queue *q = new queue;
        q->id = id;
        q->at = at;
        q->bt = bt;
        q->ct = 0;
        q->wt = 0;
        q->tat = 0;
        q->next = NULL;
        if (isEmpty())
        {
            front = q;
            rear = q;
        }
        else
        {
            rear->next = q;
            rear = q;
        }
    }

    queue deletenode()
    {
        queue queue;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            queue.id = -1;
            return queue;
        }
        else
        {
            queue = *front;
            front = front->next;
            if (front == NULL)
            {
                rear = NULL;
            }
            return queue;
        }
    }
};

int main()
{
    int n,i;
    cout << "Enter The No. of Processes being Scheduled: " << endl;
    cin>>n;
    FCFS obj;
    for (i = 0;i<n;i++)
    {
        int id, at, bt;
        cout << "Enter the Process ID: " << endl;
        cin >> id;
        cout << "Enter the Arrival Time: " << endl;
        cin >> at;
        cout << "Enter The Burst Time: " << endl;
        cin >> bt;
        obj.addnode(id,at,bt);
    }
    int ct= 0;
    while (!obj.isEmpty())
    {
        queue d = obj.deletenode();
        d.wt = ct- d.at;
        d.ct = ct + d.bt;
        d.tat = d.ct - d.at;
        cout << "Process\tWait time\tCompletion time\tTurn around time" << endl;
        cout << d.id <<"\t\t" << d.wt << "\t\t" << d.ct << "\t\t" << d.tat<< endl;
        ct = d.ct;
    }
    return 0;
}
