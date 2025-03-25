#include <iostream>
#include <conio.h>
using namespace std;

struct Employee {
    int ID;
    string FirstName;
    string LastName;
    float HoursWorked;
    float HourlyRate;
};

Employee GetEmployeeInfo(int &i) {
    Employee *employee = new Employee;
    
    int employeeCount = i + 1;
    cout << "\nEnter the ID for Employee " << employeeCount << ": ";
    cin >> employee->ID;

    cout << "Enter the First Name for Employee " << employeeCount << ": ";
    cin >> employee->FirstName;

    cout << "Enter the Last Name for Employee " << employeeCount << ": ";
    cin >> employee->LastName;

    cout << "Enter the Hours Worked for Employee " << employeeCount << ": ";
    cin >> employee->HoursWorked;

    cout << "Enter the Hourly Rate for Employee " << employeeCount << ": ";
    cin >> employee->HourlyRate;

    return *employee;
}

void GetPayReport(Employee * employees, int &NUM_EMPLOYEES) {
    cout << "\nPay Report\n" << "----------\n";
    float totalPay = 0;
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        float pay = (employees[i].HoursWorked * employees[i].HourlyRate);
        totalPay += pay;
        cout << employees[i].ID << ". " << employees[i].FirstName << " " << employees[i].LastName << ": $" << (pay) << endl;
    }
    cout << "\nTotal Pay: $" << totalPay;
}

int main() {

    int NUM_EMPLOYEES;
    cout << "Enter the number of employees: ";
    cin >> NUM_EMPLOYEES;
    Employee * employees = new Employee[NUM_EMPLOYEES];

    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        Employee pEmployee = GetEmployeeInfo(i);
        employees[i] = pEmployee;
    }
    GetPayReport(employees, NUM_EMPLOYEES);

    delete[] employees;
	(void)_getch();
	return 0;
}