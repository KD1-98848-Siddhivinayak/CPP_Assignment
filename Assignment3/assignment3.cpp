#include <iostream>
using namespace std ;
class Cylinder {
    double radius ;
    double height ;
    static double pi;
    public:
    Cylinder(void):radius(1),height(1){};
    Cylinder(double radius, double height) :radius(radius),height(height){};
     void setRadius(double radius){
        this->radius=radius;
     } 
    void  setHeight(double height){
        this->height=height;

    } 
    double getRadius() {
        return radius;
    }
    double getHeight(){
        return height;

    }
    void calculateVolume() {
        double volume = Cylinder::pi* radius * radius *height;
        cout<<"--------------------------------"<<endl;
        cout<<" Valume of Cylinder:"<<volume<<endl;
        cout<<"--------------------------------"<<endl;

    }
};
 double Cylinder::pi=3.14;


int main (){
    Cylinder c1;
    c1.setHeight(10);
    c1.setRadius(10);
    cout<<"radius :"<<c1.getRadius()<<endl;
    cout<<"height :"<<c1.getHeight()<<endl;
    c1.calculateVolume();
    
    Cylinder c2;
    c2.setHeight(30);
    c2.setRadius(40);
    cout<<"radius :"<<c2.getRadius()<<endl;
    cout<<"height :"<<c2.getHeight()<<endl;
    c2.calculateVolume();
    
}