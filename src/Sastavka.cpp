#include "../include/Sastavka.h"
#include <iostream>

// ============================================================
// ProstaSastavka
// ============================================================
void ProstaSastavka::opisanie() const {
    std::cout << "  [Проста] " << ime
              << " (" << kategoriq << ")"
              << " | единица: " << edinica << "\n";
}

// ============================================================
// SlozhnaSastavka
// ============================================================
void SlozhnaSastavka::opisanie() const {
    std::cout << "  [Сложна] " << ime
              << " — съставена от " << podSastavki.size() << " под-съставки:\n";
    for (const auto& [s, kol] : podSastavki) {
        std::cout << "      -> " << s->getIme()
                  << ": " << kol << " " << s->getEdinica() << "\n";
    }
}
