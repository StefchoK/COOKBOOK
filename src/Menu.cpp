#include "../include/Menu.h"
#include <iostream>
#include <iomanip>

// Имена на дните на седмицата
static const std::string DNI[7] = {
    "Понеделник", "Вторник", "Сряда",
    "Четвъртък",  "Петък",   "Събота", "Неделя"
};
static const std::string HRANENYA[3] = { "Закуска", "Обяд   ", "Вечеря " };

// ============================================================
// СедмичноМеню
// ============================================================
void SedmichnoMenu::generirai(const std::vector<Recepta*>& nalichni) {
    if (nalichni.empty()) {
        std::cerr << "[!] Няма налични рецепти за генериране на меню!\n";
        return;
    }

    // Изчистваме предишно съдържание
    for (auto& d : denove) d.clear();
    recepti.clear();

    // Ротираме рецептите равномерно по дни и хранения
    size_t idx = 0;
    for (int d = 0; d < 7; d++) {
        for (int h = 0; h < 3; h++) {
            Recepta* r = nalichni[idx % nalichni.size()];
            denove[d].push_back(r);
            recepti.push_back(r);
            idx++;
        }
    }
}

void SedmichnoMenu::pokazi() const {
    std::cout << "\n========== СЕДМИЧНО МЕНЮ ==========\n";
    for (int d = 0; d < 7; d++) {
        std::cout << "\n  " << DNI[d] << ":\n";
        for (size_t h = 0; h < denove[d].size(); h++) {
            std::cout << "    " << HRANENYA[h] << ": "
                      << denove[d][h]->getIme() << "\n";
        }
    }
    std::cout << "====================================\n";
}

// ============================================================
// ДиетичноМеню — включва само "леки" рецепти (≤ maxSastavki)
// ============================================================
void DietichnoMenu::generirai(const std::vector<Recepta*>& nalichni) {
    if (nalichni.empty()) {
        std::cerr << "[!] Няма налични рецепти!\n";
        return;
    }

    // Филтрираме по брой съставки
    std::vector<Recepta*> leки;
    for (Recepta* r : nalichni) {
        if (static_cast<int>(r->getSastavki().size()) <= maxSastavki)
            leки.push_back(r);
    }

    if (leки.empty()) {
        std::cout << "[!] Няма рецепти с <= " << maxSastavki
                  << " съставки. Взимам всички.\n";
        leки = nalichni;
    }

    for (auto& d : denove) d.clear();
    recepti.clear();

    size_t idx = 0;
    for (int d = 0; d < 7; d++) {
        for (int h = 0; h < 3; h++) {
            Recepta* r = leки[idx % leки.size()];
            denove[d].push_back(r);
            recepti.push_back(r);
            idx++;
        }
    }
}

void DietichnoMenu::pokazi() const {
    std::cout << "\n===== ДИЕТИЧНО МЕНЮ (макс. "
              << maxSastavki << " съставки/рецепта) =====\n";
    for (int d = 0; d < 7; d++) {
        std::cout << "\n  " << DNI[d] << ":\n";
        for (size_t h = 0; h < denove[d].size(); h++) {
            std::cout << "    " << HRANENYA[h] << ": "
                      << denove[d][h]->getIme() << "\n";
        }
    }
    std::cout << "=============================================\n";
}
