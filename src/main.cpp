#include <cstdlib>
#include <iostream>
#include <string>

#include <boost/json.hpp>
#include <boost/log/trivial.hpp>
#include <fstream>
#include <iostream>

#include "morse/morseCodec.hpp"


int main() {
    // Toggle mode: true = encode, false = decode
    constexpr bool doEncode = false;

    if constexpr (doEncode) {
        std::cout << "===========================\n"
                  << "    Morse Code Encoder    \n"
                  << "===========================\n";
        std::cout << "Enter plain text lines (Ctrl+D to exit):\n";
    } else {
        std::cout << "===========================\n"
                  << "    Morse Code Decoder    \n"
                  << "===========================\n";
        std::cout << "Enter Morse code lines (Ctrl+D to exit):\n";
    }
    std::cout << std::endl;

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty()) continue;

        std::string result;
        if constexpr (doEncode) {
            result = morse::MorseCodec::encode(line);
        } else {
            result = morse::MorseCodec::decodeSequence(line);
        }

        // Print nicely with color for output (green) and reset
        const char* green = "\033[1;32m";
        const char* reset = "\033[0m";

        std::cout << "\nInput:  " << line << "\n"
                  << "Output: " << green << result << reset << "\n";
    }

    return 0;
}

