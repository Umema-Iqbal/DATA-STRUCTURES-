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
//    int size, count;
//
//public:
//    myStack(int s) {
//        size = s;
//        count = 0;
//        arr = new T[size];
//    }
//
//    void push(T value) override {
//        if (isFull())
//            cout << "Stack is full!\n";
//        else {
//            arr[count++] = value;
//            cout << "Value pushed.\n";
//        }
//    }
//
//    T pop() override {
//        if (isEmpty()) {
//            cout << "Stack is empty!\n";
//            return T{};
//        }
//        return arr[--count];
//    }
//
//    T top() const override {
//        if (isEmpty())
//            return T{};
//        return arr[count - 1];
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
//        cout << "\n1. Push\n";
//        cout << "2. Pop\n";
//        cout << "3. Top\n";
//        cout << "4. Check Empty\n";
//        cout << "5. Check Full\n";
//        cout << "6. Display\n";
//        cout << "7. Exit\n";
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
//                cout << "Top: " << s.top() << endl;
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
//            cout << "Program ended.\n";
//            break;
//
//        default:
//            cout << "Invalid choice!\n";
//        }
//
//    } while (choice != 7);
//
//    return 0;
//}
