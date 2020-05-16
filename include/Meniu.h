#ifndef MENIU_H
#define MENIU_H
#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <fstream>
#include <Exceptie.h>

using namespace std;

struct strIngrediente{
    string denumire;
    int cantitate;
    int pretUnitar;};

template <class P> struct strComenzi{
    int id;
    P* ptr;};

template <class P, class PV> class Meniu{
public:
    unordered_map<int,vector<strIngrediente>> retete;
    vector<strComenzi<P>> comenzi;
    int sumaVeg=0, index=0;
    Meniu(){}
    Meniu(string x){init(x);}
    Meniu(const Meniu &x){retete=x.retete;}

    void init(string x) {
        static bool first=true;
        if(!first)
            cout<<"Warning: Already initialized!";
        first=false;
        int nrRetete,nrIngrediente,id;
        ifstream f(x);
        f>>nrRetete;
        for(int i=0; i<nrRetete; i++) {
            f>>id>>nrIngrediente;
            vector<strIngrediente> temp;
            for(int j=0; j<nrIngrediente; j++) {
                strIngrediente aux;
                f>>aux.denumire>>aux.cantitate>>aux.pretUnitar;
                temp.push_back(aux);}
            retete.insert({id,temp});}
        f.close();}

    void addPizza(P &pizza){
        try{if(retete.find(pizza.getid())==retete.end()){
            throw Exceptie();}}
        catch(Exceptie x){
            cout<<x.what();}
        int x=0;
        for(unsigned int i=0; i<retete[pizza.getid()].size(); i++)
            x+=retete[pizza.getid()][i].cantitate*retete[pizza.getid()][i].pretUnitar;
        pizza.setpret(x);
        strComenzi<P> aux;
        aux.id=++index;
        aux.ptr=new PV;
        *aux.ptr=pizza;
        comenzi.push_back(aux);}

    void addPizza(PV &pizza){
        if(retete.find(pizza.getid())==retete.end()){
            cerr<<"Nu exista reteta!";
            return;}
        int x=0;
        for(unsigned int i=0; i<retete[pizza.getid()].size(); i++)
            x+=retete[pizza.getid()][i].cantitate*retete[pizza.getid()][i].pretUnitar;
        pizza.setpret(x);
        strComenzi<P> aux;
        aux.id=++index;
        aux.ptr=new PV;
        *aux.ptr=pizza;
        sumaVeg+=pizza.calcul();
        comenzi.push_back(aux);}

    void printComenzi(){
        cout<<'\n';
        for(unsigned int i=0; i<comenzi.size(); i++)
            cout<<comenzi[i].id<<" -> "<<*comenzi[i].ptr;}

    void operator+= (int id){
        if(retete.find(id)==retete.end()){
            cerr<<"Nu exista reteta!";
            return;}
        int x=0;
        for(unsigned int i=0; i<retete[id].size(); i++)
            x+=retete[id][i].cantitate*retete[id][i].pretUnitar;
        strComenzi<P> aux;
        aux.id=++index;
        aux.ptr=new P(id, 0, x);
        comenzi.push_back(aux);
        return;}

    ~Meniu() {
        for(unsigned int i=0; i<comenzi.size(); i++)
            delete(comenzi[i].ptr);}

    Meniu& operator= (const Meniu &x){
        retete=x.retete;}

};

template <class P, class PV> ostream& operator << (ostream& os, Meniu<P, PV> &obj){
    for(auto i=obj.retete.begin(); i!=obj.retete.end(); ++i){
        os<<"\n--"<<i->first<<"--\n";
        for(unsigned int j=0; j<i->second.size(); j++)
            os<<i->second[j].denumire<<" "<<i->second[j].cantitate<<" "<<i->second[j].pretUnitar<<endl;}
    return os;}

template <class P, class PV> istream& operator >> (istream& is, Meniu<P, PV> &obj){
    int nrr, nri, id;
    cout<<"Introduceti numarul de retete:  ";
    is>>nrr;
    for(int i=0; i<nrr; i++){
        cout<<"ID:  ";
        is>>id;
        cout<<"Nr. ingrediente:  ";
        is>>nri;
        vector<strIngrediente> temp;
        for(int j=0; j<nri; j++){
            strIngrediente aux;
            is>>aux.denumire>>aux.cantitate>>aux.pretUnitar;
            temp.push_back(aux);}
        obj.retete.insert({id,temp});}
    return is;}

#endif
