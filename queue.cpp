#include <iostream>
#include <array>
#include "./queue.hpp"

using namespace std;

int main(){
    Queue<int> myQueue;
    myQueue.dequeue();
    myQueue.sorting();
    cout << "=========================================" << endl;
    myQueue.enqueue(42);
    myQueue.enqueue(63);
    myQueue.enqueue(13);
    myQueue.enqueue(52);
    myQueue.enqueue(14);
    myQueue.enqueue(81);
    cout << "Before sorting : ";
    myQueue.print();
    myQueue.sorting();
    cout << "After sorting : ";
    myQueue.print();
    cout << "=========================================" << endl;
    myQueue.binarySearch(52);
    myQueue.binarySearch(42);
    myQueue.binarySearch(14);
    cout << "=========================================" << endl;
    myQueue.binarySearch(0);
    myQueue.binarySearch(99);
    myQueue.binarySearch(123);
}