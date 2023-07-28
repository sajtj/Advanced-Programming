#include <iostream>
using namespace std;

char b1;
string a1;
class stack
{
 
public:
    char top(string a)
    {
        char b;
        b = a[a.size() - 1];
        b1 = b;
        return b1;
    }
    string push()
    {
        string s = "";
        s = s + b1;
        return s;
    }
    string pop(string a)
    {
        string st = "";
        for (int i = 0; i < a.size() - 1; i++)
        {
            st = st + a[i];
        }
        return st;
    }
    bool isempty(string a)
    {
        return a.size() == 0;
    }
    bool isfull(string a, string b)
    {
        // a = str3 -> az ghabl malom shode
        // b = str1 -> dar hal sakhte shodan...
        return a.size() == b.size();
    }
};

int main()
{
    stack myobj;
    string str;
    string str1 = ""; /**/
    cin >> str;
    string str3 = str; /**/
    string str2 = str;
    int j = str.size();
    for (int i = 0; i < j; i++)
    {
        str = str2;
        myobj.top(str);
        str1 = str1 + myobj.push();
        str2 = myobj.pop(str);
    }
    if (str3 == str1)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}
