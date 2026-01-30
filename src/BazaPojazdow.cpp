#include "BazaPojazdow.h"
#include "Motor.h"
#include "Osobowy.h"

void BazaPojazdow::dodaj(std::unique_ptr< Pojazd > p)// std::move przenosi wlasnosc do wektora (unique_ptr nie mozna kopiowac)
{
    lista.push_back(std::move(p));
}

//void BazaPojazdow::usun(int indeks)// Sprawdza czy podany numer istnieje w tablicy
//{
//    if (indeks >= 0 && indeks < static_cast< int >(lista.size()))
//    {
//       lista.erase(lista.begin() + indeks);// erase usuwa element, a unique_ptr automatycznie zwalnia pamiec
 //   }
//
void BazaPojazdow::usun(int indeks)
{
    // Sprawdza czy indeks nie jest mniejszy od 0 lub wiekszy od rozmiaru listy
    if (indeks >= 0 && indeks < static_cast< int >(lista.size()))
    {

        // erase() potrzebuje iteratora, dlatego uzywamy lista.begin() + indeks
        lista.erase(lista.begin() + indeks);

        std::cout << "Pojazd pod indeksem " << indeks << " zostal trwale usuniety.\n";
    }
    else
    {
        // Informacja jesli zly numer zostal podany
        std::cout << "BLAD: Nie ma pojazdu o takim indeksie! (Aktualny zakres: 0 - "
                  << (lista.empty() ? 0 : lista.size() - 1) << ")\n";
    }
}
/// <summary>
/// /
/// </summary>
void BazaPojazdow::pokazWszystkie() const
{
    for (size_t i = 0; i < lista.size(); ++i)
    {
        std::cout << i << ". ";
        lista[i]->wyswietl(); // Polimorfizm 
    }
}

void BazaPojazdow::zapisz(const std::string& nazwa)
{
    std::ofstream out(nazwa, std::ios::binary);// Otwarcie pliku w trybie binarnym
    size_t        ile = lista.size();
    out.write(reinterpret_cast< char* >(&ile), sizeof(ile));
    for (auto& p : lista)
    {
        std::string typ = p->pobierzTyp();
        size_t      len = typ.size();
        out.write(reinterpret_cast< char* >(&len), sizeof(len));
        out.write(typ.c_str(), len);
        p->zapiszBinarnie(out);// Wywolanie wirtualnej metody zapisu binarnego
    }
}

void BazaPojazdow::wczytaj(const std::string& nazwa)
{
    std::ifstream in(nazwa, std::ios::binary);
    if (!in)
        return;
    lista.clear();// Czyszczenie obecna liste
    size_t ile;
    in.read(reinterpret_cast< char* >(&ile), sizeof(ile));
    for (size_t i = 0; i < ile; ++i)
    {
        size_t len;
        in.read(reinterpret_cast< char* >(&len), sizeof(len));//  Wczytuje typ obiektu
        std::string typ(len, ' ');
        in.read(&typ[0], len);

        size_t mLen;//Wczytuje dane wspolne
        in.read(reinterpret_cast< char* >(&mLen), sizeof(mLen));
        std::string marka(mLen, ' ');
        in.read(&marka[0], mLen);
        int rok;
        in.read(reinterpret_cast< char* >(&rok), sizeof(rok));

        if (typ == "Osobowy")//na podstawie napisu 'typ' tworzony jest konkretny obiekt
        {
            int d;
            in.read(reinterpret_cast< char* >(&d), sizeof(d));
            dodaj(std::make_unique< Osobowy >(marka, rok, d));
        }
        else
        {
            bool k;
            in.read(reinterpret_cast< char* >(&k), sizeof(k));
            dodaj(std::make_unique< Motor >(marka, rok, k));
        }
    }
}