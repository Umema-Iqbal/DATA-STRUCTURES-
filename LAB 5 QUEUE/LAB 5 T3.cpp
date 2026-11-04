//#include <iostream>
//using namespace std;
//
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
//        if (topIndex == capacity - 1)
//            return;
//        arr[++topIndex] = value;
//    }
//    int pop() {
//        if (isEmpty())
//            return -1;
//        return arr[topIndex--];
//    }
//    bool isEmpty() {
//        return topIndex == -1;
//    }
//    ~Stack() {
//        delete[] arr;
//    }
//};
//class Queue {
//private:
//    int* arr;
//    int capacity;
//    int frontIndex;
//    int rearIndex;
//    int count;
//public:
//    Queue(int size) {
//        capacity = size;
//        arr = new int[capacity];
//        frontIndex = 0;
//        rearIndex = -1;
//        count = 0;
//    }
//    void enqueue(int value) {
//        if (count == capacity) {
//            cout << "Queue is Full!" << endl;
//            return;
//        }
//        rearIndex = (rearIndex + 1) % capacity;
//        arr[rearIndex] = value;
//        count++;
//    }
//    int dequeue() {
//        if (isEmpty())
//            return -1;
//        int value = arr[frontIndex];
//        frontIndex = (frontIndex + 1) % capacity;
//        count--;
//        return value;
//    }
//    int front() {
//        if (isEmpty())
//            return -1;
//        return arr[frontIndex];
//    }
//    bool isEmpty() {
//        return count == 0;
//    }
//    int size() {
//        return count;
//    }
//    void display() {
//        if (isEmpty()) {
//            cout << "Queue is Empty!" << endl;
//            return;
//        }
//        for (int i = 0; i < count; i++) {
//            cout << arr[(frontIndex + i) % capacity] << " ";
//        }
//        cout << endl;
//    }
//    void reverseFirstK(int k) {
//        if (k <= 1) {
//            cout << "No Reversal Needed!" << endl;
//            return;
//        }
//        if (k > count) {
//            cout << "K is Greater Than Queue Size!" << endl;
//            cout << "No Reversal Performed." << endl;
//            return;
//        }
//        Stack s(k);
//        for (int i = 0; i < k; i++) {
//            s.push(dequeue());
//        }
//        while (!s.isEmpty()) {
//            enqueue(s.pop());
//        }
//        int remaining = count - k;
//        for (int i = 0; i < remaining; i++) {
//            enqueue(dequeue());
//        }
//        cout << "First " << k << " elements reversed successfully!" << endl;
//    }
//    ~Queue() {
//        delete[] arr;
//    }
//};
//int main() {
//    int n, value, k;
//    cout << "Enter Number of Queue Elements: ";
//    cin >> n;
//    if (n < 0) {
//        cout << "Invalid Queue Size!" << endl;
//        return 0;
//    }
//    Queue q(n > 0 ? n : 1);
//    for (int i = 0; i < n; i++) {
//        cout << "Enter Element " << i + 1 << ": ";
//        cin >> value;
//        q.enqueue(value);
//    }
//    cout << "\nOriginal Queue: ";
//    q.display();
//    cout << "\nEnter K: ";
//    cin >> k;
//    if (k < 0) {
//        cout << "Invalid K!" << endl;
//        return 0;
//    }
//    q.reverseFirstK(k);
//    cout << "\nFinal Queue: ";
//    q.display();
//
//    return 0;
//}
