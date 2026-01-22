
#pragma once // Zabezpieczenie przed wielokrotnym dolaczeniem pliku
#include <fstream>
#include <iostream>
#include <string>

class Pojazd  // Klasa abstrakcyjna - nie mozna stworzyc jej obiektu
{
protected:
    std::string marka;
    int         rokProdukcji;

public:
    // Konstruktor z lista inicjalizacyjna - wartosci sa przypisywane przed wejsciem do ciala
    Pojazd(std::string m, int r) : marka(m), rokProdukcji(r) {}// Lista do inicjalizacji 

  
    virtual ~Pojazd() {} // Wirtualny destruktor

    
    virtual void wyswietl() const = 0;// Metoda wirtualna do tego by klasa byla abstrakcyjna czyli polimorfizm

    virtual void        zapiszBinarnie(std::ostream& out) const;
    virtual std::string pobierzTyp() const = 0;// Zwraca nazwe typu pojazdu, co ulatwia rozpoznanie obiektu podczas wczytywania z pliku
};