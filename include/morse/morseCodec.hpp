#pragma once

#include <string>
#include <string_view>

namespace morse {

class MorseCodec {
public:
  static std::string_view encode(char ch) noexcept;

  static std::string encode(std::string_view text);

  static char decodeSymbol(std::string_view symbol) noexcept;

  static std::string decodeSequence(std::string_view morse, char sep = ' ');
};

} // namespace morse
