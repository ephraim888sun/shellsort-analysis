#include <vector>
#include "stuff.h"

void ShellSort(vector<Stuff> &s, int code) {
    if (code < 0 || code > 4) {
        cout << "Error: Invalid code. Code must be between 0 and 4." << endl;
        exit(1);
    }

    int n = s.size();
    vector<int> hlist;

    if (code == 0)
    {
        hlist.push_back(1);
    }
    else if (code == 1)
    {
        int k = 1;
        while (k * k < n)
        {
            hlist.push_back(k * k);
            k++;
        }
    }
    else if (code == 2)
    {
        int k = 1;
        while (pow(2, k) < n)
        {
            hlist.push_back(pow(2, k));
            k++;
        }
    }
    else if (code == 3)
    {
        int k = 1;
        while (pow(2, k) - 1 < n)
        {
            hlist.push_back(pow(2, k) - 1);
            k++;
        }
    }
    else if (code == 4)
    {
        int k = 0;
        while (4 * pow(2, k + 1) + 3 * pow(2, k) + 1 < n)
        {
            k++;
        }
        if (k > 0)
        {
            for (int i = k; i >= 0; i--)
            {
                hlist.push_back(4 * pow(2, i + 1) + 3 * pow(2, i) + 1);
            }
        }
        else
        {
            hlist.push_back(1);
        }
    }

    for (int h : hlist)
    {
        for (int i = h; i < n; i++)
        {
            Stuff temp = s[i];
            int j = i;
            while (j >= h && s[j - h] < temp)
            {
                s[j] = s[j - h];
                j -= h;
            }
            s[j] = temp;
        }
    }
};