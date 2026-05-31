#pragma once
#include <string>
#include <vector>
#include "Sastavka.h"
#include "Ocenka.h"

struct HranitelnаInfo {
    double kalorii      = 0;
    double proteini     = 0;
    double mazhnini     = 0;
    double vyglekhidrati = 0;
};

class Recepta {
private:
    std::string ime;
    std::string kategoriq;
    int portcii;
    std::vector<std::pair<Sastavka*, double>> sastavki;
    std::vector<std::string> stapki;
    std::vector<Ocenka> ocenki;     

public:
    Recepta(const std::string& ime,
            const std::string& kategoriq,
            int portcii);

    std::string getIme()       const { return ime; }
    std::string getKategoriq() const { return kategoriq; }
    int         getPortcii()   const { return portcii; }
    const std::vector<std::pair<Sastavka*, double>>& getSastavki() const { return sastavki; }
    const std::vector<std::string>& getStapki() const { return stapki; }

    void dodadiSastavka(Sastavka* s, double kolichestvo);
    void dodadiStapka(const std::string& stapka);

    void dodadiOcenka(const Ocenka& o);
    double getSrednaOcenka() const;
    void pokaziOcenki() const;

    HranitelnаInfo getHranitelnаInfo() const;

    Recepta* mashtabirane(int novPortcii) const;

    void pokaziPълно()  const;
    void pokaziKratko() const;
};