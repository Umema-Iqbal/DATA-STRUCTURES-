//#include <iostream>
//using namespace std;
//
//template <class T>
//class AbstractStack {
//public:
//    virtual void push(T value) = 0;
//    virtual T pop() = 0;
//    virtual T top() const = 0;
//    virtual bool isEmpty() const = 0;
//    virtual bool isFull() const = 0;
//    virtual ~AbstractStack() {}
//};
//
//template <class T>
//class myStack : public AbstractStack<T> {
//    T* arr;
//    T* minArr;
//    int size, count;
//
//public:
//    myStack(int s) {
//        size = s;
//        count = 0;
//        arr = new T[size];
//        minArr = new T[size];
//    }
//
//    //void push(T value) override {
//        if (isFull()) {
//            cout << "Stack is full!\n";
//            return;
//        }
//
//        arr[count] = value;
//
//        if (count == 0)
//            minArr[count] = value;
//        else if (value < minArr[count - 1])
//            minArr[count] = value;
//        else
//            minArr[count] = minArr[count - 1];
//
//        count++;
//        cout << "Value pushed.\n";
//    }
//
//    T pop() override {
//        if (isEmpty()) {
//            cout << "Stack is empty!\n";
//            return T{};
//        }
//
//        return arr[--count];
//    }
//    T top() const override {
//        if (isEmpty())
//            return T{};
//        return arr[count - 1];
//    }
//    T getMin() const {
//        if (isEmpty())
//            return T{};
//        return minArr[count - 1];
//    }
//
//    bool isEmpty() const override {
//        return count == 0;
//    }
//
//    bool isFull() const override {
//        return count == size;
//    }
//
//    void display() const {
//        if (isEmpty()) {
//            cout << "Stack is empty!\n";
//            return;
//        }
//
//        for (int i = count - 1; i >= 0; i--)
//            cout << arr[i] << endl;
//    }
//
//    ~myStack() {
//        delete[] arr;
//        delete[] minArr;
//    }
//};
//
//int main() {
//    int size, choice, value;
//
//    cout << "Enter stack size: ";
//    cin >> size;
//
//    if (size <= 0) {
//        cout << "Invalid size!\n";
//        return 1;
//    }
//
//    myStack<int> s(size);
//
//    do {
//        cout << "\n1. Push element\n";
//        cout << "2. Pop element\n";
//        cout << "3. Show top element\n";
//        cout << "4. Check if stack is empty\n";
//        cout << "5. Check if stack is full\n";
//        cout << "6. Display stack elements\n";
//        cout << "7. Show minimum element\n";
//        cout << "8. Exit\n";
//        cout << "Enter choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            cout << "Enter value: ";
//            cin >> value;
//            s.push(value);
//            break;
//
//        case 2:
//            if (!s.isEmpty())
//                cout << "Popped: " << s.pop() << endl;
//            else
//                cout << "Stack is empty!\n";
//            break;
//
//        case 3:
//            if (!s.isEmpty())
//                cout << "Top element: " << s.top() << endl;
//            else
//                cout << "Stack is empty!\n";
//            break;
//
//        case 4:
//            cout << (s.isEmpty() ? "Stack is empty\n"
//                : "Stack is not empty\n");
//            break;
//
//        case 5:
//            cout << (s.isFull() ? "Stack is full\n"
//                : "Stack is not full\n");
//            break;
//
//        case 6:
//            s.display();
//            break;
//
//        case 7:
//            if (!s.isEmpty())
//                cout << "Minimum element: " << s.getMin() << endl;
//            else
//                cout << "Stack is empty!\n";
//            break;
//
//        case 8:
//            cout << "Program ended.\n";
//            break;
//
//        default:
//            cout << "Invalid choice!\n";
//        }
//
//    } while (choice != 8);
//
//    return 0;
//}
