#include<iostream>
using namespace std;

template<class T>
class list {
protected:
    T *arr;
    int maxsize;
    int currentsize;
public:
    list(int m = 10) {
        maxsize = (m > 0) ? m : 10;
        currentsize = 0;
        arr = new T[maxsize];
    }

    list(const list &l) {
        maxsize = l.maxsize;
        currentsize = l.currentsize;
        arr = new T[maxsize];
        for (int i = 0; i < currentsize; i++) {
            arr[i] = l.arr[i];
        }
    }

    virtual void addelementfirstindex(T) = 0;
    virtual void addelementlastindex(T) = 0;
    virtual T removeelementfromend() = 0;
    virtual void removeelementfromstart() = 0;

    virtual ~list() {
        delete[] arr;
    }
};

template <class T>
class mylist : public list<T> {
public:
    mylist(int m = 10) : list<T>(m) {}

    mylist(const mylist &L) : list<T>(L) {}

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

template <class T>
class CustomList : public mylist<T> {
private:
    bool isPrime(T n) {
        if (n < 2) return false;
        for (T i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    void rotateLeft(int start, int end, int times) {
        int len = end - start + 1;
        if (len <= 1) return;
        times = times % len;
        for (int t = 0; t < times; t++) {
            T temp = this->arr[start];
            for (int i = start; i < end; i++) {
                this->arr[i] = this->arr[i + 1];
            }
            this->arr[end] = temp;
        }
    }

    void rotateRight(int start, int end, int times) {
        int len = end - start + 1;
        if (len <= 1) return;
        times = times % len;
        for (int t = 0; t < times; t++) {
            T temp = this->arr[end];
            for (int i = end; i > start; i--) {
                this->arr[i] = this->arr[i - 1];
            }
            this->arr[start] = temp;
        }
    }

public:
    CustomList(int m = 10) : mylist<T>(m) {}

    CustomList(const CustomList &L) : mylist<T>(L) {}

    ~CustomList() {}

    T sum_ofPrime() {
        T sum = 0;
        for (int i = 0; i < this->currentsize; i++) {
            if (isPrime(this->arr[i])) {
                sum += this->arr[i];
            }
        }
        return sum;
    }

    T secondMaxEven() {
        T max1 = -1, max2 = -1;
        for (int i = 0; i < this->currentsize; i++) {
            if (this->arr[i] % 2 == 0) {
                if (this->arr[i] > max1) {
                    max2 = max1;
                    max1 = this->arr[i];
                } else if (this->arr[i] > max2 && this->arr[i] != max1) {
                    max2 = this->arr[i];
                }
            }
        }
        return max2;
    }

    T secondMinOdd() {
        T min1 = -1, min2 = -1;
        for (int i = 0; i < this->currentsize; i++) {
            if (this->arr[i] % 2 != 0) {
                min1 = this->arr[i];
                break;
            }
        }
        for (int i = 0; i < this->currentsize; i++) {
            if (this->arr[i] % 2 != 0) {
                if (this->arr[i] < min1) {
                    min2 = min1;
                    min1 = this->arr[i];
                } else if (this->arr[i] < min2 && this->arr[i] != min1) {
                    min2 = this->arr[i];
                } else if (min2 == -1 && this->arr[i] != min1) {
                    min2 = this->arr[i];
                }
            }
        }
        return min2;
    }

    void printDuplicates() {
        bool found = false;
        bool *printed = new bool[this->currentsize];
        for (int i = 0; i < this->currentsize; i++) printed[i] = false;

        for (int i = 0; i < this->currentsize; i++) {
            if (printed[i]) continue;
            int count = 1;
            for (int j = i + 1; j < this->currentsize; j++) {
                if (this->arr[i] == this->arr[j]) {
                    count++;
                    printed[j] = true;
                }
            }
            if (count > 1) {
                cout << this->arr[i] << " ";
                found = true;
            }
        }
        if (!found) cout << "No duplicates found";
        cout << "\n";
        delete[] printed;
    }

    void rotateClockwaise(int r) {
        if (this->currentsize <= 1) return;
        int mid = this->currentsize / 2;
        rotateRight(0, mid - 1, r);
        rotateRight(mid, this->currentsize - 1, r);
    }

    void rotateanitclockwaise(int rt) {
        if (this->currentsize <= 1) return;
        int mid = this->currentsize / 2;
        rotateLeft(0, mid - 1, rt);
        rotateLeft(mid, this->currentsize - 1, rt);
    }
};

int main() {
    CustomList<int> l;
    int choice, x, index, r;

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
        cout << "\n12. Sum of Primes";
        cout << "\n13. Second Max Even";
        cout << "\n14. Second Min Odd";
        cout << "\n15. Print Duplicates";
        cout << "\n16. Rotate Clockwise";
        cout << "\n17. Rotate Anti-Clockwise";
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

        case 12:
            cout << "Sum of primes: " << l.sum_ofPrime() << "\n";
            break;

        case 13:
            cout << "Second max even: " << l.secondMaxEven() << "\n";
            break;

        case 14:
            cout << "Second min odd: " << l.secondMinOdd() << "\n";
            break;

        case 15:
            cout << "Duplicates: ";
            l.printDuplicates();
            break;

        case 16:
            cout << "Enter rotations: ";
            cin >> r;
            l.rotateClockwaise(r);
            cout << "Rotated clockwise.\n";
            break;

        case 17:
            cout << "Enter rotations: ";
            cin >> r;
            l.rotateanitclockwaise(r);
            cout << "Rotated anti-clockwise.\n";
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