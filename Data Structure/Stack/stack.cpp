#include <iostream>
using namespace std;

template <class dataType>
class StackArrayList
{
private:
    int capacity;
    int numberOfElements;
    dataType *stack;

public:
    StackArrayList()
    {
        capacity = 1;
        numberOfElements = 0;
        stack = new dataType[capacity];
    }
    
    int size()
    {
        return this->numberOfElements;
    }

    int capcity()
    {
        return this->capacity;
    }

    bool isEmpty()
    {
        return numberOfElements == 0;
    }

    bool isFull()
    {
        return numberOfElements == capacity;
    }
    
    void expandCapacity()
    {
        this->capacity *= 2;
        dataType *newStack = new dataType[capacity];
        for (int i = 0; i < numberOfElements; i++)
        {
            newStack[i] = stack[i];
        }
        delete []stack;
        stack = newStack;
    }

    void pushToStack(dataType value)
    {
        if (isFull()) expandCapacity(); // Expand capacity if stack is full
        for (int i = numberOfElements - 1; i >= 0; i--)
        {
            stack[i+1] = stack[i];
        }
        stack[0] = value;
        numberOfElements++;
    }

    void popFromStack()
    {
        if (isEmpty()) return; // If stack is empty exit
        for (int i = 0; i < numberOfElements; i++)
        {
            stack[i] = stack[i+1];
        }
        numberOfElements--;
    }

    void showStack()
    {
        if (isEmpty()) return;
        for (int i = 0; i < numberOfElements; i++)
        {
            cout<< stack[i] <<endl;   
        }
    }

    void stackInfo()
    {
        this->showStack();
        cout << "Capacity : " << this->capcity() 
             << "\nSize : " << this->size() << "\n=====Break Line=====\n";
    }

};

int main()
{
    StackArrayList<int> stack;

    stack.stackInfo();

    for (int i = 10; i <= 100; i+=10)
    {
        stack.pushToStack(i);
    }
    
    stack.stackInfo();

    stack.popFromStack();

    stack.stackInfo();

    stack.popFromStack();

    stack.stackInfo();

    return 0;
}