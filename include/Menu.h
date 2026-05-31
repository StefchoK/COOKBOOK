#pragma once
#include <vector>
#include <string>
#include "Recepta.h"

class Menu {
protected:
    std::vector<Recepta*> recepti; // всички рецепти в менюто (за пазарския списък)
    int period;                    // брой дни

public:
    explicit Menu(int period) : period(period) {}
    virtual ~Menu() = default;

    const std::vector<Recepta*>& getRecepti() const { return recepti; }
    int getPeriod() const { return period; }

    // pure virtual — различна логика при всеки подклас
    virtual void generirai(const std::vector<Recepta*>& nalichni) = 0;
    virtual void pokazi() const = 0;
};

// ============================================================
// Седмично меню — 7 дни × 3 хранения, ротира рецептите
// ============================================================
class SedmichnoMenu : public Menu {
private:
    // [ден][хранене] → рецепта
    std::vector<std::vector<Recepta*>> denove;

public:
    SedmichnoMenu() : Menu(7) { denove.resize(7); }

    void generirai(const std::vector<Recepta*>& nalichni) override;
    void pokazi()   const override;
};

// ============================================================
// Диетично меню — само рецепти с по-малко от maxKalorii
// (калориите ще бъдат добавени в по-късен чекпойнт;
//  тук менюто просто ограничава броя съставки ≤ 4)
// ============================================================
class DietichnoMenu : public Menu {
private:
    int maxSastavki; // праг за "лека" рецепта
    std::vector<std::vector<Recepta*>> denove;

public:
    explicit DietichnoMenu(int maxSast = 4) : Menu(7), maxSastavki(maxSast) {
        denove.resize(7);
    }

    void generirai(const std::vector<Recepta*>& nalichni) override;
    void pokazi()   const override;
};
