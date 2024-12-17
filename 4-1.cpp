#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:

    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }
    ~Stack() {
        delete[] arr;
    }

    void Push(int item) {
        if (top == capacity - 1) {
            cout << "Stack Overflow!" << endl;
        }
        else {
            arr[++top] = item;
        }
    }

    int Pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        else {
            return arr[top--];
        }
    }

    bool IsEmpty() {
        return top == -1;
    }
};

class QueueWithStacks {
private:
    Stack stack1, stack2;

public:
    QueueWithStacks(int size) : stack1(size), stack2(size) {}

    void Enqueue(int item) {
        stack1.Push(item);
    }
    int Dequeue() {
        if (stack2.IsEmpty()) {
            while (!stack1.IsEmpty()) {
                stack2.Push(stack1.Pop());
            }
        }

        if (stack2.IsEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        return stack2.Pop();
    }
};

int main() {
    QueueWithStacks queue(5);

    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    cout << "Dequeue: " << queue.Dequeue() << endl;
    cout << "Dequeue: " << queue.Dequeue() << endl;

    queue.Enqueue(40);
    queue.Enqueue(50);

    cout << "Dequeue: " << queue.Dequeue() << endl;
    cout << "Dequeue: " << queue.Dequeue() << endl;
    cout << "Dequeue: " << queue.Dequeue() << endl; 

    return 0;
}