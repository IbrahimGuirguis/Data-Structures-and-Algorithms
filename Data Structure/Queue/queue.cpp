#include <iostream>
using namespace std;

template <class dataType> 
class QueueArrayList
{
    int capacity;
    int size;
    dataType *queue;

public:
    QueueArrayList()
    {
        this->capacity = 1;
        this->size = 0;
        queue = new dataType[this->capacity];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    void expandQueue()
    {
        capacity *= 2;
        dataType *newQueue = new dataType[capacity];
        for (int i = 0; i < size; i++)
        {
            newQueue[i] = queue[i];
        }
        delete []queue;
        queue = newQueue;
    }

    void pushToBack(dataType value)
    {
        if (isFull()) expandQueue();
        queue[size] = value;
        size++;
    }

    void popFromFront()
    {
        if (isEmpty()) return;
        for (int i = 0; i < size; i++)
        {
            queue[i] = queue[i+1];
        }
        size--;
    }

    void showQueue()
    {
        for (int i = size - 1; i >= 0; i--)
        {
            cout<< queue[i] << " ";
        }
        cout<<"\n";
    }

    void printInfo()
    {
        showQueue();
        cout<< "Capacity : " << this->capacity
            << "\nSize : " <<this->size
            << "\n=====Break Line=====\n";
    }


};


int main()
{
    QueueArrayList<int> queue;

    queue.printInfo();

    for (int i = 10; i <= 100; i+=10)
    {
        queue.pushToBack(i);
    }
    
    queue.printInfo();

    queue.popFromFront();

    queue.printInfo();

    queue.popFromFront();

    queue.printInfo();

    return 0;
}