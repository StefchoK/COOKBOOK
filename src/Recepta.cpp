#include "COOKBOOK/include/Recepta.h"
#include <iostream>
#include <iomanip>

Recepta::Recepta(const std::string& ime,
                 const std::string& kategoriq,
                 int portcii)
    : ime(ime), kategoriq(kategoriq), portcii(portcii)
{
    if (portcii <= 0) {
        std::cerr << "[!] Nevaliден broi portcii, zadavam 1.\n";
        this->portcii = 1;
    }
}

void Recepta::dodadiSastavka(Sastavka* s, double kolichestvo) {
    if (!s) { std::cerr << "[!] Nullptr sastavka!\n"; return; }
    if (kolichestvo <= 0) { std::cerr << "[!] Kolichestvoto trqbva da e > 0!\n"; return; }
    sastavki.push_back({s, kolichestvo});
}

void Recepta::dodadiStapka(const std::string& stapka) {
    if (!stapka.empty()) stapki.push_back(stapka);
}

void Recepta::dodadiOcenka(const Ocenka& o) {
    ocenki.push_back(o);
}

double Recepta::getSrednaOcenka() const {
    if (ocenki.empty()) return 0.0;
    double suma = 0;
    for (const auto& o : ocenki) suma += o.getZvezdi();
    return suma / ocenki.size();
}

void Recepta::pokaziOcenki() const {
    if (ocenki.empty()) { std::cout << "  (nqma ocenki)\n"; return; }
    std::cout << "  Sredna ocenka: " << std::fixed << std::setprecision(1)
              << getSrednaOcenka() << "/5 (" << ocenki.size() << " ocenki)\n";
    for (const auto& o : ocenki) o.pokazi();
}

HranitelnаInfo Recepta::getHranitelnаInfo() const {
    HranitelnаInfo info;
    for (const auto& [s, kol] : sastavki) {
        double f = kol / 100.0;
        info.kalorii += s->getKalorii() * f;
        if (auto* ps = dynamic_cast<ProstaSastavka*>(s)) {
            info.proteini      += ps->getProteini()      * f;
            info.mazhnini      += ps->getMazhnini()      * f;
            info.vyglekhidrati += ps->getVyglekhidrati() * f;
        }
    }
    return info;
}

Recepta* Recepta::mashtabirane(int novPortcii) const {
    if (novPortcii <= 0) {
        std::cerr << "[!] Nevaliден broi portcii za mashtabirane!\n";
        return nullptr;
    }
    double f = static_cast<double>(novPortcii) / portcii;
    auto* nova = new Recepta(ime, kategoriq, novPortcii);
    for (const auto& [s, kol] : sastavki) nova->dodadiSastavka(s, kol * f);
    for (const auto& st : stapki)         nova->dodadiStapka(st);
    return nova;
}

void Recepta::pokaziPълно() const {
    std::cout << "\n========================================\n";
    std::cout << "  " << ime << "\n";
    std::cout << "  Kategoriq: " << kategoriq
              << "  |  Portcii: " << portcii << "\n";
    std::cout << "========================================\n";

    std::cout << "SASTAVKI:\n";
    for (const auto& [s, kol] : sastavki)
        std::cout << "  - " << s->getIme() << ": "
                  << std::fixed << std::setprecision(0)
                  << kol << " " << s->getEdinica() << "\n";

    std::cout << "\nNACHIN NA PRIGOTAVQNE:\n";
    for (size_t i = 0; i < stapki.size(); i++)
        std::cout << "  " << (i+1) << ". " << stapki[i] << "\n";

    HranitelnаInfo info = getHranitelnаInfo();
    std::cout << "\nHRANITELNA INFORMACIQ:\n";
    std::cout << "  Kalorii:       " << std::fixed << std::setprecision(1) << info.kalorii      << " kcal\n";
    std::cout << "  Proteini:      " << info.proteini      << " g\n";
    std::cout << "  Mazhnini:      " << info.mazhnini      << " g\n";
    std::cout << "  Vyglekhidrati: " << info.vyglekhidrati << " g\n";

    std::cout << "\nOCENKI:\n";
    pokaziOcenki();
}

void Recepta::pokaziKratko() const {
    double sr = getSrednaOcenka();
    std::cout << "  [" << kategoriq << "] " << ime
              << " (" << portcii << " portcii)";
    if (sr > 0)
        std::cout << " | " << std::fixed << std::setprecision(1) << sr << "/5";
    std::cout << "\n";
}