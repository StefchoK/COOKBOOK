#pragma once
#include <string>
#include <vector>

// ============================================================
// Абстрактен базов клас за всички съставки
// ============================================================
class Sastavka {
protected:
    std::string ime;
    std::string edinica; // "г", "мл", "бр"
    std::string kategoriq;

public:
    Sastavka(const std::string& ime,
             const std::string& edinica,
             const std::string& kat)
        : ime(ime), edinica(edinica), kategoriq(kat) {}

    virtual ~Sastavka() = default;

    std::string getIme()       const { return ime; }
    std::string getEdinica()   const { return edinica; }
    std::string getKategoriq() const { return kategoriq; }

    // pure virtual — всеки подклас го имплементира по свой начин
    virtual void opisanie() const = 0;
};

// ============================================================
// Проста съставка (брашно, яйца, мляко...)
// ============================================================
class ProstaSastavka : public Sastavka {
public:
    ProstaSastavka(const std::string& ime,
                   const std::string& edinica,
                   const std::string& kat)
        : Sastavka(ime, edinica, kat) {}

    void opisanie() const override;
};

// ============================================================
// Сложна съставка (доматен сос = домати + олио + ...)
// ============================================================
class SlozhnaSastavka : public Sastavka {
private:
    std::vector<std::pair<Sastavka*, double>> podSastavki;

public:
    SlozhnaSastavka(const std::string& ime,
                    const std::string& edinica,
                    const std::string& kat)
        : Sastavka(ime, edinica, kat) {}

    void dodadiPodSastavka(Sastavka* s, double kol) {
        podSastavki.push_back({s, kol});
    }

    const std::vector<std::pair<Sastavka*, double>>&
    getPodSastavki() const { return podSastavki; }

    void opisanie() const override;
};
