#pragma once
#include <vector>
#include <string>
#include "Recepta.h"
#include "Sastavka.h"
#include "Menu.h"

// ============================================================
// Фасаден клас — държи всички рецепти и съставки
// Функционалност 1: dodadiRecepta
// Функционалност 2: tarsi, tarsiPoKategoriq
// Функционалност 4: generiraiPazarskiSpisak
// ============================================================
class GotvarskаKniga {
private:
    std::vector<Recepta*>  recepti;
    std::vector<Sastavka*> sastavki;

public:
    ~GotvarskаKniga();

    // --- Функционалност 1 ---
    void dodadiRecepta(Recepta* r);
    void dodadiSastavka(Sastavka* s);

    const std::vector<Recepta*>&  getRecepti()  const { return recepti; }
    const std::vector<Sastavka*>& getSastavki() const { return sastavki; }

    // --- Функционалност 2 ---
    // Търси по ключова дума в името на рецептата ИЛИ в имената на съставките
    std::vector<Recepta*> tarsi(const std::string& klyuchDuma) const;
    // Търси само по категория (точно съвпадение)
    std::vector<Recepta*> tarsiPoKategoriq(const std::string& kat) const;

    // --- Функционалност 4 ---
    // Генерира пазарски списък от меню — обобщава количества, без дублиране
    std::vector<std::string> generiraiPazarskiSpisak(const Menu* m) const;

    // Помощен изход
    void pokaziVsichki() const;
};
