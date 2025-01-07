#include <iostream>
using namespace std;

class Node {
public:
    int data;      
    Node* next;    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head; 
    int size;  

public:
   
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    void InsertAtBegin(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            newNode->next = newNode; 
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;   
        }
        size++;
    }

    void InsertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            newNode->next = newNode; 
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != head) { 
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        size++;
    }

    void InsertAtIndex(int data, int index) {
        if (index < 0 || index > size) {
            cout << "index invalid";
            return;
        }

        if (index == 0) {
            InsertAtBegin(data);
            return;
        }

        Node* newNode = new Node(data);
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) { 
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;    
        size++; 
    }

    void UpdateNode(int data, int index) {
        if (index < 0 || index >= size) {
            cout <<"index invalid";
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index; i++) { 
            temp = temp->next;
        }
        temp->data = data;
    }

    int RemoveNodeAtBegin() {
        if (!head) {
            cout << "list is empty";
            return -1;
        }
        int removedData = head->data; 
        if (head->next == head) {   
            delete head;
            head = nullptr;
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next; 
            delete head;
            head = temp->next;
        }
        size--;
        return removedData;
    }

    int RemoveNodeAtEnd() {
        if (!head) {
            cout <<"list is empty";
            return -1;
        }

        Node* temp = head;
        if (head->next == head) { 
            int removedData = head->data;
            delete head;
            head = nullptr;
            size--;
            return removedData;
        }
        while (temp->next->next != head) { 
            temp = temp->next;
        }

        int removedData = temp->next->data;
        delete temp->next;
        temp->next = head;
        size--;
        return removedData;
    }

    int RemoveNodeAtIndex(int index) {
        if (index < 0 || index >= size) {
            cout << "index invalid";
            return -1;
        }

        if (index == 0) {
            return RemoveNodeAtBegin();
        }

        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        int removedData = temp->next->data; 
        Node* nodeToDelete = temp->next;    
        temp->next = temp->next->next;     
        delete nodeToDelete;
        size--;
        return removedData;
    }

    int SizeOfList() {
        return size;
    }

    void Concatenate(LinkedList& other) {
        if (!other.head) return;

        if (!head) {
            head = other.head;
        }
        else {
            Node* temp = head;
            while (temp->next != head) { 
                temp = temp->next;
            }
            temp->next = other.head; 
            temp = other.head;
            while (temp->next != other.head) {
                temp = temp->next;
            }
            temp->next = head;
        }

        size += other.size; 
        other.head = nullptr;
        other.size = 0;
    }

    void Invert() {
        if (!head || head->next == head) return;

        Node* prev = nullptr, * current = head, * next = nullptr;
        Node* tail = head;
        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head);

        head->next = prev;
        head = prev;
    }

    void Display() {
        if (!head) {
            cout << "list is empty";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.InsertAtBegin(10);
    list.InsertAtEnd(20);
    list.InsertAtEnd(30);
    list.InsertAtBegin(5);
    list.InsertAtIndex(15, 2);

    list.Display(); 

    list.RemoveNodeAtBegin();
    list.RemoveNodeAtEnd();
    list.RemoveNodeAtIndex(1);

    list.Display(); 

    cout << list.SizeOfList() << endl; 

    LinkedList list2;
    list2.InsertAtBegin(100);
    list2.InsertAtEnd(200);

    list.Concatenate(list2);
    list.Display();

    list.Invert();
    list.Display();

    return 0;
}