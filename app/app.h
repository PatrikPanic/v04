#pragma once
#include <string>
#include <memory>

namespace vsite::oop::v4 {

    class animal {
    public:
        virtual std::string species() const = 0;
        virtual unsigned int legs() const = 0;
        virtual ~animal() = default;
    };

    // Abstraktne klase
    class insect : public animal {
    public:
        unsigned int legs() const override;
    };

    class bird : public animal {
    public:
        unsigned int legs() const override;
    };

    class spider : public animal {
    public:
        unsigned int legs() const override;
    };

    // Konkretne klase
    class cockroach : public insect {
    public:
        std::string species() const override;
    };

    class sparrow : public bird {
    public:
        std::string species() const override;
    };

    class tarantula : public spider {
    public:
        std::string species() const override;
    };

    // Factory funkcija
    std::unique_ptr<animal> animal_factory(int id);

    class leg_counter {
        unsigned int total_legs = 0;
    public:
        std::string add_animal(const animal* a);
        unsigned int legs() const;
    };

}
