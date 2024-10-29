#include <iostream>
using namespace std;

// Array List is the implementation of vector

template<class type> // Template for specifying list data type
class ArrayList {
private:
    // Attributes
    int capacity; // Size of the list
    int numberOfItems; // Number of list items
    type *list; // Pointer in stack points to array in heap memory
    // Increase the capacity of the list when it is full
    void expand(){
        this->capacity *= 2; // Increase capacity by twice to save time, because if we increase by one, it will cost more time
        type *temp = new type[capacity]; // Create new pointer points to new array with expanded capacity
        for (int i = 0; i < numberOfItems; i++)
        {
            temp[i] = list[i]; // Copying the old array in the new array
        }
        delete []list; // Release memory
        list = temp; // Points to a new array
    }
public:
    // Default constructor
    ArrayList(){
        this->capacity = 1;
        this->numberOfItems = 0;
        list = new type[capacity];
    }

    // Getters for capcity and number of items
    int getCapacity(){
        return this->capacity;
    }
    int getNumberOfItems(){
        return this-> numberOfItems;
    }

    // Add and remove from first of the array
    void addFromFirst(type value){
        if(numberOfItems == capacity){
            // Increasing the capacity of the list to add more items if number of items reach to capacity
            this->expand();
        } 
        for (int i = numberOfItems - 1; i >= 0; i--){
            list[i+1] = list[i];
        }
        list[0] = value;
        numberOfItems++;
    }
    void removeFromFirst(){
        for (int i = 0; i <= numberOfItems - 1; i++){
            list[i] = list[i+1];
        }
        numberOfItems--;        
    }

    // Add and remove from last of the array
    void addFromLast(int value){
        if(numberOfItems == capacity){
            this->expand();
        }
        list[numberOfItems] = value;
        numberOfItems++;
    }
    void removeFromLast(){
        numberOfItems--;
    }
    
    // Display list capacity ,number of items and item values
    void printListInfo(){
        cout<<"Capcity : " << this->capacity << endl <<"Number of items : " << this->numberOfItems <<endl;
        cout<< "Array = [";
        for (int i = 0; i < numberOfItems - 1; i++)
        {
            cout<< list[i] << " ,";
        }
        cout <<list[numberOfItems-1]<<"]" <<endl;
    }
    
    // Search for a value If it exists, it will return true, otherwise it will return false
    bool search(type value){
        for (int i = 0; i <= numberOfItems - 1; i++)
        {
            if(value == list[i]){
                return true;
            }
        }
        return false;
    }
    
    // Releasing memory using destructor
    ~ArrayList(){
        delete []list;
    }
};



int main() {
    /*
                            Array List
        (Advantage)               vs            (Disadvantage)
        - Fixed access time                     - Bad Insersion
                                                - Bad removal
                                                - Fixed size but we make it dynamic by creating
                                                new array in heap memory with different sizes                 
    */
    
    ArrayList<int>list;
    list.printListInfo();
    
    // Adding and removing items from first
    // Add
    list.addFromFirst(55);
    list.printListInfo(); 
    list.addFromFirst(10);
    list.printListInfo(); 
    list.addFromFirst(13);
    list.printListInfo(); 
    list.addFromFirst(523);
    list.printListInfo(); 
    list.addFromFirst(1032);
    list.printListInfo();
    // Remove
    list.removeFromFirst();
    list.printListInfo();

    // Adding and removing items from last
    // Add
    list.addFromLast(55);
    list.printListInfo(); 
    list.addFromLast(10);
    list.printListInfo(); 
    list.addFromLast(13);
    list.printListInfo();
    list.addFromLast(523);
    list.printListInfo();
    list.addFromLast(1032);
    list.printListInfo(); 
    // Remove
    list.removeFromLast();
    list.printListInfo();

    // Search for value
    list.addFromLast(33);
    list.printListInfo();
    cout<< list.search(33) << endl;
    list.removeFromLast();
    list.printListInfo();
    cout<< list.search(33) << endl;

    return 0;
}