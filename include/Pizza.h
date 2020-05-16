#ifndef PIZZA_H
#define PIZZA_H
#include <iostream>
#include <Base.h>

using namespace std;

class Pizza:public Base{
    static int nrpizza;
    const int Manopera=10;
protected:
    int id;
    int distanta;
    int pret;
public:
    Pizza(int idc=0, int distantac=0, int pretc=0);
    Pizza(const Pizza &x);
    int calcul();
    static int nrp();
    int getManopera() const;
    int getid(){return id;}
    void setpret(int pretc){pret=pretc;}
    friend ostream& operator << (ostream& os, Pizza p);
    friend istream& operator >> (istream& is, Pizza &p);
    Pizza operator= (const Pizza &p);
    virtual void tip(){cout<<"Pizza\n";}
    virtual ~Pizza();
};


#endif
