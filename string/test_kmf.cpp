#include "kmf.h"
#include <iostream>
#include <ostream>
#include <vector>

using std::vector;

vector<size_t> find_all(std::string &s, std::string &p) {

  int i = s.find(p);

  vector<size_t> res;
  while (i < std::string::npos) {
    res.push_back(i);
    i = s.find(p, i + 1);
  }

  return res;
}

int main (int argc, char *argv[]) {
  Kmp kmp;

  std::string text1 = "abcxabcdabxabcdabcdabcy";
  std::string pattern1 = "abcdabcy";
  assert(kmp.search(text1, pattern1) == find_all(text1, pattern1));

  std::string text2 = "ababcabcabababd";
  std::string pattern2 = "ababd";
  assert(kmp.search(text2, pattern2) == find_all(text2, pattern2));

  std::string text3 = "aaaaa";
  std::string pattern3 = "aaa";
  assert(kmp.search(text3, pattern3) == find_all(text3, pattern3));

  std::string text4 = "abxabcabcaby";
  std::string pattern4 = "abcaby";
  assert(kmp.search(text4, pattern4) == find_all(text4, pattern4));

  std::string text5 = "abc";
  std::string pattern5 = "abc";
  assert(kmp.search(text5, pattern5) == find_all(text5, pattern5));

  std::string text6 = "abcdef";
  std::string pattern6 = "gh";
  assert(kmp.search(text6, pattern6) == find_all(text6, pattern6));

  std::string text7 = "abxabcabcabyabxabcabcabyabxabcabcaby";
  std::string pattern7 = "abcaby";
  assert(kmp.search(text7, pattern7) == find_all(text7, pattern7)); 

  return 0;
}
