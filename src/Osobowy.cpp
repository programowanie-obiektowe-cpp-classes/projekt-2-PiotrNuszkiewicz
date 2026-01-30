#include "Osobowy.h"

void Osobowy::wyswietl() const
{
    std::cout << "[Osobowy] Marka: " << marka << ", Rok: " << rokProdukcji << ", Drzwi: " << liczbaDrzwi << std::endl;// Korzysta z pol chronionych (marka, rokProdukcji) zdefiniowanych w klasie Pojazd
}

void Osobowy::zapiszBinarnie(std::ostream& out) const
{
    Pojazd::zapiszBinarnie(out);// Najpierw wywoluje wersje z klasy bazowej by zapisac marke i rok. Zapis danych bazowych
    out.write(reinterpret_cast< const char* >(&liczbaDrzwi), sizeof(liczbaDrzwi));// dopisuje ceche specyficzna dla tego typu
}