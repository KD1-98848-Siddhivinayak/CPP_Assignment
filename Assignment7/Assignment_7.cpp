#include <iostream>
using namespace std;

class InvalidInputException
{
private:
    string message;

public:
    InvalidInputException(string message)
    {
        this->message = message;
    }
    string getMessage(void)
    {
        return this->message;
    }
};

class Employee
{

private:
    int Id;
    double salary;

public:
    Employee() : Id(101), salary(0.0) {};

    Employee(int Id, double salary) : Id(Id), salary(salary) {};

    void setId(int Id)
    {
        this->Id = Id;
    }

    int getId()
    {
        return this->Id;
    }

    void setSalary(double salary)
    {
        this->salary = salary;
    }

    double getSalary()
    {
        return this->salary;
    }

    virtual void accept()
    {
        cout << " Enter Id : ";
        cin >> Id;
        cout << " Enter Salary : ";
        cin >> salary;

        if (salary <= 100)
        {
            cout << " Please Enter Salary greater than 100 ";
            throw InvalidInputException(" Invalid Input Entered !!!");
        }
    }

    virtual void display()
    {
        cout << " Id : " << Id << endl;
        cout << " Salary : " << salary << endl;
    }

    virtual ~Employee() {}
};

class Manager : virtual public Employee
{

private:
    double bonus;

public:
    Manager() : bonus(0.0) {};

    Manager(int Id, double salary, double bonus) : Employee(Id, salary), bonus(bonus) {};

    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }

    double getBonus()
    {
        return this->bonus;
    }

    void accept()
    {
        Employee::accept();
        this->acceptManager();
    }

    void display()
    {
        Employee::display();
        this->displayManager();
    }

protected:
    void acceptManager()
    {
        cout << " Bonus : ";
        cin >> bonus;
        if (bonus < 0)
        {
            throw InvalidInputException("Bonus cannot be negative!");
        }
    }

    void displayManager()
    {
        cout << " Bonus : " << bonus << endl;
    }
};

class Salesman : virtual public Employee
{

private:
    double commission;

public:
    Salesman() : commission(0.0) {};

    Salesman(int Id, double salary, double commission) : Employee(Id, salary), commission(commission) {};

    void setCommission(double commission)
    {
        this->commission = commission;
    }

    double getCommission()
    {
        return this->commission;
    }

    void accept()
    {

        Employee::accept();
        this->acceptSalesman();
    }

    void display()
    {
        Employee::display();
        this->displaySalesman();
    }

protected:
    void acceptSalesman()
    {
        cout << " Commission : ";
        cin >> commission;
        if (commission < 0)
        {
            throw InvalidInputException("Bonus cannot be negative!");
        }
    }
    void displaySalesman()
    {
        cout << " Commission : " << commission << endl;
    }
};

class SalesManager : public Manager, public Salesman
{

public:
    SalesManager() {};

    SalesManager(int Id, double salary, double bonus, double commission) : Employee(Id, salary), Manager(Id, salary, bonus), Salesman(Id, salary, commission) {};

    void accept()
    {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }

    void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }
};
int menuList()
{
    int choice;
    cout << "0. Exit" << endl;
    cout << "1. Add Manager " << endl;
    cout << "2. Add Salesman " << endl;
    cout << "3. Add SalesManager " << endl;
    cout << "4. Count of all employees with respect to designation " << endl;
    cout << "5. Display All Managers " << endl;
    cout << "6. Display All Salesman " << endl;
    cout << "7. Display All SalesManager " << endl;

    cin >> choice;
    return choice;
}
int main()
{

    int n;
    cout << " How many Employee's you want to enter : ";
    cin >> n;
    if (n <= 0)
    {
        throw InvalidInputException(" \n Invalid Input !!!");
    }

    Employee *arr[n];
    int choice;
    int count = 0;
    while ((choice = ::menuList()) != 0)
    {
        try

        {
            switch (choice)
            {
            case 1:
            {
                if (count == n)
                {
                    throw InvalidInputException(" \nNo more seat for new Employees!!!");
                }
                arr[count] = new Manager();
                arr[count]->accept();
                count++;
                break;
            }

            case 2:
            {
                if (count == n)
                {
                    throw InvalidInputException(" \nNo more seat for new Employees!!!");
                }
                arr[count] = new Salesman();
                arr[count]->accept();
                count++;
                break;
            }

            case 3:
            {
                if (count == n)
                {
                    throw InvalidInputException("\n No more seat for new Employees!!!");
                }
                arr[count] = new SalesManager();
                arr[count]->accept();
                count++;
                break;
            }

            case 4:
            {
                int m = 0;
                int s = 0;
                int sm = 0;

                for (int i = 0; i < count; i++)
                {
                    if (typeid(*arr[i]) == typeid(Manager))
                    {
                        m++;
                    }
                    else if (typeid(*arr[i]) == typeid(Salesman))
                    {
                        s++;
                    }
                    else if (typeid(*arr[i]) == typeid(SalesManager))
                    {
                        sm++;
                    }
                }

                cout << " Total Count of Employee's :" << endl;
                cout << " Manager's :" << m << endl;
                cout << " Salesman's :" << s << endl;
                cout << " SalesManager's :" << sm << endl;
                break;
            }

            case 5:
            {
                cout << " Managers :" << endl;
                for (int i = 0; i < count; i++)
                {
                    if (typeid(*arr[i]) == typeid(Manager))
                    {
                        arr[i]->display();
                    }
                }
                break;
            }

            case 6:
            {
                cout << " Salesman :" << endl;
                for (int i = 0; i < count; i++)
                {
                    if (typeid(*arr[i]) == typeid(Salesman))
                    {
                        arr[i]->display();
                    }
                }
                break;
            }

            case 7:
            {
                cout << " SalesManager :" << endl;
                for (int i = 0; i < count; i++)
                {
                    if (typeid(*arr[i]) == typeid(SalesManager))
                    {
                        arr[i]->display();
                    }
                }
                break;
            }
            }
        }
        catch (InvalidInputException &ie)
        {
            cout << ie.getMessage();
        }
    }
    delete[] arr;
    *arr = NULL;
    return 0;
}