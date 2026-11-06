#include <iostream>
#include <string>
using namespace std;
struct PrintJob {
    int jobID;
    string userName;
    int pages;
};
class CircularQueue {
private:
    PrintJob* arr;
    int maxSize;
    int front, rear, currentSize;
public:
    CircularQueue(int size) {
        maxSize = size;
        arr = new PrintJob[maxSize];
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
    void enqueue(PrintJob p) {
        if (isFull()) {
            cout << "Printer Queue is Full!\n";
            return;
        }
        rear = (rear + 1) % maxSize;
        arr[rear] = p;
        currentSize++;
        cout << "Print Job Submitted Successfully!\n";
    }
    PrintJob dequeue() {
        if (isEmpty()) {
            cout << "No print jobs available!\n";
            return {0, "", 0};
        }
        PrintJob p = arr[front];
        front = (front + 1) % maxSize;
        currentSize--;

        return p;
    }
    PrintJob peek() {
        if (isEmpty()) {
            cout << "No pending print jobs!\n";
            return {0, "", 0};
        }
        return arr[front];
    }
    void display() {
        if (isEmpty()) {
            cout << "No pending jobs.\n";
            return;
        }
        for (int i = 0; i < currentSize; i++) {
            int index = (front + i) % maxSize;
            cout << "\nJob ID: " << arr[index].jobID;
            cout << "\nUser Name: " << arr[index].userName;
            cout << "\nPages: " << arr[index].pages << endl;
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
        cout << "\nPRINTER JOB SYSTEM:\n";
        cout << "1. Submit Print Job\n";
        cout << "2. Process Print Job\n";
        cout << "3. Display Next Print Job\n";
        cout << "4. Display All Pending Jobs\n";
        cout << "5. Total Pending Jobs\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            PrintJob p;
            cout << "Enter Job ID: ";
            cin >> p.jobID;
            cin.ignore();
            cout << "Enter User Name: ";
            getline(cin, p.userName);
            cout << "Enter Number of Pages: ";
            cin >> p.pages;
            if (p.pages <= 0) {
                cout << "Invalid page count!\n";
                break;
            }
            q.enqueue(p);
            break;
        }
        case 2: {
            PrintJob p = q.dequeue();
            if (p.jobID != 0) {
                cout << "Printing Completed!\n";
                cout << "Job ID: " << p.jobID;
                cout << "\nUser: " << p.userName;
                cout << "\nPages: " << p.pages << endl;
            }
            break;
        }
        case 3: {
            PrintJob p = q.peek();
            if (p.jobID != 0) {
                cout << "Next Print Job:\n";
                cout << "Job ID: " << p.jobID;
                cout << "\nUser: " << p.userName;
                cout << "\nPages: " << p.pages << endl;
            }
            break;
        }
        case 4:
            q.display();
            break;
        case 5:
            cout << "Pending Jobs: " << q.getSize() << endl;
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
