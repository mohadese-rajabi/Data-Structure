#include <iostream>
#include <stack>
using namespace std;

class Stack {
private:
    int arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Push
    void Push(int item) {
        if (top < 99) {
            arr[++top] = item;
        }
        else {
            cout << "Stack Overflow!" << endl;
        }
    }

    // Pop
    int Pop() {
        if (top >= 0) {
            return arr[top--];
        }
        else {
            throw runtime_error("Stack Underflow");
        }
    }

    // Peek
    int Peek() {
        if (top >= 0) {
            return arr[top];
        }
        else {
            throw runtime_error("Stack is empty");
        }
    }

    // IsEmpty
    bool IsEmpty() {
        return top == -1;
    }
};

int main() {

    Stack stack;
    stack.Push(5);
    stack.Push(10);
    stack.Push(15);

    cout << "Peek: " << stack.Peek() << endl; 
    cout << "Pop: " << stack.Pop() << endl;
    cout << "Pop: " << stack.Pop() << endl; 

    return 0;
}