#include <iostream>
using namespace std;

class Course {
public:
    virtual void duration() const = 0;
    virtual ~Course() = default;
};
template <typename T>
class OnlineCourse : public Course {
private:
    T weeks;
    T hoursPerWeek;

public:
    OnlineCourse(T w, T h): weeks(w), hoursPerWeek(h) {}
    void duration() const override {
        cout << "Online Course Duration: "<< weeks << " weeks" << endl;
        cout << "Total Study Hours: "<< weeks * hoursPerWeek << " hours" << endl;
    }
};
template <typename T>
class OfflineCourse : public Course {
private:
    T months;
    T hoursPerDay;

public:
    OfflineCourse(T m, T h): months(m), hoursPerDay(h) {}
    void duration() const override {
        cout << "Offline Course Duration: "<< months << " months" << endl;
        cout << "Hours Per Day: "<< hoursPerDay << " hours" << endl;
    }
};
int main() {
    OnlineCourse<int> online(8, 3);
    OfflineCourse<int> offline(6, 4);
    Course* course = &online;
    cout << " Online Course " << endl;
    course->duration();
    cout << "\nOffline Course" << endl;
    course = &offline;
    course->duration();

    return 0;
}
