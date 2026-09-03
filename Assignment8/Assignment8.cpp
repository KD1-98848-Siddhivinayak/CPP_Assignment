#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    int inches;

public:
    Distance()
    {
        feet = 0;
        inches = 0;
    }

    Distance(int f, int i)
    {
        feet = f;
        inches = i;
    }

    // Overload + operator
    Distance operator+(Distance d)
    {
        Distance temp;

        temp.feet = feet + d.feet;
        temp.inches = inches + d.inches;

        if (temp.inches >= 12)
        {
            temp.feet = temp.feet + (temp.inches / 12);
            temp.inches = temp.inches % 12;
        }

        return temp;
    }

    // Overload ++ operator
    Distance operator++()
    {
        inches++;

        if (inches >= 12)
        {
            feet++;
            inches = inches - 12;
        }

        return *this;
    }

    // Overload -- operator
    friend Distance operator--(Distance &d);

    // Overload >> operator
    friend istream &operator>>(istream &in, Distance &d);

    // Overload << operator
    friend ostream &operator<<(ostream &out, Distance d);
};

// Definition of -- operator
Distance operator--(Distance &d)
{
    if (d.inches > 0)
    {
        d.inches--;
    }
    else
    {
        d.feet--;
        d.inches = 11;
    }

    return d;
}

istream &operator>>(istream &in, Distance &d)
{
    cout << "Enter feet: ";
    in >> d.feet;

    cout << "Enter inches: ";
    in >> d.inches;

    return in;
}

ostream &operator<<(ostream &out, Distance d)
{
    out << d.feet << " feet " << d.inches << " inches";

    return out;
}

int main()
{
    Distance d1, d2, d3;

    cout << "Enter first distance:" << endl;
    cin >> d1;

    cout << "Enter second distance:" << endl;
    cin >> d2;

    d3 = d1 + d2;

    cout << endl;
    cout << "First Distance  : " << d1 << endl;
    cout << "Second Distance : " << d2 << endl;
    cout << "Addition        : " << d3 << endl;

    ++d1;
    cout << "After ++d1      : " << d1 << endl;

    --d2;
    cout << "After --d2      : " << d2 << endl;

    return 0;
}