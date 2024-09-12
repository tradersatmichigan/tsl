#include <chrono>
#include <iostream>
#include <random>

#include "hash_vector.hpp"

constexpr int VEC_SIZE = 100'000'000;

auto main() -> int {
  std::default_random_engine e1(42);
  std::default_random_engine e2(42);
  std::default_random_engine e3(42);
  std::uniform_int_distribution<int> id_generator(1, 1'000'000);

  hash_vector<int> vec1;
  for (size_t i = 0; i < VEC_SIZE; ++i) {
    vec1.push_back(id_generator(e1));
  }
  hash_vector<int> vec2;
  for (size_t i = 0; i < VEC_SIZE; ++i) {
    vec2.push_back(id_generator(e1));
  }

  std::cout << "vec1 hash: " << vec1.get_hash() << std::endl;
  std::cout << "vec2 hash: " << vec2.get_hash() << std::endl;

  auto t_start = std::chrono::high_resolution_clock::now();
  std::cout << (vec1 == vec2) << std::endl;
  auto t_end = std::chrono::high_resolution_clock::now();
  std::cout << "Checking unequal vectors took: "
            << std::chrono::duration<double, std::milli>(t_end - t_start)
            << std::endl;

  hash_vector<int> vec3;
  for (size_t i = 0; i < VEC_SIZE; ++i) {
    vec3.push_back(id_generator(e2));
  }
  hash_vector<int> vec4;
  for (size_t i = 0; i < VEC_SIZE; ++i) {
    vec4.push_back(id_generator(e3));
  }

  std::cout << "vec3 hash: " << vec3.get_hash() << std::endl;
  std::cout << "vec4 hash: " << vec4.get_hash() << std::endl;

  t_start = std::chrono::high_resolution_clock::now();
  std::cout << (vec3 == vec4) << std::endl;
  t_end = std::chrono::high_resolution_clock::now();
  std::cout << "Checking equal vectors took: "
            << std::chrono::duration<double, std::milli>(t_end - t_start)
            << std::endl;
}
