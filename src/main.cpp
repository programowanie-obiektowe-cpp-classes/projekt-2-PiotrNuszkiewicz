#include "BazaPojazdow.h"
#include "Motor.h"
#include "Osobowy.h"
#include <iostream>

int main()
{
    BazaPojazdow& baza  = BazaPojazdow::pobierzInstancje();// Pobieram referencje do bazy
    int           wybor = -1;

    while (wybor != 0)
    {
        std::cout << "\n 1. Dodaj Osobowy \n 2. Dodaj Motor \n 3. Pokaz \n 4. Usun \n 5. Zapisz \n 6. Wczytaj \n 0. Koniec\n "
                     "Wybor: ";
        std::cin >> wybor;

        if (wybor == 1)
        {
            std::string m;
            int         r, d;
            std::cout << "Marka: ";
            std::cin >> m;
            std::cout << "Rok: ";
            std::cin >> r;
            std::cout << "Drzwi: ";
            std::cin >> d;
            baza.dodaj(std::make_unique< Osobowy >(m, r, d));// make_unique tworzony jest  nowy obiekt i zwraca  wskaznik
        }
        else if (wybor == 3)
        {
            baza.pokazWszystkie();
        }
        else if (wybor == 5)
        {
            baza.zapisz("baza.dat");
        }
        else if (wybor == 6)
        {
            baza.wczytaj("baza.dat");
        }
    }
    return 0;
}