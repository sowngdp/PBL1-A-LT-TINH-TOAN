#include <iostream>
struct Book
{
    int id;
    std::string name;
    std::string authorName;
    std::string publisher;
    int yearOfPublication;
    bool isBorrowed;
};
void inputBook(Book &book)
{
    std::cout << " id: ";
    std::cin >> book.id;
    std::cout << " name: ";
    std::cin >> book.name;
    std::cout << " author name: ";
    std::cin >> book.authorName;
    std::cout << " publisher: ";
    std::cin >> book.publisher;
    std::cout << " year of publication: ";
    std::cin >> book.yearOfPublication;
    std::cout << " isBorrowed? (true/false): ";
    std::cin >> book.isBorrowed;
}
void showBook(Book book)
{
    std::cout << " id: " << book.id << std::endl;
    std::cout << " name: " << book.name << std::endl;
    std::cout << " author name: " << book.authorName << std::endl;
    std::cout << " publisher: " << book.publisher << std::endl;
    std::cout << " status: " << (book.isBorrowed ? "Borrowed" : "Free") << std::endl;
    std::cout << "===========================================================" << std::endl;
}
