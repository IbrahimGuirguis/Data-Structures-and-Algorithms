#include <iostream>
using namespace std;


template <class dataType>
class Node
{
public:
    dataType value;
    Node *next;
    // Default constructor
    Node()
    {
        next = nullptr;
    }
    // Parameterized constructor
    Node(dataType value, Node *next)
    {
        this->value = value;
        this->next = next;
    }
};

template <class dataType>
class LinkedList
{
private:
    Node<dataType> *head;

public:
    // Default constructor
    LinkedList()
    {
        head = nullptr; // Initialize head pointer to nullptr
    }

    bool isEmpty(){
        return head == nullptr; // return true if linked list is empty
    }

    // Front operations
    void addToFirst(dataType value)
    {
        Node<dataType> *newNode = new Node<dataType>(value, head); // Create new node in heap memory with passed value and address of head pointer
        head = newNode; // Let the head pointer points to the new node
    }
    void removeFromFirst()
    {
        if (isEmpty()) return; // If linked list is empty exit the function       
        head = head->next; // Let the head points to next node
    }

    // Back operations
    void addToLast(dataType value)
    {
        if(isEmpty())
        {
            addToFirst(value); // In case the linked list is empty
            return;
        }
        Node<dataType> *newNode = new Node<dataType>(value, nullptr); // Create new node and make it points to null cause we will add it from the last
        Node<dataType> *goThrough = head; // Make a pointer to loop through linked list elements
        while(goThrough->next != nullptr)
        {
            goThrough = goThrough->next; // If next pointer of the goThrough not equal nullptr then make goThrough points to next node by assigning next reference to goThrough
        }
        goThrough->next = newNode; // Make next pointer of last node points to new node
    }
    void removeFromLast()
    {
        if (isEmpty()) return; // If linked list is empty exit
        // Making two pointers loop through elements but one of them next the other
        Node<dataType> *nextGoThrough = head;
        Node<dataType> *previousGoThrough = head;
        // If the next of the next pointer not equal null let it points to next node until you reach null one
        // With consideration of letting previous pointer behind next pointer with one step
        while (nextGoThrough->next != nullptr)
        {
            previousGoThrough = nextGoThrough;
            nextGoThrough = nextGoThrough->next; 
        }
        delete nextGoThrough;
        previousGoThrough->next = nullptr;

        /*
            Another impelementation in case you want to remove from last and 
            the linked list is not empty
        */
        /*
            if (isEmpty()) return; // If linked list is empty exit
            Node<dataType> *goThrough = head; // Make a pointer loop through linked list elements
            while (goThrough->next->next != nullptr)
            {
                goThrough = goThrough->next; // If the next of the next node is not null go to next node
            }
            goThrough->next = nullptr; // Make the node before the last points to null
        */
    }

    void printElements()
    {   
        if (isEmpty())
        {
            cout<<"The Linked List is Empty!\n";
            return;
        }
        Node<dataType> *goThrough = head;
        cout<< "Head -> ";
        while(goThrough->next != nullptr)
        {
            cout<< goThrough->value << " -> ";
            goThrough = goThrough->next;
        }
        cout<< goThrough->value << " -> " << "Null" <<endl;
    }
};

int main()
{
    /*
                            (Linked List)
        Advantage               vs               Disadvantage
        - Not Fixed Size                         - Different access time (retrieval time)
        - Good Insersion
        - Good Removal
    */

    LinkedList<int> list;

    list.printElements();

    for(int i = 10; i <= 50; i+=10)
    {
        list.addToFirst(i);
    }
    
    list.printElements();

    for(int i = 10; i <= 50; i+=10)
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