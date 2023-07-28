#include <iostream>
#include <vector>
using namespace std;

class Queue
{
public:
    vector<int> q;
    void push(int a)
    {
        if (q.size() < 100)
        {
            q.push_back(a);
        }
        else
        {
            cout << "you can't push it  is full" << endl;
        }
    }
    void pop()
    {
        int a;
        a = q[0];
        cout << a << endl;
        q.erase(q.begin());
    }
    void size()
    {
        cout << q.size() << endl;
    }
    void reverse()
    {
        int x;
        vector<int> help;
        for (int i = q.size() - 1; i >= 0; i--)
        {
            x = q[i];
            help.push_back(x);
        }
        q.clear();
        for (int i = 0; i < help.size(); i++)
        {
            x = help[i];
            q.push_back(x);
        }
    }
    void find(int a)
    {
        int index = 0;
        for (int i = 0; i < q.size(); i++)
        {
            if (a == q[i])
            {
                cout << i + 1 << endl;
                index++;
                break;
            }
        }
        if (index == 0)
        {
            cout << -1 << endl;
        }
    }
    void isfull()
    {
        if (q.size() == 100)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
    void isempty()
    {
        if (q.size() == 0)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
};
int main()
{
    Queue qu;
    string s;
    while (s != "exit")
    {
        getline(cin, s);
        string str;
        for (int i = 0; i < 4; i++)
        {
            str = str + s[i];
        }
        if (str == "push")
        {
            string str1;
            for (int i = str.size() + 1; i < s.size(); i++)
            {
                str1 = str1 + s[i];
            }
            int x = stoi(str1);
            qu.push(x);
        }
        else if (s == "pop")
        {
            qu.pop();
        }
        else if (s == "size")
        {
            qu.size();
        }
        else if (s == "reverse")
        {
            qu.reverse();
        }
        else if (str == "find")
        {
            string str2;
            for (int i = str.size() + 1; i < s.size(); i++)
            {
                str2 = str2 + s[i];
            }
            int x = stoi(str2);
            qu.find(x);
        }
        else if (s == "isfull")
        {
            qu.isfull();
        }
        else if (s == "isempty")
        {
            qu.isempty();
        }
    }
}