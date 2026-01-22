#include "Motor.h"

void Motor::wyswietl() const
{
    std::cout << "[Motor] Marka: " << marka << ", Rok: " << rokProdukcji << ", Kosz: " << (czyMaKosz ? "Tak" : "Nie")
              << std::endl;
}

void Motor::zapiszBinarnie(std::ostream& out) const
{
    Pojazd::zapiszBinarnie(out);
    out.write(reinterpret_cast< const char* >(&czyMaKosz), sizeof(czyMaKosz));
}