#ifndef PIZZA_VEGETARIANA_H
#define PIZZA_VEGETARIANA_H
#include <Pizza.h>

class Pizza_Vegetariana:public Pizza{
public:
    Pizza_Vegetariana(int idc=0, int distantac=0, int pretc=0):Pizza(idc, distantac, pretc){}
    Pizza_Vegetariana(const Pizza_Vegetariana &x):Pizza(x){}
    virtual void tip(){cout<<"Pizza vegetariana\n";}
};

#endif
