#include "Book.h"
struct BookNode
{
    Book *book;
    BookNode *nextNode;
};
struct LinkedList
{
    BookNode *headNode;
    BookNode *tailNode;
};

LinkedList createLinkedList()
{
    LinkedList linkedList;
    linkedList.headNode = NULL;
    linkedList.tailNode = NULL;
    return linkedList;
}

void addBookToLast(LinkedList &linkedList, Book *book)
{
    BookNode *newNode = new BookNode;
    newNode->book = book;
    newNode->nextNode = NULL;
    if (linkedList.headNode == NULL)
    {
        linkedList.headNode = newNode;
        linkedList.tailNode = newNode;
    }
    else
    {
        linkedList.tailNode->nextNode = newNode;
        linkedList.tailNode = newNode;
    }
}
void addBookToFirst(LinkedList &linkedList, Book *book)
{
    BookNode *newNode = new BookNode;
    newNode->book = book;
    newNode->nextNode = NULL;
    if (linkedList.headNode == NULL)
    {
        linkedList.headNode = newNode;
        linkedList.tailNode = newNode;
    }
    else
    {
        newNode->nextNode = linkedList.headNode;
        linkedList.headNode = newNode;
    }
}
void insertAfter(LinkedList &linkedList, Book *book, BookNode *node)
{
    BookNode *newNode = new BookNode;
    newNode->book = book;
    newNode->nextNode = node->nextNode;
    node->nextNode = newNode;
    if (linkedList.tailNode == node)
    {
        linkedList.tailNode = newNode;
    }
}
void deleteBookById(LinkedList &linkedList, int id)
{
    BookNode *currentNode = linkedList.headNode;
    BookNode *previousNode = NULL;
    while (currentNode != NULL)
    {
        if (currentNode->book->id == id)
        {
            if (previousNode == NULL) // đây là node đầu tiên
            {
                linkedList.headNode = currentNode->nextNode;
            }
            else
            {
                previousNode->nextNode = currentNode->nextNode;
            }
            if (currentNode == linkedList.tailNode) // đây là node cuối cùng
            {
                linkedList.tailNode = previousNode;
            }
            delete currentNode;
            break;
        }
        previousNode = currentNode;
        currentNode = currentNode->nextNode;
    }
}
void DeleteBookByName(LinkedList &linkedList, std::string name)
{
    BookNode *node = linkedList.headNode;
    if (node->book->name == name)
    {
        linkedList.headNode = node->nextNode;
        delete node;
    }
    else
    {
        while (node->nextNode != NULL)
        {
            if (node->nextNode->book->name == name)
            {
                BookNode *temp = node->nextNode;
                node->nextNode = temp->nextNode;
                delete temp;
                break;
            }
            node = node->nextNode;
        }
    }
}
void deleteBookByAuthorName(LinkedList &linkedList, std::string author)
{
    BookNode *node = linkedList.headNode;
    if (node->book->authorName == author)
    {
        linkedList.headNode = node->nextNode;
        delete node;
    }
    else
    {
        while (node->nextNode != NULL)
        {
            if (node->nextNode->book->authorName == author)
            {
                BookNode *temp = node->nextNode;
                node->nextNode = temp->nextNode;
                delete temp;
                break;
            }
            node = node->nextNode;
        }
    }
}
void deleteFirstBook(LinkedList &linkedList)
{
    BookNode *node = linkedList.headNode;
    linkedList.headNode = node->nextNode;
    delete node;
}
void deleteLastBook(LinkedList &linkedList)
{
    BookNode *node = linkedList.headNode;
    while (node->nextNode != linkedList.tailNode)
    {
        node = node->nextNode;
    }
    linkedList.tailNode = node;
    delete node->nextNode;
    node->nextNode = NULL;
}
void deleteAfterId(LinkedList &linkedList, int id)
{
    BookNode *node = linkedList.headNode;
    while (node->nextNode != NULL)
    {
        if (node->book->id == id)
        {
            BookNode *temp = node->nextNode;
            node->nextNode = node->nextNode->nextNode;
            delete temp;
            break;
        }
        node = node->nextNode;
    }
}
LinkedList findBookByName(LinkedList &linkedList, std::string name)
{
    LinkedList result;
    BookNode *node = linkedList.headNode;
    while (node != NULL)
    {
        if (node->book->name == name)
        {
            addBookToLast(result, node->book);
        }
        node = node->nextNode;
    }
    return result;
}
LinkedList findBookByAuthorName(LinkedList &linkedList, std::string author)
{
    LinkedList result;
    BookNode *node = linkedList.headNode;
    while (node != NULL)
    {
        if (node->book->authorName == author)
        {
            addBookToLast(result, node->book);
        }
        node = node->nextNode;
    }
    return result;
}
LinkedList findBookByPublisher(LinkedList &linkedList, std::string publisher)
{
    LinkedList result;
    BookNode *node = linkedList.headNode;
    while (node != NULL)
    {
        if (node->book->publisher == publisher)
        {
            addBookToLast(result, node->book);
        }
        node = node->nextNode;
    }
    return result;
}
void displayList(LinkedList &linkedList)
{
    BookNode *node = linkedList.headNode;
    while (node != NULL)
    {
        showBook(*node->book);
        node = node->nextNode;
    }
}
void displayAllBookIsBorrowed(LinkedList &linkedList)
{
    BookNode *node = linkedList.headNode;
    while (node != NULL)
    {
        if (node->book->isBorrowed)
        {
            showBook(*node->book);
        }
        node = node->nextNode;
    }
}
void displayAllBookIsNotBorrowed(LinkedList &linkedList)
{
    BookNode *node = linkedList.headNode;
    while (node != NULL)
    {
        if (!node->book->isBorrowed)
        {
            showBook(*node->book);
        }
        node = node->nextNode;
    }
}
void sort(LinkedList &linkedList, bool (*compare)(Book, Book))
{
    BookNode *node = linkedList.headNode;
    while (node != NULL)
    {
        BookNode *node2 = node->nextNode;
        while (node2 != NULL)
        {
            if (compare(*node->book, *node2->book))
            {
                Book temp = *node->book;
                *node->book = *node2->book;
                *node2->book = temp;
            }
            node2 = node2->nextNode;
        }
        node = node->nextNode;
    }
}
