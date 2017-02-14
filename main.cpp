#include <iostream>
#include <thread>
#include "szybki.h"
#include "zwykly.h"
#include <cstdlib>
#include <ctime>

SzybkiBufor szybki;
Bufor buf1(&szybki);
Bufor buf2(&szybki);
Bufor buf3(&szybki);

void producer(int z){
    int ch1 = std::rand()%3;
    int ch2 = std::rand()%2;
    int i = z;
    int value;
    sleep(3);
    while(i< z + 12) {
        value = i;
        if(ch1 == 0){
            if(ch2 == 0){
                std::cout<<"Dodaje do bufora 1 wartosc:          "<< value<<"\n";
            }else{
                std::cout<<"Dodaje do bufora szybkiego wartosc:  "<<value + 1000<<"\n";
                value = i + 1000;
            }
            buf1.dodaj(value,ch2);
        }else if(ch1 == 1){
            if(ch2 == 0){
                std::cout<<"Dodaje do bufora 2 wartosc:          "<<value<<"\n";
            }else{
                std::cout<<"Dodaje do bufora szybkiego wartosc:  "<<value + 1000<<"\n";
                value = i + 1000;
            }
            buf2.dodaj(value,ch2);
        }else{
            if(ch2 == 0){
                std::cout<<"Dodaje do bufora 3 wartosc:          "<<value<<"\n";
            }else{
                std::cout<<"Dodaje do bufora szybkiego wartosc:  "<<value + 1000<<"\n";
                value = i + 1000;
            }
            buf3.dodaj(value,ch2);
        }
        ++i;
        sleep(3);
        ch1 = std::rand()%3;
        ch2 = std::rand()%2;
    }
}
void consumer(){
    int ch1 = std::rand()%3;
    int i = 0;
    sleep(2);

    while(i < 3){
        if(ch1 == 0){
            std::cout<<"Probuje pobrac z bufora 1\n";
            std::cout<<"Przed pobraniem: ";
            buf1.wypisz(1);
            buf1.pobierz();
            buf1.wypisz(1);
        }else if(ch1 == 1){
            std::cout<<"Probuje pobrac z bufora 2\n";
            std::cout<<"Przed pobraniem: ";
            buf2.wypisz(2);
            buf2.pobierz();
            buf2.wypisz(2);
        }else{
            std::cout<<"Probuje pobrac z bufora 3\n";
            std::cout<<"Przed pobraniem: ";
            buf3.wypisz(3);
            buf3.pobierz();
            buf3.wypisz(3);
        }
        ++i;
        ch1 = std::rand()%3;
        sleep(4);

    }
}

int main() {

    std::srand(std::time(0));
    std::thread p1(producer, 0);
  //  std::thread p2(producer, 12);
  //  std::thread p3(producer, 24);
    std::thread c1(consumer);
    std::thread c2(consumer);
    std::thread c3(consumer);




    p1.join();
 //   p2.join();
 //   p3.join();
    c1.join();
    c2.join();
    c3.join();

    buf1.wypisz(1);
    buf2.wypisz(2);
    buf3.wypisz(3);
    std::cout<<"DZIALA";

}