#include <iostream>
using namespace std;


template <class dataType>
class Node
{
public:
    dataType value;
    Node *previous;
    Node *next;
    // Default Constructor
    Node()
    {
        previous = nullptr;
        next = nullptr;
    }
    Node(dataType value, Node *previous, Node *next)
    {
        this->value = value;
        this->previous = previous;
        this->next = next;
    }
};

template <class dataType>
class DoublyLinkedList
{
private:
    Node<dataType> *head;
public:
    // Default Constructor
    DoublyLinkedList()
    {
        head = nullptr;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    // Front operations
    void addToFirst(dataType value)
    {
        Node<dataType> *newNode = new Node<dataType>(value, head, head); // Create new node
        head = newNode;
    }
    void removeFromFirst()
    {
        if (isEmpty()) return;
        head = head->next;
    }

    // Back operations
    void addToLast(dataType value)
    {
        Node<dataType> *newNode = new Node<dataType>;
        Node<dataType> *goThrough = head;
        while (goThrough->next != nullptr)
        {
            goThrough = goThrough->next;
        }
        goThrough->next = newNode;
        newNode->previous = goThrough;
        newNode->value = value;
    }
    void removeFromLast()
    {
        Node<dataType> *goThrough = head;
        while (goThrough->next != nullptr)
        {
            goThrough = goThrough->next;
        }
        goThrough->previous->next = nullptr;
    }

    void printElements()
    {
        if (isEmpty())
        {
            cout << "The Doubly Linked List is Empty!\n";
            return; 
        }
        Node<dataType> *goThrough = head;
        cout << "Head <-> ";
        while(goThrough->next != nullptr)
        {
            cout << goThrough->value << " <-> ";
            goThrough = goThrough->next;
        }
        cout << goThrough->value << " <-> Null\n";
    }
};



int main()
{
    DoublyLinkedList<int> list;

    list.printElements();

    for (int i = 10; i <= 50; i+=10)
    {
        list.addToFirst(i);
    }

    list.printElements();

    for (int i = 10; i <= 50; i+=10)
    {
        list.addToLast(i);
    }

    list.printElements();

    list.removeFromFirst();
    list.printElements();
    list.removeFromLast();
    list.printElements();

    return 0;
}