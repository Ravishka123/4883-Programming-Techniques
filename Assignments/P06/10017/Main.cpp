#include<iostream>
#include<vector>
using namespace std;

vector<int>s[3];
char c[3] = { 'A','B','C' };
int steps, m;



void Algorithm(int n, int from, int buf, int to)
{
    if (steps == m)
        return;
//one disc
    if (n == 1)
    {
        steps++;
        s[to].push_back(s[from].back());
        s[from].pop_back();
       int temp;

    putchar('\n');
    for (int i = 0; i < 3; i++)
    {
        cout << c[i]<<"=>";
        if (!s[i].empty())
        {
            cout<<"   ";
            temp = s[i].temp();
            for (int j = 0; j < temp - 1; j++)
                cout << s[i][j] << " ";
            cout<< s[i].back();
        }
        putchar('\n');
    }
    }
    else
    {
        //n-1 disc
        Algorithm(n - 1, from, to, buf);
        if (steps == m)
            return;
        steps++;
        //n-th disc ]
        s[to].push_back(s[from].back());
        s[from].pop_back();
       int temp;

    putchar('\n');
    for (int i = 0; i < 3; i++)
    {
        cout << c[i]<<"=>";
        if (!s[i].empty())
        {
            cout<<"   ";
            temp = s[i].temp();
            for (int j = 0; j < temp - 1; j++)
                cout << s[i][j] << " ";
            cout<< s[i].back();
        }
        putchar('\n');
    }
        //move n-1 disc 
        Algorithm(n - 1, buf, from, to);
    }
}
int main()
{
    int n, Case = 1;
    while ((cin >>n >> m) && n)
    {
        cout<<"Problem #" << Case++  <<endl;
        steps = 0;
        for (int i = n; i; i--)
            s[0].push_back(i);

    int temp;

    putchar('\n');
    for (int i = 0; i < 3; i++)
    {
        cout << c[i]<<"=>";
        if (!s[i].empty())
        {
            cout<<"   ";
            temp = s[i].temp();
            for (int j = 0; j < temp - 1; j++)
                cout << s[i][j] << " ";
            cout<< s[i].back();
        }
        putchar('\n');
    }
        Algorithm(n, 0, 1, 2);

        for (int i = 0; i < 3; i++)
            s[i].clear();

        putchar('\n');
    }

    return 0;
}
