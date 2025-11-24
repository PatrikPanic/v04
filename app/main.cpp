#include "app.h"
#include <iostream>

int main() {
    int id = 0;
    vsite::oop::v4::leg_counter counter;

    do {
        std::cout << "Enter animal id (1-3) (0 to stop): ";
        std::cin >> id;

        if (id == 0) break;
        if (id < 1 || id > 3) {
            std::cout << "Invalid id!" << std::endl;
            continue;
        }

        auto a = vsite::oop::v4::animal_factory(id);
        std::string speciesName = counter.add_animal(a.get());
        std::cout << "Added: " << speciesName << std::endl;

    } while (id != 0);

    std::cout << "Total legs: " << counter.legs() << std::endl;
}
