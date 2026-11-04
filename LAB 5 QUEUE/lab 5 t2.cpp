//#include <iostream>
//using namespace std;
//class Stack {
//private:
//    int* arr;
//    int topIndex;
//    int capacity;
//public:
//    Stack(int size) {
//        capacity = size;
//        arr = new int[capacity];
//        topIndex = -1;
//    }
//    void push(int value) {
//        if (topIndex == capacity - 1) {
//            cout << "Stack is Full!" << endl;
//            return;
//        }
//        arr[++topIndex] = value;
//    }
//    int pop() {
//        if (isEmpty()) {
//            return -1;
//        }
//        return arr[topIndex--];
//    }
//    int top() {
//        if (isEmpty()) {
//            return -1;
//        }
//        return arr[topIndex];
//    }
//    bool isEmpty() {
//        return topIndex == -1;
//    }
//    ~Stack() {
//        delete[] arr;
//    }
//};
//class myQueue {
//private:
//    Stack stack1;
//    Stack stack2;
//    void transfer() {
//        while (!stack1.isEmpty()) {
//            stack2.push(stack1.pop());
//        }
//    }
//public:
//    myQueue(int size) : stack1(size), stack2(size) {
//    }
//    void enQueue(int value) {
//        stack1.push(value);
//        cout << value << " inserted into Queue." << endl;
//    }
//    int deQueue() {
//        if (stack2.isEmpty()) {
//            transfer();
//        }
//        if (stack2.isEmpty()) {
//            cout << "Queue is Empty!" << endl;
//            return -1;
//        }
//        return stack2.pop();
//    }
//    int front() {
//        if (stack2.isEmpty()) {
//            transfer();
//        }
//        if (stack2.isEmpty()) {
//            cout << "Queue is Empty!" << endl;
//            return -1;
//        }
//        return stack2.top();
//    }
//    void display() {
//        if (stack1.isEmpty() && stack2.isEmpty()) {
//            cout << "Queue is Empty!" << endl;
//            return;
//        }
//        cout << "Queue Elements (Front to Rear): ";
//        Stack temp1(1000);
//        while (!stack2.isEmpty()) {
//            int value = stack2.pop();
//            cout << value << " ";
//            temp1.push(value);
//        }
//        while (!temp1.isEmpty()) {
//            stack2.push(temp1.pop());
//        }
//        Stack temp2(1000);
//        Stack temp3(1000);
//        while (!stack1.isEmpty()) {
//            temp2.push(stack1.pop());
//        }
//        while (!temp2.isEmpty()) {
//            int value = temp2.pop();
//            cout << value << " ";
//            temp3.push(value);
//        }
//        while (!temp3.isEmpty()) {
//            stack1.push(temp3.pop());
//        }
//        cout << endl;
//    }
//    bool isEmpty() {
//        return stack1.isEmpty() && stack2.isEmpty();
//    }
//};
//int main() {
//
//    int size;
//    cout << "Enter Maximum Queue Size: ";
//    cin >> size;
//    if (size <= 0) {
//        cout << "Invalid Queue Size!" << endl;
//        return 0;
//    }
//    myQueue q(size);
//    int choice, value;
//    do {
//        cout << "\n QUEUE USING TWO STACKS" << endl;
//        cout << "1. Enqueue (Insert Element)" << endl;
//        cout << "2. Dequeue (Remove Element)" << endl;
//        cout << "3. Front Element" << endl;
//        cout << "4. Display Elements" << endl;
//        cout << "5. Check Empty" << endl;
//        cout << "0. Exit" << endl;
//        cout << "\nEnter Your Choice: ";
//        cin >> choice;
//        switch (choice) {
//        case 1:
//            cout << "Enter Value: ";
//            cin >> value;
//            q.enQueue(value);
//            break;
//        case 2:
//            if (!q.isEmpty()) {
//                cout << "Deleted Element: "
//                    << q.deQueue() << endl;
//            }
//            else {
//                cout << "Queue is Empty!" << endl;
//            }
//            break;
//        case 3:
//            if (!q.isEmpty()) {
//                cout << "Front Element: "
//                    << q.front() << endl;
//            }
//            else {
//                cout << "Queue is Empty!" << endl;
//            }
//            break;
//        case 4:
//            q.display();
//            break;
//        case 5:
//            if (q.isEmpty())
//                cout << "Queue is Empty." << endl;
//            else
//                cout << "Queue is Not Empty." << endl;
//            break;
//        case 0:
//            cout << "Program Exited Successfully!" << endl;
//            break;
//        default:
//            cout << "Invalid Choice!" << endl;
//        }
//    } while (choice != 0);
//
//    return 0;
//}
