//
// Created by kacper on 26.12.16.
//

#ifndef MONITORY_ZWYKLY_H
#define MONITORY_ZWYKLY_H

#include "monitor.h"
#include <queue>

class SzybkiBufor;

class Bufor: public Monitor{
public:
    friend class SzybkiBufor;

    Bufor();
    Bufor(SzybkiBufor *szb);
    void pobierz();
    void dodaj(int i, unsigned char wybor);
    void wypisz(int i);

protected:
    std::list<int> bufor;
    Condition EMPTY;
private:
    SzybkiBufor *szybki;
};
#endif //MONITORY_ZWYKLY_H
