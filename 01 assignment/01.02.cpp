#include <iostream>
#include <string>
using namespace std;

class Article
{
public:
    string ArticleName;
    string AuthorName;
    string ArticleContext;
    int ArticleYear;
    void SetArticleName(string n)
    {
        ArticleName = n;
    }
    void SetAuthorName(string n)
    {
        AuthorName = n;
    }
    void SetYear(int n)
    {
        ArticleYear = n;
    }
    void SetContext(string n)
    {
        ArticleContext = n;
    }
    string GetArticleName()
    {
        return ArticleName;
    }
    string GetAuthorName()
    {
        return AuthorName;
    }
    int GetYear()
    {
        return ArticleYear;
    }
    string GetContext()
    {
        return ArticleContext;
    }

private:
    bool ValidateArticleName()
    {
        return ArticleName.length() <= 30;
    }
    bool ValidateAuthorName()
    {
        return AuthorName.length() <= 30;
    }
    bool ValidateYear()
    {
        return ArticleYear > 999 and ArticleYear < 10000;
    }
    bool ValidateContext()
    {
        return ArticleContext.length() <= 500;
    }
};

int main()
{
}