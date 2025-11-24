#include "app.h"
#include <algorithm>

namespace vsite::oop::v4 {

    // Factory funkcija
    std::unique_ptr<animal> animal_factory(int id) {
        switch (id) {
        case 1: return std::make_unique<cockroach>();
        case 2: return std::make_unique<sparrow>();
        case 3: return std::make_unique<tarantula>();
        default: return nullptr;
        }
    }

    // species implementacija
    std::string cockroach::species() const { return "cockroach"; }
    std::string sparrow::species() const { return "sparrow"; }
    std::string tarantula::species() const { return "tarantula"; }

    // legs implementacija
    unsigned int insect::legs() const { return 6u; }
    unsigned int bird::legs() const { return 2u; }
    unsigned int spider::legs() const { return 8u; }

    // leg_counter implementacija
    std::string leg_counter::add_animal(const animal* a) {
        if (!a) return "";
        total_legs += a->legs();
        return a->species();
    }

    unsigned int leg_counter::legs() const {
        return total_legs;
    }

}
