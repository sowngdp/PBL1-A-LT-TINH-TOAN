#include <iostream>
#include <string>
#include <cmath>
using namespace std;
struct Book
{
    string name;
    string authorName;
    string publisher;
    int yearOfPublication;
    bool status;
};
struct BookNode
{
    Book *book;
    BookNode *nextNode;
};

using namespace std;

int main()
{
}