#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void InsertAtBegin(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void InsertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void InsertAtIndex(int data, int index) {
        if (index == 0) {
            InsertAtBegin(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* current = head;
        for (int i = 0; current != nullptr && i < index - 1; i++) {
            current = current->next;
        }
        if (current == nullptr) return;
        newNode->next = current->next;
        current->next = newNode;
    }

    void UpdateNode(int data, int index) {
        Node* current = head;
        for (int i = 0; current != nullptr && i < index; i++) {
            current = current->next;
        }
        if (current != nullptr) {
            current->data = data;
        }
    }

    int RemoveNodeAtBegin() {
        if (head == nullptr)
        {
            cout << "List is empty";
            return -1;
        }
        Node* temp = head;
        int value = head->data;
        head = head->next;
        delete temp;
        return value;
    }

    int RemoveNodeAtEnd() {
        if (head == nullptr)
        {
            cout << "List is empty";
            return -1;
        }
        if (head->next == nullptr) {
            int value = head->data;
            delete head;
            head = nullptr;
            return value;
        }
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        int value = current->next->data;
        delete current->next;
        current->next = nullptr;
        return value;
    }

    int RemoveNodeAtIndex(int index) {
        if (index == 0) return RemoveNodeAtBegin();
        Node* current = head;
        for (int i = 0; current != nullptr && i < index - 1; i++) {
            current = current->next;
        }
        if (current == nullptr || current->next == nullptr) return -1;
        Node* temp = current->next;
        int value = temp->data;
        current->next = temp->next;
        delete temp;
        return value;
    }

    int SizeOfList() {
        int size = 0;
        Node* current = head;
        while (current != nullptr) {
            size++;
            current = current->next;
        }
        return size;
    }

    void Concatenate(SinglyLinkedList& otherList) {
        if (head == nullptr) {
            head = otherList.head;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = otherList.head;
    }

    void Invert() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void Display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};
class arraylinked {
private: 
    SinglyLinkedList m;
public:
    void insert(int index, int data)
    {
        m.InsertAtIndex(data, index);
    }
    void Deletebyindex(int index)
    {
        m.RemoveNodeAtIndex(index);
    }
    void Display()
    {
        m.Display();
    }
    void Append(int data)
    {
        m.InsertAtEnd(data);
    }
    void Reverse()
    {
        m.Invert();
    }
    void size()
    {
        m.SizeOfList();
    }

};
int main()
{
    arraylinked ob;
    ob.insert(0,10);
    ob.insert(1,20);
    ob.Append(30);
    ob.Display();
    ob.Reverse();
    ob.Display();


    


}