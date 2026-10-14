#include <iostream>
#include <string.h>
using namespace std;
class Room{
    protected:
    int roomNumber,night;
    string guestName;
    public:
    Room(int r,string v,int n){
        roomNumber=r;
        guestName=v;
        night=n;
    }
  void showDetails(){
        cout<<"Room Number : "<<roomNumber<<endl;
        cout<<"Guest Name : "<<guestName<<endl;
        cout<<"Nights : "<<night<<endl;
    }
    virtual int calculateBill(){
        return 0;
    }
};
class StandardRoom : public Room{
    public:
    StandardRoom(int r, string v, int n) : Room(r,v,n){}
    int calculateBill() override
    {
        return 1000*night;
    }
    void showDetails()
    {
        cout<<"Room Type : Standard Room "<<endl;
        Room:: showDetails();
        cout<<"Room Bill : "<<calculateBill()<<endl;
        cout<<"-----------------------------"<<endl;
    }
};
class DeluxeRoom : public Room{
    public:
    DeluxeRoom(int r, string v, int n) : Room(r,v,n){}
    int calculateBill() override
    {
        return 2000*night;
    }
    void showDetails()
    {
        cout<<"Room Type : Deluxe Room "<<endl;
        Room::showDetails();
        cout<<"Room Bill : "<<calculateBill()<<endl;
        cout<<"-----------------------------"<<endl;

    }
};
class SuiteRoom : public Room{
    public:
    SuiteRoom(int r, string v, int n) : Room(r,v,n){}
    int calculateBill() override
    {
        return 4000*night;
    }
    void showDetails()
    {
        cout<<"Room Type : Suite Room "<<endl;
        Room::showDetails();
        cout<<"Room Bill : "<<calculateBill()<<endl;
        cout<<"-----------------------------"<<endl;

    }
};
int main()
{
    StandardRoom a(101, "Amit",2);
    DeluxeRoom b(205, "Priya",3);
    SuiteRoom c(301,"Rohan",1);
    cout<<"-------Hotel Booking bill--------"<<endl;
    a.showDetails();
    b.showDetails();
    c.showDetails();
    int total=0;
    total = a.calculateBill()+b.calculateBill()+c.calculateBill();
    cout<<"Total Earnings : "<<total<<endl;
    return 0;
}