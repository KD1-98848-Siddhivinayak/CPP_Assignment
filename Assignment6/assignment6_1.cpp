#include<iostream>
#include<typeinfo>
using namespace std;
class Product {
    int id;
    string title;

protected:

    double price;
public:
    Product(void) :id(0), title(""), price(0.0) {}
    Product(int id, string title, double price) :id(id), title(title), price(price) {}

    virtual void  acceptRecord() {
        cout << "id" << endl;
        cin >> id;
        cout << "title :" << endl;
        cin >> title;
        cout << "price:" << endl;
        cin >> price;

    }
    virtual void printReacord() {
        cout << "id :" << id << endl;
        cout << "title :" << title << endl;
        cout << "price :" << price << endl;
    }
    virtual double bill() = 0;


};
class Book :public Product {
    string author;
public:
    Book(void) :author(" ") {};
    Book(int id, string title, double price, string author) :author(author), Product(id, title, price) {}
    void acceptRecord() {
        Product::acceptRecord();
        cout << "Enter the Author name :" << endl;
        cin >> author;

    }

    double bill() {
        double discount = this->price * 0.10;
        double finalprice = this->price - discount;
        return finalprice;
    }
    void printRecord() {
        Product::printReacord();
        cout << "author name :" << author << endl;
    }

};
class Tape :public Product {
    string artist;
public:
    Tape(void) :artist("") {}
    Tape(int id, string title, double price, string artist) :artist(artist), Product(id, title, price) {}
    void acceptRecord() {
        Product::acceptRecord();
        cout << "enter the artist name :" << endl;
        cin >> artist;

    }
    double bill() {
        double discount = this->price * 0.10;
        double finalprice = this->price - discount;
        return finalprice;
    }
    void printRecord() {
        Product::printReacord();
        cout << "artist name :" << artist << endl;
    }
};
int menulist(void) {
    int choice;

    cout << "0.exist " << endl;
    cout << "1.tape " << endl;
    cout << "2.book " << endl;
    cout << "3.final bill" << endl;
    cin >> choice;
    return choice;

}



void acceptRecord(Product* ptr) {

    if (typeid(*ptr) == typeid(Book)) {
        cout << "in casep " << endl;
        Book* bptr = (Book*)ptr;
        bptr->acceptRecord();

    }
    else if (typeid(*ptr) == typeid(Tape)) {
        Tape* tptr = (Tape*)ptr;
        tptr->acceptRecord();
    }

}
void printRecord(Product* ptr) {
    ptr->printReacord();
}




int main() {
    int choice;
    Product* ptr[3];
    double finalbill = 0;
    int i = 0;
    while (i < 3) {

        choice = menulist();


        switch (choice) {
        case 1:
            ptr[i] = new Tape();
            break;
        case 2:
            ptr[i] = new Book();

            break;



        }

        if (ptr != NULL) {

            ::acceptRecord(ptr[i]);
            i++;

            // ::printRecord(ptr[i]);
        }
    }




    for (int i = 0;i < 3;i++) {
        if (ptr[i] != NULL) {
            finalbill += ptr[i]->bill();
        }

    }
    cout << "finalbill" << finalbill << endl;

    cout << "total bill after the discount :" << finalbill << endl;




}