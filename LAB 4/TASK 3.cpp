#include <iostream>
#include <string>
using namespace std;
class LibraryItem {
public:
    virtual void display() const = 0;
    virtual string getName() const = 0;
    virtual ~LibraryItem() {}
};
class Book : public LibraryItem {
private:
    string title;
    string author;
    int pages;
public:
    Book() {
        title = "";
        author = "";
        pages = 0;
    }
    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }
    string getName() const override {
        return title;
    }
    int getPages() const {
        return pages;
    }
    void display() const override {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};
class Newspaper : public LibraryItem {
private:
    string name;
    string date;
    string edition;
public:
    Newspaper() {
        name = "";
        date = "";
        edition = "";
    }
    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }
    string getName() const override {
        return name;
    }
    string getEdition() const {
        return edition;
    }
    void display() const override {
        cout << "Newspaper Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }
};
template <typename T, typename Key, typename GetKey>
int linearSearch(T arr[], int size,Key key, GetKey getKey) {
    for (int i = 0; i < size; i++) {
        if (getKey(arr[i]) == key) {
            return i;
        }
    }
    return -1;
}
template <typename T, typename Key, typename GetKey>
int binarySearch(T arr[], int size,Key key, GetKey getKey) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        auto value = getKey(arr[mid]);
        if (value == key) {
            return mid;
        }
        else if (value < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}
template <typename T, typename Compare>
void selectionSort(T arr[], int size, Compare compare) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (compare(arr[j], arr[minIndex])) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
template <typename T>
class Library {
private:
    T items[10];
    int count;
public:
    Library() {
        count = 0;
    }
    void addItem(const T& item) {
        if (count < 10) {
            items[count] = item;
            count++;
        }
        else {
            cout << "Library is full!" << endl;
        }
    }
    void displayCollection() const {
        for (int i = 0; i < count; i++) {
            items[i].display();
            cout << endl;
        }
    }
    template <typename Compare>
    void sortItems(Compare compare) {
        selectionSort(items, count, compare);
    }
    template <typename Key, typename GetKey>
    T* searchItem(Key key, GetKey getKey) {
        int index = linearSearch(
            items, count, key, getKey
        );
        if (index != -1) {
            return &items[index];
        }
        return nullptr;
    }
    template <typename Key, typename GetKey>
    int searchBinary(Key key, GetKey getKey) {
        return binarySearch(
            items, count, key, getKey
        );
    }
};
int main() {
    Book book1("The Catcher in the Rye","J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird","Harper Lee", 324);
    
    Newspaper newspaper1("Washington Post","2024-10-13", "Morning Edition" );
    Newspaper newspaper2("The Times","2024-10-12","Weekend Edition");

    Library<Book> bookLibrary;
    Library<Newspaper> newspaperLibrary;
    bookLibrary.addItem(book1);
    bookLibrary.addItem(book2);

    newspaperLibrary.addItem(newspaper1);
    newspaperLibrary.addItem(newspaper2);

    cout << " Before Sorting\n";
    cout << "\nBooks:\n";
    bookLibrary.displayCollection();

    cout << "\nNewspapers:\n";
    newspaperLibrary.displayCollection();

    bookLibrary.sortItems([](const Book& a, const Book& b) {
            return a.getPages() < b.getPages();
        }
    );
    newspaperLibrary.sortItems([](const Newspaper& a, const Newspaper& b) {
            return a.getEdition() < b.getEdition();
        }
    );
    cout << "\nAfter Sorting\n";
    cout << "\nBooks:\n";
    bookLibrary.displayCollection();

    cout << "\nNewspapers:\n";
    newspaperLibrary.displayCollection();

    Book* foundBook = bookLibrary.searchItem(
        string("The Catcher in the Rye"),[](const Book& b) {
            return b.getName();
        }
    );

    if (foundBook != nullptr) {
        cout << "\nFound Book \n";
        foundBook->display();
    }
    else {
        cout << "\nBook not found.\n";
    }
    Newspaper* foundNewspaper = newspaperLibrary.searchItem(string("The Times"),[](const Newspaper& n) {
                return n.getName();
            }
    );
    if (foundNewspaper != nullptr) {
        cout << "\n Found Newspaper\n";
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found.\n";
    }
    int index = bookLibrary.searchBinary(324, [](const Book& b) {
            return b.getPages();
        }
    );
    if (index != -1) {
        cout << "\nBinary Search: Book with 324 pages found.\n";
    }
    else {
        cout << "\nBinary Search: Book not found.\n";
    }
    return 0;
}
