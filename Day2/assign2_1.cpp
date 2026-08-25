#include<iostream>
using namespace std ;
struct Date {
    private:
    int day ;
    int month;
    int year ;
public:
void initDate(){
day=1;
month=10;
year=2004;
}
void printDateOnConsole(){
cout <<"------Date------"<<endl;
cout<<""<<day<<"-"<<month<<"-"<<year<<endl;
cout <<"----------------"<<endl;

} 
void acceptDateFromConsole(){
    cout<<"-------enter the date-------"<<endl;
    cout<<"enter the day "<<endl;
    cin>>day;
    cout <<"enter the month "<<endl;
    cin>>month;
    cout<<"enter the year "<<endl;
    cin>>year;
    
}
bool isLeapYear(){
    if (year%400==0||(year%4==0&&year%100!=0)){
        return true;

    }
    else {
        return false;
    }

    
}
};
int  menulist(void){
    int choice;
    cout <<"\n0.for exit\n1.for init date\n2.accept date\n3.print date\n4.leap year\n ";
    cin>>choice;
    return choice;
}
int main () {
    struct Date d1;
    int choice ;
    while((choice = menulist())!=0){
        switch (choice){
            case 1:
            d1.initDate();
            break;
            case 2:
            d1.acceptDateFromConsole();
            break;
            case 3:
            d1.printDateOnConsole();
            break;
            case 4:
            if (d1.isLeapYear()){
                cout <<"----------------"<<endl;
                cout<<"leap year "<<endl;
                cout <<"----------------"<<endl;
            }
            else {
                cout <<"----------------"<<endl;
                cout<<"not leap year :"<<endl;
                cout <<"----------------"<<endl;
            }
            break;

        }


    }
}