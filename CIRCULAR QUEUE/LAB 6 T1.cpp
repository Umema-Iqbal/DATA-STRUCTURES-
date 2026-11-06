#include <iostream>
#include <string>
using namespace std;
struct Customer {
    string name;
    string transaction;
};
class MyQueue {
private:
    Customer* arr;
    int maxSize;
    int front, rear, currentSize;
public:
    MyQueue(int size) {
        maxSize = size;
        arr = new Customer[maxSize];
        front = 0;
        rear = -1;
        currentSize = 0;
    }
    ~MyQueue() {
        delete[] arr;
    }
    bool isEmpty() {
        return currentSize == 0;
    }
    bool isFull() {
        return currentSize == maxSize;
    }
    void enqueue(Customer c) {
        if (isFull()) {
            cout << "Queue Overflow! Queue is full.\n";
            return;
        }
        rear = (rear + 1) % maxSize;
        arr[rear] = c;
        currentSize++;
        cout << "Customer added successfully!\n";
    }
    Customer dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! No customers waiting.\n";
            return {"", ""};
        }
        Customer c = arr[front];
        front = (front + 1) % maxSize;
        currentSize--;
        return c;
    }
    void display() {
        if (isEmpty()) {
            cout << "No customers waiting.\n";
            return;
        }
        for (int i = 0; i < currentSize; i++) {
            int index = (front + i) % maxSize;
            cout << "\nName: " << arr[index].name;
            cout << "\nTransaction: "<< arr[index].transaction << endl;
        }
    }
    int getSize() {
        return currentSize;
    }
};
int main() {
    MyQueue q(5);
    int choice;
    do {
        cout << "\n BANK QUEUE SYSTEM\n";
        cout << "1. Add Customer\n";
        cout << "2. Serve Customer\n";
        cout << "3. Display Customers\n";
        cout << "4. Total Waiting Customers\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            Customer c;
            cin.ignore();
            cout << "Enter customer name: ";
            getline(cin, c.name);
            cout << "Enter transaction type: ";
            getline(cin, c.transaction);
            q.enqueue(c);
            break;
        }
        case 2: {
            Customer c = q.dequeue();
            if (c.name != "") {
                cout << "Served Customer: " << c.name;
                cout << "\nTransaction: "
                     << c.transaction << endl;
            }
            break;
        }
        case 3:
            q.display();
            break;
        case 4:
            cout << "Total waiting customers: "<< q.getSize() << endl;
            break;
        case 5:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}
