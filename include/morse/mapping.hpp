#pragma once

#include <array>
#include <cctype>
#include <cstddef>
#include <cstdint>
#include <string_view>
#include <unordered_map>

namespace morse {
namespace internal {

inline constexpr std::string_view unknownSymbol = "*";
inline constexpr unsigned asciiMin = 32;
inline constexpr unsigned asciiMax = 96;
inline constexpr size_t tableSize = asciiMax - asciiMin + 1;

inline constexpr std::array<std::string_view, tableSize> makeEncodeArray() {
  std::array<std::string_view, tableSize> table{};
  table.fill(unknownSymbol);

  // Word division (3 spaces)
  table[' ' - asciiMin] = "   "; // ASCII 32

  // Punctuation
  table['!' - asciiMin] = "-.-.--";
  table['"' - asciiMin] = ".-..-.";
  table['$' - asciiMin] = "...-..-";
  table['&' - asciiMin] = ".-...";
  table['\'' - asciiMin] = ".----.";
  table['(' - asciiMin] = "-.--.";
  table[')' - asciiMin] = "-.--.-";
  table['+' - asciiMin] = ".-.-.";
  table[',' - asciiMin] = "--..--";
  table['-' - asciiMin] = "-....-";
  table['.' - asciiMin] = ".-.-.-";
  table['/' - asciiMin] = "-..-.";
  table[':' - asciiMin] = "---...";
  table[';' - asciiMin] = "-.-.-.";
  table['=' - asciiMin] = "-...-";
  table['?' - asciiMin] = "..--..";
  table['@' - asciiMin] = ".--.-.";
  table['_' - asciiMin] = "..--.-";

  // Digits 0-9
  constexpr std::array<std::string_view, 10> digitCodes = {
      "-----", ".----", "..---", "...--", "....-",
      ".....", "-....", "--...", "---..", "----."};
  for (char c = '0'; c <= '9'; ++c) {
    table[c - asciiMin] = digitCodes[c - '0'];
  }

  // Letters A-Z
  constexpr std::array<std::string_view, 26> letterCodes = {
      ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
      ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
      "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};
  for (char c = 'A'; c <= 'Z'; ++c) {
    table[c - asciiMin] = letterCodes[c - 'A'];
  }

  return table;
};

inline constexpr auto encodeArray = makeEncodeArray();

inline const auto decodeMap = [] {
  std::unordered_map<std::string_view, char> m;
  for (unsigned i = 0; i < tableSize; ++i) {
    auto code = encodeArray[i];
    if (code != unknownSymbol)
      m.emplace(code, static_cast<char>(i + asciiMin));
  }
  return m;
}();
} // namespace internal

} // namespace morse
