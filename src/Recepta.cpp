#include "../include/Recepta.h"
#include <iostream>
#include <iomanip>

// ============================================================
// Конструктор — валидира портциите
// ============================================================
Recepta::Recepta(const std::string& ime,
                 const std::string& kategoriq,
                 int portcii)
    : ime(ime), kategoriq(kategoriq), portcii(portcii)
{
    if (portcii <= 0) {
        std::cerr << "[!] Невалиден брой порции за \"" << ime
                  << "\", задавам 1.\n";
        this->portcii = 1;
    }
}

// ============================================================
// Функционалност 1 — добавяне
// ============================================================
void Recepta::dodadiSastavka(Sastavka* s, double kolichestvo) {
    if (!s) {
        std::cerr << "[!] Нулев указател към съставка — пропускам.\n";
        return;
    }
    if (kolichestvo <= 0) {
        std::cerr << "[!] Количеството трябва да е > 0 — пропускам.\n";
        return;
    }
    sastavki.push_back({s, kolichestvo});
}

void Recepta::dodadiStapka(const std::string& stapka) {
    if (!stapka.empty())
        stapki.push_back(stapka);
}

// ============================================================
// Изход — пълна рецепта
// ============================================================
void Recepta::pokaziPълно() const {
    std::cout << "\n========================================\n";
    std::cout << "  " << ime << "\n";
    std::cout << "  Категория: " << kategoriq
              << "  |  Порции: " << portcii << "\n";
    std::cout << "========================================\n";

    std::cout << "СЪСТАВКИ:\n";
    for (const auto& [s, kol] : sastavki) {
        std::cout << "  - " << s->getIme() << ": "
                  << std::fixed << std::setprecision(0)
                  << kol << " " << s->getEdinica() << "\n";
    }

    std::cout << "\nНАЧИН НА ПРИГОТВЯНЕ:\n";
    for (size_t i = 0; i < stapki.size(); i++) {
        std::cout << "  " << (i + 1) << ". " << stapki[i] << "\n";
    }
    std::cout << "\n";
}

// ============================================================
// Изход — кратък ред
// ============================================================
void Recepta::pokaziKratko() const {
    std::cout << "  [" << kategoriq << "] "
              << ime << " (" << portcii << " порции)\n";
}
