#include <iostream>
using namespace std;

class human
{
public:
    string Name;
    int Age;

private:
    int SalaryInJob1 = 2375;
    int SalaryInJob2 = 3420;
    float SalaryInJob3 = 3657.5;
    int SalaryInBestJob = 3657.5;
};
class alian
{
public:
    string Name;
    int Age;

private:
    int SalaryInJob1 = 2700;
    int SalaryInJob2 = 2800;
    int SalaryInJob3 = 2600;
    int SalaryInBestJob = 2800;
};
void buy(int a)
{
    if (a <= 6457.5)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
void GetBest()
{
    cout << "Job3" << endl;
    cout << "Job2";
}
int main()
{
    int price;
    cin >> price;
    buy(price);
    GetBest();
    return 0;
}