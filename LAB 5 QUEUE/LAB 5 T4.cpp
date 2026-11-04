#include <iostream>
using namespace std;
class CustomerSupport {
private:
    int* arr;
    int capacity;
    int frontIndex;
    int rearIndex;
    int count;
public:
    CustomerSupport(int size) {
        capacity = size;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }
    void enqueue(int ticket_id) {
        if (isFull()) {
            cout << "Ticket Queue is Full!" << endl;
            return;
        }
        if (ticket_id < 1000 || ticket_id > 9999) {
            cout << "Invalid Ticket ID! Enter a 4-digit ID." << endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            if (arr[(frontIndex + i) % capacity] == ticket_id) {
                cout << "Ticket ID already exists!" << endl;
                return;
            }
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = ticket_id;
        count++;
        cout << "Ticket #" << ticket_id << " added successfully!" << endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "No Pending Tickets!" << endl;
            return;
        }
        int ticket = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        cout << "Ticket #" << ticket << " has been resolved successfully!" << endl;
    }
    void front() {
        if (isEmpty()) {
            cout << "No Pending Tickets!" << endl;
            return;
        }
        cout << "Next Ticket to Resolve: #" << arr[frontIndex] << endl;
    }
    bool isEmpty() {
        return count == 0;
    }
    bool isFull() {
        return count == capacity;
    }
    void display() {
        if (isEmpty()) {
            cout << "No Pending Tickets!" << endl;
            return;
        }
        cout << "\nPENDING SUPPORT TICKETS" << endl;
        for (int i = 0; i < count; i++) {
            cout << "Ticket #"
                << arr[(frontIndex + i) % capacity]
                << endl;
        }
        cout << "===================================" << endl;
    }
    ~CustomerSupport() {
        delete[] arr;
    }
};
int main() {
    int size;
    cout << "Enter Maximum Number of Tickets: ";
    cin >> size;
    if (size <= 0) {
        cout << "Invalid Queue Size!" << endl;
        return 0;
    }
    CustomerSupport q(size);
    int choice, ticket_id;
    do {
        cout << "\n CUSTOMER SUPPORT SYSTEM" << endl;
        cout << "1. Add New Ticket" << endl;
        cout << "2. Resolve Ticket" << endl;
        cout << "3. Next Ticket" << endl;
        cout << "4. Display Pending Tickets" << endl;
        cout << "5. Check Queue Empty" << endl;
        cout << "6. Check Queue Full" << endl;
        cout << "0. Exit" << endl;
        cout << "\nEnter Your Choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter 4-Digit Ticket ID: ";
            cin >> ticket_id;
            q.enqueue(ticket_id);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.front();
            break;

        case 4:
            q.display();
            break;

        case 5:
            if (q.isEmpty())
                cout << "Ticket Queue is Empty." << endl;
            else
                cout << "Ticket Queue is Not Empty." << endl;
            break;

        case 6:
            if (q.isFull())
                cout << "Ticket Queue is Full." << endl;
            else
                cout << "Ticket Queue is Not Full." << endl;
            break;

        case 0:
            cout << "Customer Support System Closed!" << endl;
            break;

        default:
            cout << "Invalid Choice! Try Again." << endl;
        }

    } while (choice != 0);

    return 0;
}
