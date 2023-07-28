#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int item;
    Node *next;
};
class linkedlist
{
private:
    Node *head;

public:
    linkedlist()
    {
        head = NULL;
    }
    void Insertion(int val);
    void Deletion();
    void Display();
    int Search(int val);
    void Delete(int val);
};
void linkedlist::Insertion(int val)
{
    Node *newNode = new Node();
    newNode->item = val;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void linkedlist::Display()
{
    Node *temp = head;
    if (temp != NULL)
    {
        while (temp != NULL)
        {
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
void linkedlist::Deletion()
{
    head = head->next;
}
void linkedlist::Delete(int val)
{
    Node *temp = head;
    Node *pre = NULL;
    while (temp != NULL)
    {
        if (temp->item == val)
        {
            if (pre == NULL)
            {
                head = temp->next;
            }
            else
            {
                pre->next = temp->next;
            }
            delete temp;
            return;
        }
        pre = temp;
        temp = temp->next;
    }
}
int linkedlist::Search(int val)
{
    int i = 0;
    int n;
    Node *temp = head;
    while (temp != NULL)
    {
        n = temp->item;
        temp = temp->next;
        if (n == val)
        {
            return i;
            break;
        }
        i++;
    }
}

int main()
{
    linkedlist l;
    string s;
    int x;
    while (s != "exit")
    {
        getline(cin, s);
        string str_insertion;
        string str_sd;
        if (s.size() >= 9)
        {
            for (int i = 0; i < 9; i++)
            {
                str_insertion = str_insertion + s[i];
            }
        }
        for (int i = 0; i < 6; i++)
        {
            str_sd = str_sd + s[i];
        }
        if (str_insertion == "Insertion")
        {
            string str;
            for (int i = str_insertion.size() + 1; i < s.size(); i++)
            {
                str = str + s[i];
            }
            x = stoi(str);
            l.Insertion(x);
        }
        else if (s == "Display")
        {
            l.Display();
        }
        else if (s == "Deletion")
        {
            l.Deletion();
        }
        else if (str_sd == "Search")
        {
            string str1;
            for (int i = str_sd.size() + 1; i < s.size(); i++)
            {
                str1 = str1 + s[i];
            }
            x = stoi(str1);
            cout << l.Search(x);
            cout << endl;
        }
        else if (str_sd == "Delete")
        {
            string str2;
            for (int i = str_sd.size() + 1; i < s.size(); i++)
            {
                str2 = str2 + s[i];
            }
            x = stoi(str2);
            l.Delete(x);
        }
    }
}