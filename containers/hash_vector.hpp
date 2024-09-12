#ifndef HASH_VECTOR_HPP
#define HASH_VECTOR_HPP

#include <vector>

template <typename T>
class hash_vector {
  T hash{};
  std::vector<T> vec;

 public:
  auto size() -> size_t { return vec.size(); }

  auto get_hash() -> T { return this->hash; }

  auto push_back(const T& x) -> void {
    hash ^= x;
    vec.push_back(x);
  }

  auto pop_back() -> void {
    hash ^= vec.back();
    vec.pop_back();
  }

  auto at(size_t i) -> const T& { return vec.at(i); }

  auto set(size_t i, const T& x) {
    hash ^= vec[i];
    hash ^= x;
    vec[i] = x;
  }

  auto operator==(const hash_vector<T>& other) -> bool {
    if (this->hash != other.hash) {
      return false;
    }
    return this->vec == other.vec;
  }
};

#endif  // HASH_VECTOR_HPP
