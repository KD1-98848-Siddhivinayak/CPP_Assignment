#include <iostream>
using namespace std;
class Employee {
    int id;
    double salary;
public:
    Employee(void) :id(0), salary(0.0) {};
    Employee(int id, double salary) :id(id), salary(salary) {};


    void setId(int id) {
        this->id = id;

    }
    int getId() {
        return this->id;

    }
    void setSalary(double salary) {
        this->salary = salary;
    }
    double getSalary() {
        return salary;
    }
    void accept() {
        cout << "id :" << endl;
        cin >> id;
        cout << "salary :" << endl;
        cin >> salary;

    }
    void display() {
        cout << "Id:" << id << endl;
        cout << "salary :" << salary << endl;

    }

};
class Manager :virtual public Employee {
    double bonus;
public:
    Manager(void) :bonus(0) {};
    Manager(int bonus) :bonus(bonus) {};
    Manager(int id, double salary, double bonus) :bonus(bonus), Employee(id, salary) {};
    void setBonus(double bonus) {
        this->bonus = bonus;
    }
    double getBonus() {
        return  bonus;
    }
    void accept() {
        Manager::accept();
        this->acceptManager();
    }
    void acceptManager() {
        cout << "bonus " << endl;
        cin >> bonus;
    }
    void display() {
        Manager::display();
        this->displayManager();
    }
    void displayManager() {
        cout << "bonus :" << bonus<<endl;
    }


};

class Salesman : virtual public Employee {
    double commission;
public:
    Salesman(void) :commission(0) {};
    Salesman(double commission) :commission(commission) {};
    Salesman(int id, double salary, double commission) :commission(commission), Employee(id, salary) {};
    void setCommission(double commission) {
        this->commission = commission;

    }
    double getCommission(double commission) {
        return commission;
    }
    void accept() {
        Employee::accept();
        this->commission;
    }
    void acceptSalesman() {
        cout << "commission :" << endl;
        cin >> commission;

    }
    void display() {
        Employee::display();
        this->displaySalesman();

    }
    void displaySalesman() {
        cout << "commission " << commission << endl;
    }

};

class SalesManager :public Salesman, public Manager {
public:
     SalesManager(void)=default; 
    SalesManager(int id, double salary, double bonus, double commision) :Employee(id, salary), Salesman(bonus), Manager(commision) {};

    void accept() {
        Employee::accept();
        Salesman::acceptSalesman();
        Manager::acceptManager();

    }
    void display() {
        Employee::display();
        Manager::displayManager();
        Salesman::displaySalesman();
    }
};

int main() {
    // Employee e;
    // e.accept();
    // e.display();
    // Salesman s;
    // s.accept();
    // s.display();
    // Manager m;
    // m.accept();
    // m.display();
    SalesManager sm;
    sm.accept();
    sm.display();


}