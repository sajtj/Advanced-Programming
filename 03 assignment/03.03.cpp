#include <iostream>
using namespace std;

struct Book
{
    string name;
    Book *next;
};
class changes
{
private:
    Book *books;

public:
    changes()
    {
        books = NULL;
    }
    void Addright(string bookname)
    {
        Book *newBook = new Book;
        newBook->name = bookname;
        newBook->next = NULL;
        if (books == NULL)
        {
            books = newBook;
        }
        else
        {
            Book *temp = books;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newBook;
        }
    }
    void Addleft(string bookname)
    {
        Book *newBook = new Book;
        newBook->name = bookname;
        newBook->next = books;
        books = newBook;
    }
    void Deleteleft()
    {
        books = books->next;
    }
    void show()
    {
        Book *temp = books;
        string b;
        while (temp != NULL)
        {
            b = temp->name;
            cout << b << endl;
            temp = temp->next;
        }
    }
    void booksnumber()
    {
        int index = 0;
        Book *temp = books;
        while (temp != NULL)
        {
            temp = temp->next;
            index++;
        }
        cout << index << endl;
    }
};
int main()
{
    changes c;
    string s;
    string xs;
    getline(cin, xs);
    int x = stoi(xs);
    for (int i = 0; i < x; i++)
    {
        getline(cin, s);
        c.Addright(s);
    }
    while (s != "Exit")
    {
        getline(cin, s);
        if (s == "AddRight")
        {
            string b;
            getline(cin, b);
            c.Addright(b);
        }
        else if (s == "AddLeft")
        {
            string b;
            getline(cin, b);
            c.Addleft(b);
        }
        else if (s == "DeleteLeft")
        {
            c.Deleteleft();
        }
    }
    c.booksnumber();
    c.show();
}