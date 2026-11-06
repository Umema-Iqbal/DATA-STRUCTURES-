#include <iostream>
#include <string>
using namespace std;
struct Booking {
    int customerID;
    string customerName;
    int numberOfTickets;
};
class CircularQueue {
private:
    Booking* arr;
    int maxSize;
    int front, rear, currentSize;
public:
    CircularQueue(int size) {
        maxSize = size;
        arr = new Booking[maxSize];
        front = 0;
        rear = -1;
        currentSize = 0;
    }
    ~CircularQueue() {
        delete[] arr;
    }
    bool isEmpty() {
        return currentSize == 0;
    }
    bool isFull() {
        return currentSize == maxSize;
    }
    void enqueue(Booking b) {
        if (isFull()) {
            cout << "Booking Queue is Full!\n";
            return;
        }
        rear = (rear + 1) % maxSize;
        arr[rear] = b;
        currentSize++;
        cout << "Booking added successfully!\n";
    }
    Booking dequeue() {
        if (isEmpty()) {
            cout << "No bookings available!\n";
            return {0, "", 0};
        }
        Booking b = arr[front];
        front = (front + 1) % maxSize;
        currentSize--;
        return b;
    }
    Booking peek() {
        if (isEmpty()) {
            cout << "No next booking!\n";
            return {0, "", 0};
        }
        return arr[front];
    }
    void display() {
        if (isEmpty()) {
            cout << "No bookings found.\n";
            return;
        }
        for (int i = 0; i < currentSize; i++) {
            int index = (front + i) % maxSize;
            cout << "\nCustomer ID: " << arr[index].customerID;
            cout << "\nCustomer Name: "  << arr[index].customerName;
            cout << "\nTickets: "<< arr[index].numberOfTickets << endl;
        }
    }
    int getSize() {
        return currentSize;
    }
};
int main() {
    CircularQueue q(5);
    int choice;
    do {
        cout << "\n CINEMA BOOKING SYSTEM\n";
        cout << "1. Book Tickets\n";
        cout << "2. Cancel First Booking\n";
        cout << "3. Display Next Booking\n";
        cout << "4. Display All Bookings\n";
        cout << "5. Total Bookings\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            Booking b;
            cout << "Enter Customer ID: ";
            cin >> b.customerID;
            cin.ignore();
            cout << "Enter Customer Name: ";
            getline(cin, b.customerName);
            cout << "Enter Number of Tickets: ";
            cin >> b.numberOfTickets;
            if (b.numberOfTickets <= 0) {
                cout << "Invalid ticket quantity!\n";
                break;
            }
            q.enqueue(b);
            break;
        }
        case 2: {
            Booking b = q.dequeue();
            if (b.customerID != 0) {
                cout << "Cancelled Booking: "<< b.customerName << endl;
            }
            break;
        }
        case 3: {
            Booking b = q.peek();
            if (b.customerID != 0) {
                cout << "Next Booking:\n";
                cout << "ID: " << b.customerID;
                cout << "\nName: " << b.customerName;
                cout << "\nTickets: "<< b.numberOfTickets << endl;
            }
            break;
        }
        case 4:
            q.display();
            break;
        case 5:
            cout << "Total bookings: "
                 << q.getSize() << endl;
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);
    return 0;
}
