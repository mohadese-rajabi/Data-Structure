#include <iostream>
using namespace std;

class CircularQueue {
private:
    int size;
    int* queue;
    int front;
    int rear;
    int count;

public:
    CircularQueue(int maxSize) {
        size = maxSize;
        queue = new int[size];
        front = 0;
        rear = -1;
        count = 0;
    }

    void Enqueue(int item) {
        if (IsFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % size;
        queue[rear] = item;
        count++;
    }

    int Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int item = queue[front];
        front = (front + 1) % size;
        count--;
        return item;
    }

    int Peek() {
        if (IsEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return queue[front];
    }

    bool IsEmpty() {
        return count == 0;
    }

    bool IsFull() {
        return count == size;
    }

    void Display() {
        if (IsEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            cout << queue[(front + i) % size] << " ";
        }
        cout << endl;
    }

    ~CircularQueue() {
        delete[] queue;
    }
};

int main() {
    CircularQueue cq(5);

    cq.Enqueue(10);
    cq.Enqueue(20);
    cq.Enqueue(30);
    cq.Display();

    cout << "Dequeued: " << cq.Dequeue() << endl;
    cq.Display();

    cq.Enqueue(40);
    cq.Enqueue(50);
    cq.Display();

    cq.Enqueue(60);
    cq.Display();

    while (!cq.IsEmpty()) {
        cout << "Dequeued: " << cq.Dequeue() << endl;
    }
    cq.Display();

    return 0;
}