#pragma once

#include "Pojazd.h"

class Motor : public Pojazd
{
private:
    bool czyMaKosz;

public:
    Motor(std::string m, int r, bool k) : Pojazd(m, r), czyMaKosz(k) {}

    void        wyswietl() const override;
    void        zapiszBinarnie(std::ostream& out) const override;
    std::string pobierzTyp() const override { return "Motor"; }
};