#pragma once

#include "Pojazd.h"
#include <memory>
#include <vector>

class BazaPojazdow
{
private:
    
    std::vector< std::unique_ptr< Pojazd > > lista;// Wektor do przechowywania wskaznika

    
    BazaPojazdow() {}// konstruktor prywatny 

public:
    static BazaPojazdow& pobierzInstancje() // sposob na dostanie sie do bazy
    {
        static BazaPojazdow instancja;
        return instancja;// Tworzy tylko raz przy pierwszym wywolaniu
    }
    // Metody do zarzadzania danymi
    void dodaj(std::unique_ptr< Pojazd > p);
    void usun(int indeks);
    void pokazWszystkie() const;
    void zapisz(const std::string& nazwa);
    void wczytaj(const std::string& nazwa);
};