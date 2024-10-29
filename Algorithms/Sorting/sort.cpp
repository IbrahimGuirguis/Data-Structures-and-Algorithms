#include <iostream>
using namespace std;

// Function for printing the arrays
void displayArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<< array[i] << " ";
    }
    cout << "\n=====Break Line=====\n";
}

// Bubble Sort Algorithm O(n^2) worst and average case & O(n) best case
void bubbleSort(int array[], int size) 
{
    for (int i = 0; i < size; i++)
    {
        bool swap = false; // For tracing whether swapping happened or not
        for (int j = 0; j < size - i - 1; j++)
        {
            // Swap in case the left number is greater than the right one
            if (array[j + 1] < array[j])
            {
                int temp = array[j + 1]; // Temporary variable for swaping
                array[j + 1] = array[j];
                array[j] = temp;
                swap = true;
            }
        }
        if (!swap) return; // If in one iteration no swap happens then exit cause the array is already sorted 
        displayArray(array, size); // For showing how the algorithm work
    }
}

// Insertion Sort Algorithm O(n^2) worst and average case & O(n) best case
void insertionSort(int array[], int size) 
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i; j >= 0 && array[j + 1] < array[j]; j--) // Swap in case the left number is greater than the right one
        {
            int temp = array[j + 1]; // Temporary variable for swaping
            array[j + 1] = array[j];
            array[j] = temp;
        }
        displayArray(array, size); // For showing how the algorithm work
    }
}

// Merge Sort Algorithm O(nlog(n))
void mergeSort(int array[], int size)
{


}



int main()
{
    int size = 10;
    int *ptr = new int[size]{2,3,5,10,4,1,8,7,9,6};

    // bubbleSort(ptr, size);
    insertionSort(ptr, size);


    return 0;
}