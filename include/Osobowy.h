#pragma once

#include "Pojazd.h"

class Osobowy : public Pojazd
{
private:
    int liczbaDrzwi;

public:
    Osobowy(std::string m, int r, int d) : Pojazd(m, r), liczbaDrzwi(d) {}

    void        wyswietl() const override;
    void        zapiszBinarnie(std::ostream& out) const override;
    std::string pobierzTyp() const override { return "Osobowy"; }
};