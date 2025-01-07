#include <iostream>
using namespace std;

class Node {
public:
    int data;     
    Node* next;   
    Node* prev;   

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head; 
    Node* tail; 
    int size;  

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void InsertAtBegin(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) { 
            head = tail = newNode;  
        }
        else {
            newNode->next = head; 
            head->prev = newNode; 
            head = newNode;       
        }
        size++; 
    }

    void InsertAtEnd(int data) {
        Node* newNode = new Node(data); 
        if (tail == nullptr) { 
            head = tail = newNode; 
        }
        else {
            tail->next = newNode; 
            newNode->prev = tail; 
            tail = newNode;        
        }
        size++; 
    }

    void InsertAtIndex(int data, int index) {
        if (index < 0 || index > size) {
            cout << "index is invalid";
            return;
        }
           
        if (index == 0) {
            InsertAtBegin(data);
        }
        else if (index == size) {
            InsertAtEnd(data);
        }
        else {
            Node* newNode = new Node(data); 
            Node* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next; 
            }
            newNode->next = temp->next;     
            newNode->prev = temp; 
            temp->next = newNode;      
            size++;
        }
    }

    void UpdateNode(int data, int index) {
        if (index < 0 || index > size) {
            cout << "index is invalid";
            return;
        }
            
        Node* temp = head;
        for (int i = 0; i <= index; i++) {
            temp = temp->next; 
        }
        temp->data = data; 
    }

    int RemoveNodeAtBegin() {
        if (head == nullptr) {
            cout << "list is empty";
            return -1;
        }
        Node* temp = head;
        int value = temp->data; 
        head = head->next; 
        if (head != nullptr) head->prev = nullptr;
        delete temp;
        size--;  
        return value;
    }

    int RemoveNodeAtEnd() {
        if (tail == nullptr) {
            cout << "list is empty";
            return -1;
        }
        Node* temp = tail;
        int value = temp->data;
        tail = tail->prev;
        if (tail != nullptr) tail->next = nullptr;
        delete temp; 
        size--; 
        return value; 
    }

    int SizeOfList() {
        return size;
    }

    void Display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void Invert() {
        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev; 
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    void Concatenate(DoublyLinkedList& otherList) {
        if (otherList.head == nullptr) return;
        if (head == nullptr) { 
            head = otherList.head;
            tail = otherList.tail;
        }
        else {
            tail->next = otherList.head; 
            otherList.head->prev = tail;  
            tail = otherList.tail; 
        }
        size += otherList.size; 
    }

   
};

int main() {
    DoublyLinkedList list1;
    list1.InsertAtBegin(10);
    list1.InsertAtEnd(20);
    list1.InsertAtEnd(30);
    list1.RemoveNodeAtBegin();
    list1.Display();

    list1.Invert();
    list1.Display();

    DoublyLinkedList list2;
    list2.InsertAtBegin(40);
    list2.InsertAtEnd(50);
    list1.InsertAtIndex(50, 2);
    list1.UpdateNode(10, 2);
    list1.Display();

    list1.Concatenate(list2);
    list1.Display();

    cout << "Size of list: " << list1.SizeOfList() << endl;

    return 0;
}