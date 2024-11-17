#include <iostream>
using namespace std;

class ArrayManager {
private:
    int arr[100];
    int size;


public:
    ArrayManager() {
        size = 0;
    }
    void Insert(int index, int value);
    int Delete_By_Value(int value);
    void Delete_By_Index(int index);
    void Display();
    void Append(int value);
    void Reverse();
    int Search_By_Value(int value);
};

void ArrayManager::Insert(int index, int value) {
    if (index < 0 || index > size || size >= 100) {
        cout << "Invalid index or array is full." << endl;
        return;
    }

    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    size++;
}

int ArrayManager::Delete_By_Value(int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            return i;
        }
    }
    cout << "Value not found." << endl;
    return -1;
}

void ArrayManager::Delete_By_Index(int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index." << endl;
        return;
    }

    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
}

void ArrayManager::Display() {
    if (size == 0) {
        cout << "Array is empty." << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void ArrayManager::Append(int value) {
    if (size >= 100) {
        cout << "Array is full." << endl;
        return;
    }

    arr[size] = value;
    size++;
}

void ArrayManager::Reverse() {
    for (int i = 0; i < size / 2; i++) {
        swap(arr[i], arr[size - 1 - i]);
    }
}

int ArrayManager::Search_By_Value(int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}
int main() {
    ArrayManager manager;

    manager.Append(10);
    manager.Append(20);
    manager.Display();

    manager.Insert(1, 15);
    manager.Display();

    manager.Delete_By_Value(15);
    manager.Display();

    manager.Reverse();
    manager.Display();

    return 0;
}