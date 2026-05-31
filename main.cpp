#include <iostream>
#include <iomanip>
#include <string>
#include "include/Sastavka.h"
#include "include/Recepta.h"
#include "include/Menu.h"
#include "include/GotvarskaKniga.h"

static void sep(const std::string& zaglavie) {
    std::cout << "\n############################################\n";
    std::cout << "#  " << zaglavie << "\n";
    std::cout << "############################################\n";
}

int main() {
    std::cout << "================================================\n";
    std::cout << "  ГОТВАРСКА КНИГА  —  Стефан Янакиев, 10Б №25\n";
    std::cout << "================================================\n";

    // --------------------------------------------------------
    // Създаваме съставки (ProstaSastavka и SlozhnaSastavka)
    // --------------------------------------------------------
    auto* brasno  = new ProstaSastavka("Брашно",  "г",  "зърнени");
    auto* yaytsa  = new ProstaSastavka("Яйца",    "бр", "млечни");
    auto* mlyako  = new ProstaSastavka("Мляко",   "мл", "млечни");
    auto* zahar   = new ProstaSastavka("Захар",   "г",  "подправки");
    auto* olio    = new ProstaSastavka("Олио",    "мл", "мазнини");
    auto* domati  = new ProstaSastavka("Домати",  "г",  "зеленчуци");
    auto* kaima   = new ProstaSastavka("Кайма",   "г",  "месо");
    auto* orizh   = new ProstaSastavka("Ориз",    "г",  "зърнени");
    auto* sirene  = new ProstaSastavka("Сирене",  "г",  "млечни");
    auto* spinat  = new ProstaSastavka("Спанак",  "г",  "зеленчуци");
    auto* kartof  = new ProstaSastavka("Картофи", "г",  "зеленчуци");

    // Сложна съставка: Доматен сос = домати + олио
    auto* domatSos = new SlozhnaSastavka("Доматен сос", "г", "сосове");
    domatSos->dodadiPodSastavka(domati, 200);
    domatSos->dodadiPodSastavka(olio,   20);

    std::cout << "\nСъздадени съставки:\n";
    brasno->opisanie();
    domatSos->opisanie();

    // --------------------------------------------------------
    // ФУНКЦИОНАЛНОСТ 1 — Добавяне на рецепти
    // --------------------------------------------------------
    sep("ФУНКЦ. 1 — Добавяне на рецепта");

    auto* palachinki = new Recepta("Палачинки", "закуска", 4);
    palachinki->dodadiSastavka(brasno, 200);
    palachinki->dodadiSastavka(yaytsa, 2);
    palachinki->dodadiSastavka(mlyako, 300);
    palachinki->dodadiSastavka(zahar,  30);
    palachinki->dodadiSastavka(olio,   20);
    palachinki->dodadiStapka("Смесете брашно, яйца и мляко до гладка смес.");
    palachinki->dodadiStapka("Добавете захарта и олиото, разбъркайте.");
    palachinki->dodadiStapka("Пържете на умерен огън от двете страни.");

    auto* boloneze = new Recepta("Спагети Болонезе", "основно", 4);
    boloneze->dodadiSastavka(kaima,    400);
    boloneze->dodadiSastavka(domatSos, 300);
    boloneze->dodadiSastavka(orizh,     50);
    boloneze->dodadiStapka("Задушете каймата на тиган.");
    boloneze->dodadiStapka("Добавете доматения сос, ври 20 мин.");
    boloneze->dodadiStapka("Сервирайте върху сварения ориз.");

    auto* banica = new Recepta("Баница", "закуска", 8);
    banica->dodadiSastavka(sirene, 300);
    banica->dodadiSastavka(yaytsa,   3);
    banica->dodadiSastavka(brasno, 400);
    banica->dodadiSastavka(olio,    50);
    banica->dodadiStapka("Замесете тесто от брашно, яйца и олио.");
    banica->dodadiStapka("Наредете на редове тесто и плънка от сирене.");
    banica->dodadiStapka("Печете на 200°C 35 минути.");

    auto* salata = new Recepta("Спаначена салата", "салата", 2);
    salata->dodadiSastavka(spinat, 150);
    salata->dodadiSastavka(domati, 100);
    salata->dodadiSastavka(olio,    10);
    salata->dodadiStapka("Измийте спанака и наредете в купа.");
    salata->dodadiStapka("Нарежете доматите, добавете олио.");

    auto* pechKartof = new Recepta("Печени картофи", "гарнитура", 4);
    pechKartof->dodadiSastavka(kartof, 600);
    pechKartof->dodadiSastavka(olio,    30);
    pechKartof->dodadiStapka("Нарежете картофите на резени.");
    pechKartof->dodadiStapka("Наредете в тава с олио, печете 200°C / 40 мин.");

    // Добавяме всичко в книгата
    GotvarskаKniga kniga;
    kniga.dodadiSastavka(brasno);   kniga.dodadiSastavka(yaytsa);
    kniga.dodadiSastavka(mlyako);   kniga.dodadiSastavka(zahar);
    kniga.dodadiSastavka(olio);     kniga.dodadiSastavka(domati);
    kniga.dodadiSastavka(kaima);    kniga.dodadiSastavka(orizh);
    kniga.dodadiSastavka(sirene);   kniga.dodadiSastavka(spinat);
    kniga.dodadiSastavka(kartof);   kniga.dodadiSastavka(domatSos);

    kniga.dodadiRecepta(palachinki);
    kniga.dodadiRecepta(boloneze);
    kniga.dodadiRecepta(banica);
    kniga.dodadiRecepta(salata);
    kniga.dodadiRecepta(pechKartof);

    kniga.pokaziVsichki();

    // Показваме пълна рецепта
    palachinki->pokaziPълно();

    // Демонстрация на невалидно добавяне (валидация)
    std::cout << "--- Тест на валидация ---\n";
    Recepta testR("Тест", "десерт", -5); // невалиден брой порции
    testR.dodadiSastavka(nullptr, 100);  // nullptr съставка
    testR.dodadiSastavka(brasno,  -50);  // отрицателно количество

    // --------------------------------------------------------
    // ФУНКЦИОНАЛНОСТ 2 — Търсене на рецепти
    // --------------------------------------------------------
    sep("ФУНКЦ. 2 — Търсене на рецепти");

    // по ключова дума в ИМЕТО
    std::cout << "Търсене по \"Баница\":\n";
    for (auto* r : kniga.tarsi("Баница"))
        r->pokaziKratko();

    // по ключова дума в СЪСТАВКИТЕ
    std::cout << "\nТърсене по съставка \"Домати\":\n";
    for (auto* r : kniga.tarsi("Домати"))
        r->pokaziKratko();

    // по КАТЕГОРИЯ
    std::cout << "\nТърсене по категория \"закуска\":\n";
    for (auto* r : kniga.tarsiPoKategoriq("закуска"))
        r->pokaziKratko();

    // търсене без резултат
    std::cout << "\nТърсене по \"Шоколад\" (очакваме 0 резултата):\n";
    auto res = kniga.tarsi("Шоколад");
    if (res.empty()) std::cout << "  (няма намерени рецепти)\n";

    // --------------------------------------------------------
    // ФУНКЦИОНАЛНОСТ 3 — Планиране на меню
    // --------------------------------------------------------
    sep("ФУНКЦ. 3 — Планиране на меню");

    std::cout << "\n--- Седмично меню ---\n";
    SedmichnoMenu sedmichno;
    sedmichno.generirai(kniga.getRecepti());
    sedmichno.pokazi();

    std::cout << "\n--- Диетично меню (макс. 3 съставки) ---\n";
    DietichnoMenu dietichno(3);
    dietichno.generirai(kniga.getRecepti());
    dietichno.pokazi();

    // --------------------------------------------------------
    // ФУНКЦИОНАЛНОСТ 4 — Пазарски списък
    // --------------------------------------------------------
    sep("ФУНКЦ. 4 — Пазарски списък от седмичното меню");

    auto spisak = kniga.generiraiPazarskiSpisak(&sedmichno);
    std::cout << "Трябва да купите (" << spisak.size() << " артикула):\n";
    for (const auto& red : spisak)
        std::cout << "  " << red << "\n";

    std::cout << "\n================================================\n";
    std::cout << "  Всички 4 функционалности работят!\n";
    std::cout << "================================================\n\n";

    return 0; // GotvarskаKniga::~GotvarskаKniga() освобождава паметта
}
