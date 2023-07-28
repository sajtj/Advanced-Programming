#include <iostream>
#include <vector>
#include <string>
using namespace std;

int index = 0;
class student;

class cs
{

public:
    vector<student *> stu;
    vector<float> nomre;
    vector<string> esm;
    void sort();
    void showstu();
    void top3();
    void mashrot();
    void avragekoll();
    void hazfmashrot();

private:
    void addstu(student *s)
    {
        stu.push_back(s);
    }
    friend class student;
};

class student
{
    friend class cs;

public:
    string Name;
    int StuNumber;
    vector<float> score;
    student(string a, int b, vector<float> c, cs &s)
    {
        Name = a;
        StuNumber = b;
        score = c;

        s.addstu(this);
    }
};

void cs::sort()
{
    float n;
    string e;
    if (index > 0)
    {
        goto R;
    }
    for (int i = 0; i < stu.size(); i++)
    {
        float a = 0;
        for (int j = 0; j < stu[i]->score.size(); j++)
        {
            a = a + stu[i]->score[j];
        }
        n = a / stu[i]->score.size();
        nomre.push_back(n);
        e = stu[i]->Name;
        esm.push_back(e);
    }
R:
    for (int i = 0; i < nomre.size(); i++)
    {
        for (int j = i + 1; j < nomre.size(); j++)
        {
            if (nomre[i] > nomre[j])
            {
                swap(nomre[i], nomre[j]);
                swap(esm[i], esm[j]);
            }
        }
    }
}

void cs::showstu()
{
    sort();
    index++;
    for (int i = 0; i < esm.size(); i++)
    {
        cout << esm[i] << endl;
    }
}
void cs::top3()
{
    sort();
    index++;
    for (int i = esm.size() - 1; i > esm.size() - 4; i--)
    {
        cout << esm[i] << endl;
    }
}
void cs::mashrot()
{
    sort();
    index++;
    for (int i = 0; i < nomre.size(); i++)
    {
        if (nomre[i] < 12)
        {
            cout << esm[i] << endl;
        }
    }
}
void cs::avragekoll()
{
    sort();
    index++;
    float a;
    float avr;
    for (int i = 0; i < nomre.size(); i++)
    {
        a = a + nomre[i];
    }
    avr = a / nomre.size();
    cout << avr << endl;
}
void cs::hazfmashrot()
{
    sort();
    index++;
    vector<string> newesm;
    vector<float> newnomre;
    for (int i = esm.size() - 1; i > 0; i--)
    {
        newesm.push_back(esm[i]);
        newnomre.push_back(nomre[i]);
    }
    for (int i = 0; i < esm.size(); i++)
    {
        if (newnomre[i] < 12)
        {
            newesm.pop_back();
            newnomre.pop_back();
        }
    }
    for (int i = 0; i < newesm.size(); i++)
    {
        cout << newesm[i] << "  " << newnomre[i] << endl;
    }
}

int main()
{
    cs c401;
    student s1("sajad tajik", 401442139, {15, 17, 10, 14, 12}, c401);
    student s2("ali habibi", 401442138, {17, 18, 13, 14.4, 19.75}, c401);
    student s3("hasan seyedi", 401442137, {16, 15.5, 11.25, 20, 17.75}, c401);
    student s4("hosein azimi", 401442136, {12, 13.5, 13.25, 11, 10.75}, c401);
    student s5("ehsan nik", 401442135, {11, 10, 5, 13, 7, 8, 12}, c401);

    char a = 'y';
    int op;
    while (a == 'y')
    {
        cout << "which one do you want? (please enter the number of the options)" << endl
             << "1) member of the class(all students)." << endl
             << "2) top 3 students." << endl
             << "3) mashroot students." << endl
             << "4) delete mashroot students." << endl
             << "5) moadel kolle class." << endl;
        cin >> op;
        if (op == 1)
        {
            c401.showstu();
        }
        else if (op == 2)
        {
            c401.top3();
        }
        else if (op == 3)
        {
            c401.mashrot();
        }
        else if (op == 4)
        {
            c401.hazfmashrot();
        }
        else if (op == 5)
        {
            c401.avragekoll();
        }
        
        cout << "wanna continue? (y / n)" << endl;
        cin >> a;
             
    }
}