#include <iostream>
using namespace std;

class SimpleQueue {
private:
    int size;     
    int* queue;   
    int front;  
    int rear;      

public:
    
    SimpleQueue(int maxSize) {
        size = maxSize;
        queue = new int[size]; 
        front = 0;
        rear = -1;
    }


    void Enqueue(int item) {
        if (IsFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        queue[++rear] = item;
    }
    int Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return queue[front++];
    }
    int Peek() {
        if (IsEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return queue[front];
    }
    bool IsEmpty() {
        return front > rear;
    }
    bool IsFull() {
        return rear == size - 1;
    }
    void Display() {
        if (IsEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
    ~SimpleQueue() {
        delete[] queue;
    }
}; int main() {
    SimpleQueue q(5);

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Display();

    cout << "Dequeued: " << q.Dequeue() << endl;
    q.Display();

    q.Enqueue(40);
    q.Enqueue(50);
    q.Display();

    q.Enqueue(60);

    return 0;
}