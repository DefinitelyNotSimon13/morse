/**
 * @file cat.hpp
 * @brief [Brief description]
 *
 * @details
 * This file contains [...].
 *
 * @see
 *  src/pets/cat.cpp
 */
#include <string>

/**
 * @brief This namespace contains pets of all kinds
 */
namespace pets {

/**
 * @brief This class represents a cat
 *
 * @details
 * A cat represented by this class can meow and has a name.
 */
class Cat {
public:
    /**
     * @brief Constructor of the Cat class
     *
     * @param[in] catName The name of the cat.
     */
    Cat(const std::string& catName): name(catName) {}

    /**
     * @brief Let the cat make a sound.
     *
     * @details
     * This method lets the cat make a sound. Upon invokation
     * the name of the cat is printed and following it's sound.
    */
    void meow();

private:
    /**
    * @brief The name of the cat
    */
    std::string name;
};
}
