#include <iostream>
using namespace std ;
class Date {
    private :
        int day ;
        int month ;
        int year ;

    public:
        void initDate(){

            day=1;
            month=10;
            year=2004;
        }
        void printDateOnConsole(){
            cout<<"--------Date---------"<<endl;
            cout<<""<<day<<"-"<<month<<"-"<<year<<endl;
            cout<<"---------------------"<<endl;

        } 
        void acceptDateFromConsole(){
            cout<<"enter the day :"<<endl;
            cin >>day;
            cout<<"enter the month :"<<endl;
            cin >>month;
            cout <<"enter the year :"<<endl;
            cin >>year;
        }
        bool isLeapYear() {
            if (year%400==0||(year%4==0&&year %100!=0))
            {
                return true;
            }
            else{
               return false;
            }
        }
        

};
int menulist(void ){
    int choice ;
    cout<<"-----------------"<<endl;
    cout <<"\n 0. Exit \n 1. init date \n 2. accept date \n 3. print date \n 4. find leap year "<<endl;
    cout<<"-----------------"<<endl;
    cin>>choice;
    return choice;
}
int main (){
    Date d1;
    int choice ;
    while((choice=menulist ())!=0){
        switch(choice){
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
                cout<<"---------------------"<<endl;
                cout<<"year is leap year :"<<endl;
                cout<<"---------------------"<<endl;
                
            }
            else{
                cout<<"---------------------"<<endl;
                cout<<"year is not leap year :"<<endl;
                cout<<"---------------------"<<endl;

            }
            break;
            default:
            cout <<"enter the valid :"<<endl;
        }

    }

}
