#include "Pojazd.h"

void Pojazd::zapiszBinarnie(std::ostream& out) const
{
    // Zapisuje dlugosc napisu a potem napis 
    size_t dlugosc = marka.size();
    out.write(reinterpret_cast< const char* >(&dlugosc), sizeof(dlugosc));
    out.write(marka.c_str(), dlugosc);// Zapisuje same znaki z pamieci
    out.write(reinterpret_cast< const char* >(&rokProdukcji), sizeof(rokProdukcji));// Liczby zapisuje jako surowe bajty z pamieci
}