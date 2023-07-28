#include <iostream>
#include <random>
using namespace std;

class Acount1
{
private:
    double ac1price = 0;

public:
    void addac1prc(float x)
    {
        ac1price = ac1price + x;
    }
    void subac1prc(float x)
    {
        ac1price = ac1price - x;
    }
    void showprc()
    {
        cout << ac1price << " ";
    }
    float setprice()
    {
        return ac1price;
    }
    void empty()
    {
        ac1price = 0;
    }
};
class Acount2
{
private:
    double ac2price = 0;

public:
    void addac2prc(float x)
    {
        ac2price = ac2price + x;
    }
    void subac2prc(float x)
    {
        ac2price = ac2price - x;
    }
    void showprc()
    {
        cout << ac2price << " ";
    }
    float setprice()
    {
        return ac2price;
    }
    void empty()
    {
        ac2price = 0;
    }
};
class subAcount
{
    friend Acount1;
    friend Acount2;

private:
    double firstprice = 1000000;

public:
    void addsubAcprc(float x)
    {
        firstprice = firstprice + x;
    }
    void subsubAcprc(float x)
    {
        firstprice = firstprice - x;
    }
    float setprice()
    {
        return firstprice;
    }
    void showprc()
    {
        cout << firstprice << endl;
    }
};

void playac1(float inv, float a, float b, Acount1 &obj1, Acount2 &obj2, subAcount &objs)
{
    float r = 1;
    float s;
    float ns = 0;
    while (r >= 1)
    {
        r = a + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / b);
        s = inv * r;
        float ns;
        if (r >= 1)
        {
            ns = s / 2;
            obj1.addac1prc(ns);
            objs.addsubAcprc(ns);
            obj1.showprc();
            obj2.showprc();
            objs.showprc();
            if (objs.setprice() >= 2000000 or objs.setprice() == 0)
            {
                break;
            }
        }
        else
        {
            float t;
            float q;
            t = inv - s;
            objs.subsubAcprc(t);
            if (obj1.setprice() >= t)
            {
                obj1.subac1prc(t);
                obj2.addac2prc(t);
            }
            else if (obj1.setprice() < t and obj1.setprice() >= 0)
            {
                q = obj1.setprice();
                obj2.addac2prc(q);
                obj1.empty();
            }

            obj1.showprc();
            obj2.showprc();
            objs.showprc();
        }
    }
}
void playac2(float inv, float a, float b, Acount1 &obj1, Acount2 &obj2, subAcount &objs)
{
    float r = 1;
    float s;
    float ns = 0;
    while (r >= 1)
    {
        r = a + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / b);
        s = inv * r;
        float ns;
        if (r >= 1)
        {
            ns = s / 2;
            obj2.addac2prc(ns);
            objs.addsubAcprc(ns);
            obj1.showprc();
            obj2.showprc();
            objs.showprc();
            if (objs.setprice() >= 2000000 or objs.setprice() == 0)
            {
                break;
            }
        }
        else
        {
            float t;
            float q;
            t = inv - s;
            objs.subsubAcprc(t);
            if (obj2.setprice() >= t)
            {
                obj2.subac2prc(t);
                obj1.addac1prc(t);
            }
            else if (obj2.setprice() < t and obj2.setprice() >= 0)
            {
                q = obj2.setprice();
                obj1.addac1prc(q);
                obj2.empty();
            }

            obj1.showprc();
            obj2.showprc();
            objs.showprc();
        }
    }
}
float investigation()
{
    float k = 0;
    while (k == 0)
    {
        float r;
        r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        string rs = to_string(r);
        string rs1 = "";
        for (int i = 0; i < 4; i++)
        {
            rs1 = rs1 + rs[i];
        }
        float r1 = stof(rs1);
        k = r1;
    }
    return k;
}
int main()
{
    srand(time(NULL));
    float a;
    float b;
    cin >> a >> b;
    Acount1 obj1;
    Acount2 obj2;
    subAcount objs;
    int index = 2;
R:
    float c = objs.setprice();
    float inv = 0;
    if (c < 10000)
    {
        goto R1;
    }
    while (inv <= 10000)
    {
        float t;
        t = investigation();
        inv = t * c;
    }
    while (c <= 2000000 and c != 0)
    {

        if (index % 2 == 0)
        {
            playac1(inv, a, b, obj1, obj2, objs);
            index++;
        }
        else
        {
            playac2(inv, a, b, obj1, obj2, objs);
            index++;
        }
        inv = 0;
        goto R;
    }
R1:
    if (obj1.setprice() > obj2.setprice())
    {
        cout << "FIRST ACOUNT WIN";
    }
    else
    {
        cout << "SECOND ACOUNT WIN";
    }

    return 0;
}