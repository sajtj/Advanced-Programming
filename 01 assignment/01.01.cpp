#include <iostream>
using namespace std;

int CtoR0(string a)
{
    string y = "";
    int x;
    for (int i = 0; i < a.length(); i++)
    {
        if ((a[i] == '-' or a[i] == '+') and i != 0)
        {
            break;
        }
        y = y + a[i];
    }

    x = stoi(y);
    return x;
}
int CtoR2(string a)
{
    string y = "";
    int x;
    for (int i = 0; i < a.length(); i++)
    {
        if ((a[i] == '-' or a[i] == '+') and i != 0)
        {
            y = y + a[i];
            for (int j = i + 1; j < a.length(); j++)
            {
                if (a[j] == 'i' and j == i + 1)
                {
                    y = y + "1";
                    break;
                }
                else
                {
                    if (a[j] == 'i')
                    {
                        break;
                    }
                    y = y + a[j];
                }
            }
        }
    }
    x = stoi(y);
    return x;
}

class Cnumber
{
public:
    string add(string a, string b)
    {
        int c = CtoR0(a);
        int z = CtoR2(a);
        int c1 = CtoR0(b);
        int z1 = CtoR2(b);
        int add;
        int add0;
        int add1;
        string adds0;
        string adds1;
        string adds;
        add0 = c + c1;
        adds0 = to_string(add0);
        add1 = z + z1;
        adds1 = to_string(add1);
        if (add1 < 0)
        {
            adds = adds0 + adds1 + "i";
            return adds;
        }
        else
        {
            adds = adds0 + "+" + adds1 + "i";
            return adds;
        }
    }
    string subtract(string a, string b)
    {
        int c = CtoR0(a);
        int z = CtoR2(a);
        int c1 = CtoR0(b);
        int z1 = CtoR2(b);
        int sub;
        int sub0;
        int sub1;
        string subs0;
        string subs1;
        string subs;
        int index;
        sub0 = c - c1;
        subs0 = to_string(sub0);
        sub1 = z - z1;
        subs1 = to_string(sub1);
        if (stoi(subs1) < 0)
        {
            subs = subs0 + subs1 + "i";
            return subs;
        }
        else
        {
            subs = subs0 + "+" + subs1 + "i";
            return subs;
        }
    }
    string multply(string a, string b)
    {
        int a1 = CtoR0(a);
        int b1 = CtoR2(a);
        int a2 = CtoR0(b);
        int b2 = CtoR2(b);
        int mltply0 = (a1 * a2) - (b1 * b2);
        string mltplys0 = to_string(mltply0);
        int mltply1 = (a1 * b2) + (a2 * b1);
        string mltplys1 = to_string(mltply1);
        string mltplys;
        if (mltply1 < 0)
        {
            mltplys = mltplys0 + mltplys1 + "i";
            return mltplys;
        }
        else
        {
            mltplys = mltplys0 + "+" + mltplys1 + "i";
            return mltplys;
        }
    }
    string conjugate(string a)
    {
        int a1 = CtoR0(a);
        int b1 = CtoR2(a) * -1;
        string a1s = to_string(a1);
        string b1s = to_string(b1);
        string z;
        if (b1 < 0)
        {
            if (b1 == -1)
            {
                z = a1s + "-" + "i";
                return z;
            }
            else
            {
                z = a1s + b1s + "i";
                return z;
            }
        }
        else
        {
            if (b1 == 1)
            {
                z = a1s + "+" + "i";
                return z;
            }
            else
            {
                z = a1s + "+" + b1s + "i";
                return z;
            }
        }
    }
    string divide(string a, string b) // it only works when [ da and db (= z ] , otherwise it returns 0. ["(=" means عضو]
    {
        string bc = conjugate(b);
        string as = multply(a, bc);
        string bs = multply(b, bc);
        int a1 = CtoR0(as);
        int a2 = CtoR2(as);
        int b1 = CtoR0(bs);
        int da = a1 / b1;
        string sda = to_string(da);
        int db = a2 / b1;
        string sdb = to_string(db);
        string d;
        if (db < 0)
        {
            d = sda + sdb + "i";
            return d;
        }
        else
        {
            d = sda + "+" + sdb + "i";
            return d;
        }
    }
    void disply(int a)
    {
        if (a == 1)
        {
            string a;
            string b;
            cin >> a >> b;
            cout << add(a, b) << endl;
        }
        else if (a == 2)
        {
            string a;
            string b;
            cin >> a >> b;
            cout << subtract(a, b) << endl;
        }
        else if (a == 3)
        {
            string a;
            string b;
            cin >> a >> b;
            cout << multply(a, b) << endl;
        }
        else if (a == 4)
        {
            string a;
            string b;
            cin >> a >> b;
            cout << divide(a, b) << endl;
        }
        else if (a == 5)
        {
            string a;
            cin >> a;
            cout << conjugate(a) << endl;
        }
    }
};

int main()
{
    Cnumber myobj;
    int x;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        int y;
        cin >> y;
        myobj.disply(y);
    }
}