#pragma once
#include <string>

class Ocenka {
private:
    int zvezdi;
    std::string komentar;
    std::string potrebitel;

public:
    Ocenka(int zvezdi, const std::string& komentar,
           const std::string& potrebitel);

    int         getZvezdi()    const { return zvezdi; }
    std::string getKomentar()  const { return komentar; }
    std::string getPotrebitel() const { return potrebitel; }

    void pokazi() const;
};