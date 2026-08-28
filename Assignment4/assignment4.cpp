#include<iostream>
using namespace std;
class Time {
    int hour;
    int min;
    int sec;
public:
    Time(void) :hour(0), min(0), sec(0) {};
    Time(int hour, int min, int sec) :hour(hour), min(min), sec(sec) {};
    void  setHour(int hour) {
        this->hour = hour;
    }
    void setMinute(int min) {
        this->min = min;

    }
    void setSeconds(int sec) {
        this->sec = sec;

    }
    int getHour(void) {
        return hour;
    }
    int getMinute(void) {
        return min;
    }
    int getSeconds(void) {
        return sec;
    }
    void printTime() {
        cout << "------------------------------------------------" << endl;
        cout << "Time :" << hour << ":" << min << ":" << sec << endl;
        cout << "------------------------------------------------" << endl;
    }




};


int menulist(void) {
    int choice;
    cout << "------------------------------------------------" << endl;
    cout << "1. Add Time " << endl;
    cout << "2. Display All Time " << endl;
    cout << "3. Display only hrs of all time objects " << endl;
    cout << "------------------------------------------------" << endl;
    cin >> choice;
    return choice;

}


int main() {
    Time* arr = new Time[2];
    int choice;
    while ((choice = menulist()) != 0) {
        switch (choice) {
        case 1: {
            // Time t1(10,20,30);
            for (int i = 0;i < 2;i++) {
                arr[i].setHour(10);
                arr[i].setMinute(20);
                arr[i].setSeconds(30);
            }
            break;
        }
        case 2: {
            for (int i = 0;i < 2;i++) {
                arr[i].printTime();
            }
            break;
        }
        case 3: {
            for (int i = 0;i < 2;i++) {
                cout << "hours of time [" << i << "] :" << arr[i].getHour() << endl;
            }
            break;
        }

        }
    }

    delete[]arr;
    arr = NULL;


}