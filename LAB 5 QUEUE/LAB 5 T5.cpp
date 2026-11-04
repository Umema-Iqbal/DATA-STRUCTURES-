//
//#include <iostream>
//using namespace std;
//
//template <typename T>
//class Queue {
//private:
//    T arr[100][100];
//    int frontIndex;
//    int rear;
//    int count;
//    int capacity;
//
//public:
//    Queue(int size) {
//        capacity = size;
//        frontIndex = 0;
//        rear = -1;
//        count = 0;
//    }
//
//    void enqueue(T document_name[]) {
//        if (count == capacity) {
//            cout << "Print Queue is Full!" << endl;
//            return;
//        }
//
//        rear = (rear + 1) % capacity;
//
//        int i = 0;
//
//        while (document_name[i] != '\0' && i < 99) {
//            arr[rear][i] = document_name[i];
//            i++;
//        }
//
//        arr[rear][i] = '\0';
//        count++;
//
//        cout << "Document added to print queue successfully!" << endl;
//    }
//
//    void dequeue() {
//        if (isEmpty()) {
//            cout << "Print Queue is Empty!" << endl;
//            return;
//        }
//
//        cout << "Printing Document: " << arr[frontIndex] << endl;
//
//        frontIndex = (frontIndex + 1) % capacity;
//        count--;
//    }
//
//    void front() {
//        if (isEmpty()) {
//            cout << "Print Queue is Empty!" << endl;
//            return;
//        }
//
//        cout << "Next Document: " << arr[frontIndex] << endl;
//    }
//
//    bool isEmpty() {
//        return count == 0;
//    }
//
//    bool isFull() {
//        return count == capacity;
//    }
//
//    void display() {
//        if (isEmpty()) {
//            cout << "No Pending Print Jobs!" << endl;
//            return;
//        }
//
//        cout << "\nPending Print Jobs:" << endl;
//
//        for (int i = 0; i < count; i++) {
//            cout << i + 1 << ". "
//                << arr[(frontIndex + i) % capacity] << endl;
//        }
//    }
//};
//
//int main() {
//    Queue<char> q(100);
//
//    int choice;
//    char document_name[100];
//
//    do {
//        cout << "\n===== DOCUMENT PRINTING SYSTEM =====" << endl;
//        cout << "1. Add New Print Job" << endl;
//        cout << "2. Print Document" << endl;
//        cout << "3. Front Document" << endl;
//        cout << "4. Display Print Queue" << endl;
//        cout << "5. Check Empty" << endl;
//        cout << "0. Exit" << endl;
//
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//
//        case 1:
//            cout << "Enter Document Name: ";
//            cin.ignore(1000, '\n');
//            cin.getline(document_name, 100);
//
//            q.enqueue(document_name);
//            break;
//
//        case 2:
//            q.dequeue();
//            break;
//
//        case 3:
//            q.front();
//            break;
//
//        case 4:
//            q.display();
//            break;
//
//        case 5:
//            if (q.isEmpty())
//                cout << "Print Queue is Empty!" << endl;
//            else
//                cout << "Print Queue is Not Empty!" << endl;
//            break;
//
//        case 0:
//            cout << "Exiting Document Printing System..." << endl;
//            break;
//
//        default:
//            cout << "Invalid Choice! Try Again." << endl;
//        }
//
//    } while (choice != 0);
//
//    return 0;
//}
