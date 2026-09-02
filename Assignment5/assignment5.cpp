#include<iostream>
using namespace std;
class Date {
    int day;
    int month;
    int year;
public:
    Date(void) :day(0), month(0), year(0) {};
    Date(int day, int month, int year) :day(day), month(month), year(year) {};
    void accepdate() {
        cout << "enter the day:" << endl;
        cin >> day;
        cout << "enter the month :" << endl;
        cin >> month;
        cout << "enter the year:" << endl;
        cin >> year;

    }
    void printRecord() {
        cout << "date :" << day << "-" << month << "-" << year << endl;
    }
};
class Person {
    string name;
    string address;
    Date birthdate;
public:
    Person(void) :name(""), address(address) {};
    Person(string name, string address, Date birthdate) :name(name), address(address), birthdate(birthdate) {};
    Person(string name, string address, int day, int month, int year) :name(name), address(address), birthdate(day, month, year) {};
    void acceptrecord() {
        cout << "-----------------------------------------" << endl;
        cout << "persons details :" << endl;
        cout << "enter the name :" << endl;
        cin >> name;
        cin.ignore();
        cout << "enter the address :" << endl;
        // cin >> address;
        getline(cin, address);
        birthdate.accepdate();
        cout << "-----------------------------------------" << endl;

    }
    void printReacord() {
        cout << "-----------------------------------------" << endl;
        cout << "name :" << name << endl;
        cout << "address :" << address << endl;
        birthdate.printRecord();
        cout << "-----------------------------------------" << endl;
    }
};

/*Create a class Student with data members id, marks, course and joining date, end date. The joining
date and end date should be of type date.*/
class Student {
    int id;
    double marks;
    string course;
    Date joindate;
    Date end_date;
public:
    Student(void) :id(0), marks(0.0), course("") {};
    Student(int id, double mark, Date joindate, Date end_date) :id(id), marks(marks), course(course), joindate(joindate), end_date(end_date) {};
    void acceptrecord() {
        cout << "-----------------------------------------" << endl;
        cout << "Enter the student datails :" << endl;
        cout << "enter id :" << endl;
        cin >> id;
        cout << "enter the marks :" << endl;
        cin >> marks;
        cout << "enter course name :" << endl;
        cin >> course;
        // getline(cin, course);
        cout << "enter the course name :" << endl;
        cout << "enter the joining date:" << endl;
        joindate.accepdate();
        cout << "enter the end date :" << endl;
        end_date.accepdate();
        cout << "-----------------------------------------" << endl;
    }
    void printRecord() {
        cout << "-----------------------------------------" << endl;
        cout << " id :" << id << endl;
        cout << "marks :" << marks << endl;
        cout << "course :" << course << endl;
        cout << "join date :" << endl;
        joindate.printRecord();
        cout << "end date :" << endl;
        end_date.printRecord();
        cout << "-----------------------------------------" << endl;

    }

};

int main() {
    Person p;
    p.acceptrecord();
    p.printReacord();
    Student s;
    s.acceptrecord();
    s.printRecord();


}