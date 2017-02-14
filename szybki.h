//
// Created by kacper on 26.12.16.
//

#ifndef MONITORY_SZYBKI_H
#define MONITORY_SZYBKI_H

#include "monitor.h"
#include <queue>
#include <list>
#include <iostream>
#define N 124


class Bufor;

class SzybkiBufor: public Monitor{
    friend class Bufor;

public:
    SzybkiBufor();
protected:
    int pobierz(Bufor *docelowy);
    void dodaj(int i);
    void wypisz();


    Bufor *listaBuforow[N];
    size_t i;
    size_t count;
    std::list<int> bufor;
};
#endif //MONITORY_SZYBKI_H
