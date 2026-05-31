#include "../include/Ocenka.h"
#include <iostream>
#include <stdexcept>

Ocenka::Ocenka(int zvezdi, const std::string& komentar,
               const std::string& potrebitel)
    : zvezdi(zvezdi), komentar(komentar), potrebitel(potrebitel)
{
    if (zvezdi < 1 || zvezdi > 5)
        throw std::invalid_argument("Zvezdite trqbva da sa mejdu 1 i 5!");
}

void Ocenka::pokazi() const {
    std::cout << "  [" << potrebitel << "] ";
    for (int i = 0; i < zvezdi; i++) std::cout << "*";
    if (!komentar.empty()) std::cout << " - " << komentar;
    std::cout << "\n";
}