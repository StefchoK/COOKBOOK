#include "COOKBOOK/include/PotrebitelskiProfil.h"
#include <iostream>

PotrebitelskiProfil::PotrebitelskiProfil(const std::string& ime,
                                          const std::string& cel)
    : ime(ime), cel(cel) {}

void PotrebitelskiProfil::dodadiAlergiq(const std::string& a) {
    alergii.push_back(a);
}

void PotrebitelskiProfil::dodadiPredpochitanie(const std::string& p) {
    predpochitaniq.push_back(p);
}

bool PotrebitelskiProfil::imaAlergiq(const std::string& imeNaSastavka) const {
    for (const auto& a : alergii)
        if (imeNaSastavka.find(a) != std::string::npos) return true;
    return false;
}

void PotrebitelskiProfil::zapaziBeljazan(Recepta* r) {
    if (!r) return;
    for (auto* fav : lyubimiRecepti)
        if (fav == r) {
            std::cout << "  \"" << r->getIme() << "\" veche e v lyubimi.\n";
            return;
        }
    lyubimiRecepti.push_back(r);
    std::cout << "  Dobavena v lyubimi: \"" << r->getIme() << "\"\n";
}

void PotrebitelskiProfil::pokaziLyubimi() const {
    std::cout << "\n=== Lyubimi recepti na " << ime << " ===\n";
    if (lyubimiRecepti.empty()) {
        std::cout << "  (nqma zapazeni lyubimi)\n";
        return;
    }
    for (const auto* r : lyubimiRecepti) r->pokaziKratko();
}

void PotrebitelskiProfil::pokaziProfil() const {
    std::cout << "\n=== Profil: " << ime << " ===\n";
    std::cout << "  Cel: " << cel << "\n";
    std::cout << "  Alergii: ";
    if (alergii.empty()) std::cout << "nqma";
    else for (size_t i = 0; i < alergii.size(); i++) {
        if (i) std::cout << ", ";
        std::cout << alergii[i];
    }
    std::cout << "\n  Lyubimi recepti: " << lyubimiRecepti.size() << "\n";
}