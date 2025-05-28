#include "morse/morseCodec.hpp"

#include <array>
#include <cctype>
#include <unordered_map>

#include "morse/mapping.hpp"

namespace morse {
std::string_view MorseCodec::encode(char ch) noexcept {
  unsigned uc = static_cast<unsigned char>(ch);
  unsigned up = static_cast<unsigned>(std::toupper(uc));
  if (up < internal::asciiMin || up > internal::asciiMax)
    return internal::unknownSymbol;
  return internal::encodeArray[up - internal::asciiMin];
}

std::string MorseCodec::encode(std::string_view text) {
  std::string out;
  out.reserve(text.size() * 5);
  bool first = true;
  for (char c : text) {
    if (!first)
      out += ' ';
    first = false;
    out += encode(c);
  }
  return out;
}

char MorseCodec::decodeSymbol(std::string_view symbol) noexcept {
  auto it = internal::decodeMap.find(symbol);
  return it != internal::decodeMap.end() ? it->second : '?';
}

std::string MorseCodec::decodeSequence(std::string_view morse, char sep) {
  std::string out;
  std::size_t i = 0;
  while (i < morse.size()) {
    auto j = morse.find(sep, i);
    auto piece = morse.substr(i, j - i);
    out += decodeSymbol(piece);
    if (j == std::string_view::npos)
      break;
    i = j + 1;
  }
  return out;
}

} // namespace morse
