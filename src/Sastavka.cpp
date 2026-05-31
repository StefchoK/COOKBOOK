#include "../include/Sastavka.h"
#include <iostream>

void ProstaSastavka::opisanie() const {
    std::cout << "  [Proста] " << ime
              << " (" << kategoriq << ")"
              << " | " << kalorii << " kcal/100g\n";
}

void SlozhnaSastavka::opisanie() const {
    std::cout << "  [Slozhna] " << ime
              << " — sastavena ot " << podSastavki.size() << " pod-sastavki:\n";
    for (const auto& [s, kol] : podSastavki)
        std::cout << "    -> " << s->getIme()
                  << ": " << kol << " " << s->getEdinica() << "\n";
}

double SlozhnaSastavka::getKalorii() const {
    double total = 0;
    for (const auto& [s, kol] : podSastavki)
        total += s->getKalorii() * kol / 100.0;
    return total;
}