#include<iostream>
using namespace std;

template<class T>
class list {
protected:
    T *arr;
    int maxsize;
    int currentsize;
public:
    // Parameterized constructor
    list(int m = 10) {
        maxsize = (m > 0) ? m : 10;
        currentsize = 0;
        arr = new T[maxsize];
    }

    // Copy constructor
    list(const list &l) {
        maxsize = l.maxsize;
        currentsize = l.currentsize;
        arr = new T[maxsize];
        for (int i = 0; i < currentsize; i++) {
            arr[i] = l.arr[i];
        }
    }

    // Pure virtual functions
    virtual void addelementfirstindex(T) = 0;
    virtual void addelementlastindex(T) = 0;
    virtual T removeelementfromend() = 0;
    virtual void removeelementfromstart() = 0;

    // Virtual destructor
    virtual ~list() {
        delete[] arr;
    }
};

template <class T>
class mylist : public list<T> {
public:
    // Parameterized constructor
    mylist(int m = 10) : list<T>(m) {}

    // Copy constructor
    mylist(const mylist &L) : list<T>(L) {}

    // Destructor
    ~mylist() {}
    bool empty() {
        return this->currentsize == 0;
    }

    bool full() {
        return this->currentsize == this->maxsize;
    }

    int size() {
        return this->currentsize;
    }
    void addelementfirstindex(T x) override {
        if (full()) {
            cout << "List is full.\n";
            return;
        }
        for (int i = this->currentsize; i > 0; i--) {
            this->arr[i] = this->arr[i - 1];
        }
        this->arr[0] = x;
        this->currentsize++;
    }

    void addelementlastindex(T x) override {
        if (full()) {
            cout << "List is full.\n";
            return;
        }
        this->arr[this->currentsize++] = x;
    }

    T removeelementfromend() override {
        if (empty()) return T();
        return this->arr[--this->currentsize];
    }

    void removeelementfromstart() override {
        if (empty()) return;
        for (int i = 0; i < this->currentsize - 1; i++) {
            this->arr[i] = this->arr[i + 1];
        }
        this->currentsize--;
    }
    bool insertAt(int index, T x) {
        if (full() || index < 0 || index > this->currentsize) {
            return false;
        }
        for (int i = this->currentsize; i > index; i--) {
            this->arr[i] = this->arr[i - 1];
        }
        this->arr[index] = x;
        this->currentsize++;
        return true;
    }

    T last() {
        if (empty()) return T();
        return this->arr[this->currentsize - 1];
    }

    bool search(T x) {
        for (int i = 0; i < this->currentsize; i++) {
            if (this->arr[i] == x) return true;
        }
        return false;
    }

    void display() {
        if (empty()) {
            cout << "List is empty.\n";
            return;
        }
        cout << "[ ";
        for (int i = 0; i < this->currentsize; i++) {
            cout << this->arr[i] << " ";
        }
        cout << "]\n";
    }
};

int main() {
    mylist<int> l;  
    int choice, x, index;

    do {
        cout << "\n1. Add at Start";
        cout << "\n2. Add at End";
        cout << "\n3. Insert at Index";
        cout << "\n4. Remove from Start";
        cout << "\n5. Remove from End";
        cout << "\n6. Check Empty";
        cout << "\n7. Check Full";
        cout << "\n8. Size";
        cout << "\n9. Last Element";
        cout << "\n10. Search";
        cout << "\n11. Display";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            l.addelementfirstindex(x);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> x;
            l.addelementlastindex(x);
            break;

        case 3:
            cout << "Enter index and value: ";
            cin >> index >> x;
            cout << (l.insertAt(index, x) ? "Inserted\n" : "Failed\n");
            break;

        case 4:
            l.removeelementfromstart();
            cout << "Removed from start.\n";
            break;

        case 5:
            cout << "Removed from end: " << l.removeelementfromend() << "\n";
            break;

        case 6:
            cout << (l.empty() ? "List is empty\n" : "Not empty\n");
            break;

        case 7:
            cout << (l.full() ? "List is full\n" : "Not full\n");
            break;

        case 8:
            cout << "Size: " << l.size() << "\n";
            break;

        case 9:
            if (!l.empty()) cout << "Last: " << l.last() << "\n";
            else cout << "List is empty\n";
            break;

        case 10:
            cout << "Enter value: ";
            cin >> x;
            cout << (l.search(x) ? "Found\n" : "Not found\n");
            break;

        case 11:
            l.display();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}