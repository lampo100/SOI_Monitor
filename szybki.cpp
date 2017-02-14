//
// Created by kacper on 26.12.16.
//
#include "szybki.h"
#include "zwykly.h"

SzybkiBufor::SzybkiBufor(){
    i = 0;
    count = 0;
}

int SzybkiBufor::pobierz(Bufor *docelowy){
    enter();
    if(bufor.empty()){
        if(docelowy->bufor.empty()){
            leave();
            return -1;
        }
        else{
            int wynik = docelowy->bufor.front();
            docelowy->bufor.pop_front();
            leave();
            return wynik;
        }
    }
    else{
        int wynik = bufor.front();
        bufor.pop_front();
        leave();
        return wynik;
    }
}

void SzybkiBufor::dodaj(int i){
    enter();
        bufor.push_back(i);
    leave();
    for(int i = 0; i < count; i++)
        listaBuforow[i]->signal(listaBuforow[i]->EMPTY);
}

void SzybkiBufor::wypisz(){
    enter();
    int i = 0;
    std::cout<<"\n||||||| SZYBKI BUFOR ||||||||\n";
    for(auto x: bufor){
        std::cout<<"Bufor["<<i<<"] = "<<x<<"\n";
        i++;
    }
    std::cout<<"|||||||||||||||||||||||||||||\n\n";
    leave();
};
