#include <iostream>
#include <iomanip>
#include <string>
#include "include/Sastavka.h"
#include "include/Ocenka.h"
#include "include/Recepta.h"
#include "include/Menu.h"
#include "include/GotvarskaKniga.h"
#include "include/PotrebitelskiProfil.h"

static void sep(const std::string& s) {
    std::cout << "\n############################################\n";
    std::cout << "#  " << s << "\n";
    std::cout << "############################################\n";
}

int main() {
    std::cout << "================================================\n";
    std::cout << "  GOTВARSKA KNIGA  —  Stefan Yanakiev, 10B #25\n";
    std::cout << "================================================\n";

    // ── Съставки ────────────────────────────────────────────
    auto* brasno  = new ProstaSastavka("Brasno",  "g",  "zarneni",    364, 10,  1, 76);
    auto* yaytsa  = new ProstaSastavka("Yaytsa",  "br", "mlachni",    155, 13, 11,  1);
    auto* mlyako  = new ProstaSastavka("Mlyako",  "ml", "mlachni",     42,  3,  1,  5);
    auto* zahar   = new ProstaSastavka("Zahar",   "g",  "podpravki",  387,  0,  0,100);
    auto* olio    = new ProstaSastavka("Olio",    "ml", "mazhnini",   884,  0,100,  0);
    auto* domati  = new ProstaSastavka("Domati",  "g",  "zelenchuti",  18,  1,  0,  4);
    auto* kaima   = new ProstaSastavka("Kaima",   "g",  "meso",       250, 17, 20,  0);
    auto* orizh   = new ProstaSastavka("Oriz",    "g",  "zarneni",    360,  7,  1, 78);
    auto* sirene  = new ProstaSastavka("Sirene",  "g",  "mlachni",    260, 14, 22,  2);
    auto* spinat  = new ProstaSastavka("Spinak",  "g",  "zelenchuti",  23,  3,  0,  4);
    auto* kartof  = new ProstaSastavka("Kartof",  "g",  "zelenchuti",  77,  2,  0, 17);

    auto* domatSos = new SlozhnaSastavka("Domaten sos", "g", "sosove");
    domatSos->dodadiPodSastavka(domati, 200);
    domatSos->dodadiPodSastavka(olio,    20);

    // ── Рецепти ─────────────────────────────────────────────
    auto* palachinki = new Recepta("Palachinki", "zakuska", 4);
    palachinki->dodadiSastavka(brasno, 200);
    palachinki->dodadiSastavka(yaytsa,   2);
    palachinki->dodadiSastavka(mlyako, 300);
    palachinki->dodadiSastavka(zahar,   30);
    palachinki->dodadiSastavka(olio,    20);
    palachinki->dodadiStapka("Smesete brasnoto, yaytsa i mlyakoto.");
    palachinki->dodadiStapka("Dobavete zaharta i olioto.");
    palachinki->dodadiStapka("Parzhhete ot dvete strani.");

    auto* boloneze = new Recepta("Spageti Boloneze", "osnovno", 4);
    boloneze->dodadiSastavka(kaima,    400);
    boloneze->dodadiSastavka(domatSos, 300);
    boloneze->dodadiSastavka(orizh,     50);
    boloneze->dodadiStapka("Zadushete kaimata na tigan.");
    boloneze->dodadiStapka("Dobavete domatenia sos, vri 20 min.");
    boloneze->dodadiStapka("Servirajte varhu oriz.");

    auto* banica = new Recepta("Banica", "zakuska", 8);
    banica->dodadiSastavka(sirene, 300);
    banica->dodadiSastavka(yaytsa,   3);
    banica->dodadiSastavka(brasno, 400);
    banica->dodadiSastavka(olio,    50);
    banica->dodadiStapka("Zameste testo.");
    banica->dodadiStapka("Naredete na redove testo i planka.");
    banica->dodadiStapka("Pechete 200C / 35 min.");

    auto* salata = new Recepta("Spanachena salata", "salata", 2);
    salata->dodadiSastavka(spinat, 150);
    salata->dodadiSastavka(domati, 100);
    salata->dodadiSastavka(olio,    10);
    salata->dodadiStapka("Izmijte spinaka.");
    salata->dodadiStapka("Narezhete domatite, dobavete olio.");

    auto* kartofeni = new Recepta("Pecheni kartofeni", "garnitura", 4);
    kartofeni->dodadiSastavka(kartof, 600);
    kartofeni->dodadiSastavka(olio,    30);
    kartofeni->dodadiStapka("Narezhete kartofite.");
    kartofeni->dodadiStapka("Pechete 200C / 40 min.");

    // ── GotvarskаKniga ──────────────────────────────────────
    GotvarskаKniga kniga;
    kniga.dodadiSastavka(brasno);  kniga.dodadiSastavka(yaytsa);
    kniga.dodadiSastavka(mlyako);  kniga.dodadiSastavka(zahar);
    kniga.dodadiSastavka(olio);    kniga.dodadiSastavka(domati);
    kniga.dodadiSastavka(kaima);   kniga.dodadiSastavka(orizh);
    kniga.dodadiSastavka(sirene);  kniga.dodadiSastavka(spinat);
    kniga.dodadiSastavka(kartof);  kniga.dodadiSastavka(domatSos);
    kniga.dodadiRecepta(palachinki);
    kniga.dodadiRecepta(boloneze);
    kniga.dodadiRecepta(banica);
    kniga.dodadiRecepta(salata);
    kniga.dodadiRecepta(kartofeni);

    // ────────────────────────────────────────────────────────
    sep("FUNK. 1 — Dobavqne na recepta");
    kniga.pokaziVsichki();

    // ────────────────────────────────────────────────────────
    sep("FUNK. 2 — Tarsene");
    std::cout << "Tarsene po 'Banica':\n";
    for (auto* r : kniga.tarsi("Banica"))       r->pokaziKratko();
    std::cout << "\nTarsene po sastavka 'Domati':\n";
    for (auto* r : kniga.tarsi("Domati"))       r->pokaziKratko();
    std::cout << "\nTarsene po kategoriq 'zakuska':\n";
    for (auto* r : kniga.tarsiPoKategoriq("zakuska")) r->pokaziKratko();

    // ────────────────────────────────────────────────────────
    sep("FUNK. 3 — Planirane na meniu");
    SedmichnoMenu sedmichno;
    sedmichno.generirai(kniga.getRecepti());
    sedmichno.pokazi();

    DietichnoMenu dietichno(3);
    dietichno.generirai(kniga.getRecepti());
    dietichno.pokazi();

    // ────────────────────────────────────────────────────────
    sep("FUNK. 4 — Pazarski spisak");
    auto spisak = kniga.generiraiPazarskiSpisak(&sedmichno);
    std::cout << "Tryabva da kupite (" << spisak.size() << " artikula):\n";
    for (const auto& red : spisak) std::cout << "  " << red << "\n";

    // ────────────────────────────────────────────────────────
    sep("FUNK. 5 — Upravlenie na sastavki");
    std::cout << "Opisanie na sastavkite:\n";
    for (const auto* s : kniga.getSastavki()) s->opisanie();

    // ────────────────────────────────────────────────────────
    sep("FUNK. 6 — Ocenqvane na recepti");
    palachinki->dodadiOcenka(Ocenka(5, "Strahotni!", "Maria"));
    palachinki->dodadiOcenka(Ocenka(4, "Mnogo dobri", "Ivan"));
    palachinki->dodadiOcenka(Ocenka(5, "Perfektni!", "Petq"));
    boloneze->dodadiOcenka(Ocenka(4, "Vkusno!", "Todor"));
    boloneze->dodadiOcenka(Ocenka(3, "Dobre", "Ana"));
    banica->dodadiOcenka(Ocenka(5, "Kato domashna!", "Baba Mara"));

    std::cout << "Ocenki za Palachinki:\n";
    palachinki->pokaziOcenki();
    std::cout << "\nOcenki za Boloneze:\n";
    boloneze->pokaziOcenki();

    // ────────────────────────────────────────────────────────
    sep("FUNK. 7 — Hranitelna informaciq");
    for (const auto* r : kniga.getRecepti()) {
        auto info = r->getHranitelnаInfo();
        std::cout << "  " << r->getIme() << ": "
                  << std::fixed << std::setprecision(0)
                  << info.kalorii << " kcal | "
                  << info.proteini << "g prot | "
                  << info.mazhnini << "g mazh | "
                  << info.vyglekhidrati << "g vagl\n";
    }
    std::cout << "\nPodrobno za Palachinki:\n";
    palachinki->pokaziPълно();

    // ────────────────────────────────────────────────────────
    sep("FUNK. 8 & 9 — Potrebitelski profil + Lyubimi");
    PotrebitelskiProfil stefan("Stefan", "nabor na masa");
    stefan.dodadiAlergiq("Sirene");
    stefan.dodadiPredpochitanie("meso");
    stefan.pokaziProfil();

    stefan.zapaziBeljazan(palachinki);
    stefan.zapaziBeljazan(boloneze);
    stefan.zapaziBeljazan(palachinki); // vtori opyt — ne se dobavq

    stefan.pokaziLyubimi();

    std::cout << "\nProverka za alergii:\n";
    for (const auto* r : kniga.getRecepti()) {
        bool ok = true;
        for (const auto& [s, _] : r->getSastavki())
            if (stefan.imaAlergiq(s->getIme())) {
                std::cout << "  [!] " << r->getIme()
                          << " — sodarzha alergent: " << s->getIme() << "\n";
                ok = false;
            }
        if (ok) std::cout << "  [OK] " << r->getIme() << "\n";
    }

    // ────────────────────────────────────────────────────────
    sep("FUNK. 10 — Mashtabirane na recepta");
    std::cout << "Originalna (4 portcii):\n";
    for (const auto& [s, kol] : palachinki->getSastavki())
        std::cout << "  " << s->getIme() << ": "
                  << std::fixed << std::setprecision(0)
                  << kol << " " << s->getEdinica() << "\n";

    Recepta* p10 = palachinki->mashtabirane(10);
    std::cout << "\nMashtabirani (10 portcii):\n";
    for (const auto& [s, kol] : p10->getSastavki())
        std::cout << "  " << s->getIme() << ": "
                  << std::fixed << std::setprecision(0)
                  << kol << " " << s->getEdinica() << "\n";
    delete p10;

    std::cout << "\n================================================\n";
    std::cout << "  Vsichki 10 funkcionalnosti demonstrirani!\n";
    std::cout << "================================================\n\n";

    return 0;
}