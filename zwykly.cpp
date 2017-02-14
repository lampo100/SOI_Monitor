//
// Created by kacper on 26.12.16.
//
#include "szybki.h"
#include "zwykly.h"
Bufor::Bufor(SzybkiBufor *szb){
    szybki = szb;
    szybki->enter();
    szybki->listaBuforow[szybki->i] = this;
    szybki->i++;
    szybki->count++;
    szybki->leave();
}

Bufor::Bufor() {
}

void Bufor::pobierz(){
    enter();
    int wynik = 0;
    while(true){
        wynik = szybki->pobierz(this);
        if(wynik == -1){
            wait(EMPTY);
            wynik = 0;
            continue;
        }
        else break;
    }
    std::cout<<"Pobrano: "<<wynik<<std::endl;
    leave();
}

void Bufor::dodaj(int i, unsigned char wybor){
    enter();
    if(wybor != 1 ){
        bufor.push_back(i);
        signal(EMPTY);
        leave();
    }else{
        leave();
        szybki->dodaj(i);
    }
}

void Bufor::wypisz(int i){
    enter();
    std::cout<<"\n||||||||BUFOR "<<i<<"||||||||\n";
    i = 0;
    for(auto x: bufor){
        std::cout<<"Bufor["<<i<<"] = "<<x<<"\n";
        i++;
    }
    std::cout<<"|||||||||||||||||||||||\n";
    szybki->wypisz();
    leave();
}