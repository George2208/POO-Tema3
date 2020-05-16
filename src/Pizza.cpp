#include "Pizza.h"

Pizza::Pizza(int idc, int distantac, int pretc){
    id=idc;
    distanta=distantac;
    pret=pretc;
    nrpizza++;}

Pizza::Pizza(const Pizza &x){
    id=x.id;
    distanta=x.distanta;
    pret=x.pret;
    nrpizza++;}

int Pizza::nrpizza{0};
int Pizza::nrp(){
    return nrpizza;}
Pizza::~Pizza(){
    nrpizza--;}

int Pizza::getManopera() const{
    return Manopera;}

int Pizza::calcul(){
    return pret+pret*(distanta/10*0.05)+Manopera;}

ostream& operator << (ostream& os, Pizza p){
    os<<p.id<<" "<<p.distanta<<" "<<p.pret<<"("<<p.calcul()<<")"<<endl;
    return os;}

istream& operator >> (istream& is, Pizza &p){
    is>>p.id>>p.distanta>>p.pret;
    return is;}

Pizza Pizza::operator= (const Pizza &p){
    id=p.id;
    distanta=p.distanta;
    pret=p.pret;
    return *this;}
