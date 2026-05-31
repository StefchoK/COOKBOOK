#pragma once
#include <string>
#include <vector>

class Sastavka {
protected:
    std::string ime;
    std::string edinica;
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

    virtual void   opisanie()    const = 0;
    virtual double getKalorii()  const = 0;
};

class ProstaSastavka : public Sastavka {
private:
    double kalorii;
    double proteini;
    double mazhnini;
    double vyglekhidrati;

public:
    ProstaSastavka(const std::string& ime, const std::string& edinica,
                   const std::string& kat,
                   double kal, double prot, double mazh, double vygl)
        : Sastavka(ime, edinica, kat),
          kalorii(kal), proteini(prot), mazhnini(mazh), vyglekhidrati(vygl) {}

    void   opisanie()        const override;
    double getKalorii()      const override { return kalorii; }
    double getProteini()     const { return proteini; }
    double getMazhnini()     const { return mazhnini; }
    double getVyglekhidrati() const { return vyglekhidrati; }
};

class SlozhnaSastavka : public Sastavka {
private:
    std::vector<std::pair<Sastavka*, double>> podSastavki;

public:
    SlozhnaSastavka(const std::string& ime, const std::string& edinica,
                    const std::string& kat)
        : Sastavka(ime, edinica, kat) {}

    void dodadiPodSastavka(Sastavka* s, double kol) {
        podSastavki.push_back({s, kol});
    }

    const std::vector<std::pair<Sastavka*, double>>&
    getPodSastavki() const { return podSastavki; }

    void   opisanie()   const override;
    double getKalorii() const override;
};