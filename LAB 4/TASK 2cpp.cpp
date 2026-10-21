#include <iostream>
using namespace std;
class Employee {
public:
    virtual double calculateSalary() const = 0;
    virtual ~Employee() = default;
};
template <typename T>
class FullTimeEmployee : public Employee {
private:
    T salary;
public:
    FullTimeEmployee(T s) : salary(s) {}
    double calculateSalary() const override {
        return static_cast<double>(salary);
    }
};
template <typename T>
class PartTimeEmployee : public Employee {
private:
    T hoursWorked;
    T hourlyRate;
public:
    PartTimeEmployee(T h, T r): hoursWorked(h), hourlyRate(r) {}
    double calculateSalary() const override {
        return static_cast<double>(
            hoursWorked * hourlyRate
            );
    }
};
int main() {
    FullTimeEmployee<double> fullTime(80000);
    PartTimeEmployee<double> partTime(80, 500);
    Employee* employee = &fullTime;
    cout << "Full-Time Employee Salary: "<< employee->calculateSalary() << endl;

    employee = &partTime;
    cout << "Part-Time Employee Salary: " << employee->calculateSalary() << endl;

    return 0;
}
