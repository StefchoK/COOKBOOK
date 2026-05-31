#include "../include/GotvarskaKniga.h"
#include <iostream>
#include <map>
#include <iomanip>

// ============================================================
// Деструктор — изчиства динамичната памет
// ============================================================
GotvarskаKniga::~GotvarskаKniga() {
    for (auto* r : recepti)  delete r;
    for (auto* s : sastavki) delete s;
}

// ============================================================
// Функционалност 1 — добавяне
// ============================================================
void GotvarskаKniga::dodadiRecepta(Recepta* r) {
    if (r) recepti.push_back(r);
}

void GotvarskаKniga::dodadiSastavka(Sastavka* s) {
    if (s) sastavki.push_back(s);
}

// ============================================================
// Функционалност 2 — търсене по ключова дума
// Проверяваме: а) името на рецептата, б) имената на съставките
// ============================================================
std::vector<Recepta*>
GotvarskаKniga::tarsi(const std::string& klyuchDuma) const {
    std::vector<Recepta*> rezultati;
    for (auto* r : recepti) {
        bool nameren = false;

        // а) в името на рецептата
        if (r->getIme().find(klyuchDuma) != std::string::npos)
            nameren = true;

        // б) в имената на съставките
        if (!nameren) {
            for (const auto& [s, _] : r->getSastavki()) {
                if (s->getIme().find(klyuchDuma) != std::string::npos) {
                    nameren = true;
                    break;
                }
            }
        }

        if (nameren) rezultati.push_back(r);
    }
    return rezultati;
}

// Търсене по категория (точно съвпадение)
std::vector<Recepta*>
GotvarskаKniga::tarsiPoKategoriq(const std::string& kat) const {
    std::vector<Recepta*> rezultati;
    for (auto* r : recepti)
        if (r->getKategoriq() == kat)
            rezultati.push_back(r);
    return rezultati;
}

// ============================================================
// Функционалност 4 — пазарски списък от меню
// Обобщаваме количествата на еднаквите съставки (без дублиране)
// ============================================================
std::vector<std::string>
GotvarskаKniga::generiraiPazarskiSpisak(const Menu* m) const {
    // map: ime -> (общо количество, единица)
    std::map<std::string, std::pair<double, std::string>> obshto;

    for (const auto* r : m->getRecepti()) {
        for (const auto& [s, kol] : r->getSastavki()) {
            const std::string& key = s->getIme();
            if (obshto.count(key))
                obshto[key].first += kol;
            else
                obshto[key] = {kol, s->getEdinica()};
        }
    }

    std::vector<std::string> spisak;
    for (const auto& [ime, info] : obshto) {
        // форматираме: "- Брашно: 1400 г"
        std::string red = "- " + ime + ": "
            + std::to_string(static_cast<int>(info.first))
            + " " + info.second;
        spisak.push_back(red);
    }
    return spisak;
}

// ============================================================
// Помощен изход
// ============================================================
void GotvarskаKniga::pokaziVsichki() const {
    std::cout << "\n=== Всички рецепти в книгата ("
              << recepti.size() << ") ===\n";
    for (const auto* r : recepti)
        r->pokaziKratko();
}
