#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of pages: ";
    cin >> n;

    int pages[n];
    cout << "Enter the page numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }

    int size;
    cout << "Enter the Size of the Frames: ";
    cin >> size;

    int frame[size];
    for (int i = 0; i < size; i++)
    {
        frame[i] = -1;
    }

    int pg_fault = 0;
    int index = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < size; j++)
        {
            if (frame[j] == pages[i])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            if (count < size)
            {
                frame[index] = pages[i];
                index = (index + 1) % size;
                count++;
            }
            else
            {
                int temp[size];
                for (int j = 0; j < size; j++)
                {
                    temp[j] = -1;
                }
                int k = 0;
                for (int j = i - 1; j >= 0; j--)
                {
                    bool flag = false;
                    for (int l = 0; l < size; l++)
                    {
                        if (temp[l] == pages[j])
                        {
                            flag = true;
                            break;
                        }
                    }
                    if (!flag)
                    {
                        temp[k] = pages[j];
                        k++;
                    }
                    if (k == size)
                    {
                        break;
                    }
                }
                for (int j = 0; j < size; j++)
                {
                    if (frame[j] == temp[size - 1])
                    {
                        frame[j] = pages[i];
                        break;
                    }
                }
            }
            pg_fault++;
        }
    }
    cout << "Number of page faults: " << pg_fault << endl;    
}