#include <vector>
#include "stuff.h"

void ShellSort(std::vector<Stuff> &s, int code)
{
    if (code < 0 || code > 4)
        exit(1);

    std::vector<int> hlist;
    int n = s.size();

    if (code == 0)
        hlist.push_back(1);
    else if (code == 1)
        for (int k = 1; k * k < n; k++)
        {
            hlist.insert(hlist.begin(), k * k);
        }
    else if (code == 2)
    {
        for (int k = 0; (1 << k) < n; k++)
        {
            hlist.insert(hlist.begin(), (1 << k));
        }
    }
    else if (code == 3)
    {
        for (int k = 0; ((1 << k) - 1) < n; k++)
        {
            hlist.insert(hlist.begin(), (1 << k) - 1);
        }
    }
    else if (code == 4)
    {

        for (int k = 0; (pow(4, (k + 1)) + 3 * (1 << k) + 1) < n; k++)
        {
            hlist.insert(hlist.begin(), pow(4, (k + 1)) + 3 * (1 << k) + 1);
        }
        if (n <= 8)
        {
            hlist.clear();
            hlist.push_back(1);
        }
    }

    for (int i : hlist)
    {
        for (int j = i; j < n; j++)
        {
            Stuff temp = s[j];
            int k;
            for (k = j; k >= i && s[k - i] < temp; k -= i)
            {
                s[k] = s[k - i];
            }
            s[k] = temp;
        }
    }
};