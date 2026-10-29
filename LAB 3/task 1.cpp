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
        maxsize = m;
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

    ~list() {
        delete[] arr;
    }
};