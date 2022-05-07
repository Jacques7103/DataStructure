#include <iostream>
#include <array>

using namespace std;

template <typename T>
class Queue{
    private :
        array<T, 100> items;
        int size;
        int index;

        void swap(T &a, T &b);
        void heapify(int size, int i);
        bool bSearch(T left, T right, T target);

    public :
        Queue(){
            this->size = 0;
            this->index = 0;
        }
        void enqueue(T item);
        T dequeue();
        void print();
        T getSize();
        void sorting();
        void binarySearch(T target);
};

// IMPLEMENTATIONS
template <typename T>
void Queue<T>::enqueue(T item){
    this->items[this->size] = item;
    this->size++;
}

template <typename T>
T Queue<T>::dequeue(){
    if (this->size != 0){
        return this->items[this->index++];
    } else {
        cout << "There is nothing inside the queue !!" << endl;
    }
}

template <typename T>
T Queue<T>::getSize(){
    return this->size;
}

template <typename T>
void Queue<T>::print(){
    for (int i = this->index; i < this->size; i++){
        cout << this->items[i] << " ";
    }
    cout << endl;
}

template <typename T>
void Queue<T>::sorting(){
    if (this->size != 0){
        for (int i = this->size / 2 - 1; i >= 0; i--){
            heapify(size, i);
        }

        for (int i = this->size - 1; i >= 0; i--){
            swap(this->items[0], this->items[i]);
            heapify(i, 0);
        }
    } else {
        cout << "There is nothing inside the queue !!" << endl;
    }
}

template <typename T>
void Queue<T>::heapify(int size, int i){
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (this->items[leftChild] > this->items[largest] && leftChild < size){
        largest = leftChild;
    }

    if (this->items[rightChild] > this->items[largest] && rightChild < size){
        largest = rightChild;
    }

    if (largest != i){
        swap(this->items[i], this->items[largest]);
        heapify(size, largest);
    }
}

template <typename T>
void Queue<T>::swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
bool Queue<T>::bSearch(T left, T right, T target){
    if (right >= left){
        int mid = (left + right) / 2;
        if (target == this->items[mid]){
            return true;
        }
        else if (target < this->items[mid]){
            return bSearch(left, mid - 1, target);
        }
        else if (target > this->items[mid]){
            return bSearch(mid + 1, right, target);
        }
    }
    return false;
}

template <typename T>
void Queue<T>::binarySearch(T target){
    T find = bSearch(0, this->size, target);
    if (find == true){
        cout << target << " is inside the queue !!" << endl;
    } else {
        cout << target << " isn't on the queue !!" << endl;
    }
}