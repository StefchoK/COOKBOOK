#pragma once
#include <string>
#include <vector>
#include "Recepta.h"

class PotrebitelskiProfil {
private:
    std::string ime;
    std::vector<std::string> alergii;
    std::vector<std::string> predpochitaniq;
    std::string cel;                       
    std::vector<Recepta*> lyubimiRecepti;   
public:
    PotrebitelskiProfil(const std::string& ime, const std::string& cel);

    std::string getIme() const { return ime; }
    std::string getCel() const { return cel; }

    void dodadiAlergiq(const std::string& a);
    void dodadiPredpochitanie(const std::string& p);
    bool imaAlergiq(const std::string& imeNaSastavka) const;
    const std::vector<std::string>& getAllergii() const { return alergii; }

    void zapaziBeljazan(Recepta* r);
    const std::vector<Recepta*>& getLyubimiRecepti() const { return lyubimiRecepti; }
    void pokaziLyubimi() const;

    void pokaziProfil() const;
};