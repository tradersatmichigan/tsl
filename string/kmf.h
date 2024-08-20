#include <exception>
#include <numeric>
#include <stdexcept>
#include <string>
#include <system_error>
#include <vector>
class Kmp {
public:
  std::vector<size_t> search(const std::string& text, const std::string& pattern) {
    if (!text.size() || !pattern.size()) throw std::invalid_argument("Pattern or text to search is empty");

    const auto table = generateTable(pattern);

    std::vector<size_t> result;

    int text_p = 0;
    int pattern_p = 0;

    while (text_p < text.size()) {
      if (pattern[pattern_p] == text[text_p]) {
        ++pattern_p;
        ++text_p;
      }
      
      if (pattern_p == pattern.size()) {
        result.push_back(text_p - pattern_p);
        pattern_p = table[pattern_p - 1];
      }
      else if (text_p < text.size() && pattern[pattern_p] != text[text_p]) {
        if (pattern_p) {
          pattern_p = table[pattern_p - 1];
        }
        else {
          ++text_p;
        }
      }
    }

    return result;
  };
private:
  std::vector<size_t> generateTable(const std::string& pattern) {
    std::vector<size_t> table(pattern.size(), 0);

    int len = 0;
    for (int i = 1; i < pattern.size(); ++i) {
      if (pattern[i] == pattern[len]) {
        table[i] = ++len;
      }
      else if (len) {
        len = table[len - 1]; 
        --i;
      }
    }
    return std::move(table);
  }
};
