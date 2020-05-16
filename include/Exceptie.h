#ifndef EXCEPTIE_H
#define EXCEPTIE_H
#include <exception>

class Exceptie:public std::exception
{
public:
    const char* what(){
        return "Nu exista reteta!";}
};

#endif
