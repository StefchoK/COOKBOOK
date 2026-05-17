#pragma once
#include <string>
#include <vector>
#include "Sastavka.h"

// ============================================================
// Централен клас — една рецепта
// Функционалност 1: Добавяне на рецепта
// ============================================================
class Recepta {
private:
    std::string ime;
    std::string kategoriq;  // "закуска", "основно", "десерт"...
    int portcii;
    std::vector<std::pair<Sastavka*, double>> sastavki; // (съставка, количество)
    std::vector<std::string> stapki;                    // стъпки на приготвяне

public:
    Recepta(const std::string& ime,
            const std::string& kategoriq,
            int portcii);

    // Getters
    std::string getIme()       const { return ime; }
    std::string getKategoriq() const { return kategoriq; }
    int         getPortcii()   const { return portcii; }

    const std::vector<std::pair<Sastavka*, double>>& getSastavki() const {
        return sastavki;
    }
    const std::vector<std::string>& getStapki() const {
        return stapki;
    }

    // Функционалност 1 — добавяне на съставка и стъпка
    void dodadiSastavka(Sastavka* s, double kolichestvo);
    void dodadiStapka(const std::string& stapka);

    // Изход
    void pokaziPълно()  const;   // пълна рецепта
    void pokaziKratko() const;   // един ред (за списъци)
};
