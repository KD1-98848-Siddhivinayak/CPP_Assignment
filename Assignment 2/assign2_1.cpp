#include <iostream>
using namespace std;
class Valumeofbox {
    double length;
    double breadth ;
    double height;
    public:
    Valumeofbox(void){
        this->length=1;
        this->breadth=1;
        this->height=1;

    }
    Valumeofbox(double length,double breadth,double height){
        this->length=length;
        this->breadth=breadth;
        this->height=height;

    }
    Valumeofbox(int value ){
        this->length=value;
        this->breadth=value;
        this->height=value;

    }


    void printValume(){
        double val=length*breadth*height;
        cout<<"volume of box :"<<val;

        
    }



};



int menulist (void ){
    int choice;
    cout<<"\n------------------------------------------------";
    cout <<"\n 1.Calculate Volume with default values \n2.Calculate Volume with length,breadth and height with same value \n3.Calculate Volume with different length,breadth and height values. \n ";
    cout<<"\n------------------------------------------------\n";
    cin>>choice;
    return choice;

}
int main() {

    int choice;
    
    
  

    while ((choice = menulist()) != 0) {

        switch (choice) {

            case 1:{
                Valumeofbox v1;
                v1.printValume();
                break;
            }
            case 2:
                {
                    Valumeofbox v2(10);
                v2.printValume();
                break;}

            case 3:{
                  Valumeofbox v3(10, 20, 30);
                v3.printValume();
                break;
            }
            default:
                cout << "Invalid data";
        }
    }

    return 0;
}