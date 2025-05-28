#include "cat.hpp"

#include <iostream>

namespace pets {
void Cat::meow() {
    std::cout << this->name << " says 'General Kenobi!'\n";
}
} // namespace pets
