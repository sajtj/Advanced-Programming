#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
    int a;
    int b;
    int c;
    Point(int x, int y, int z)
    {
        a = x;
        b = y;
        c = z;
    }
    void norm()
    {
        double D = (a * a) + (b * b) + (c * c);
        D = sqrt(D);
        cout.precision(2);
        cout << "1. Distance of (0,0,0) is " << fixed << D << endl;
    }
    void nagative()
    {
        int a1 = -1 * a;
        int b1 = -1 * b;
        int c1 = -1 * c;
        cout << "2. negative is : (" << a1 << "," << b1 << "," << c1 << ")" << endl;
    }
};
int main()
{
    string s;
    getline(cin, s);
    string s1;
    string s2[3];
    int t = 0;
    for (int i = 12; i < s.size(); i++)
    {
        if (s[i] == ',' or s[i] == ')')
        {
            s2[t] = s1;
            t = t + 1;
            s1 = "";
            continue;
        }
        s1 = s1 + s[i];
    }

    int x = stoi(s2[0]);
    int y = stoi(s2[1]);
    int z = stoi(s2[2]);
    Point myobj(x, y, z);
    myobj.norm();                                                                       // 1
    myobj.nagative();                                                                   // 2
    cout << "3. p1 is :  (" << x * -1 << ',' << y * -1 << ',' << z * -1 << ')' << endl; // 3
    int p1[3] = {x * -1, y * -1, z * -1};
    int p2[3] = {};
    for (int i = 0; i < 3; i++)
    {
        int a;
        cin >> a;
        p2[i] = p2[i] + a;
    }
    int sum[3] = {p1[0] + p2[0], p1[1] + p2[1], p1[2] + p2[2]};
    cout << "4. p1 + " << "(" << p2[0] << "," << p2[1] << "," << p2[2] << ')' << " is : (" << sum[0] << "," << sum[1] << "," << sum[2] << ")";
    return 0;
}