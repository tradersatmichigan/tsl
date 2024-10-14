#include <cstddef>
#include <utility>

template <class T, size_t size>
class priority_queue {
  const T* arr;
  public:
  priority_queue(T* arr) : arr(arr) {
    for (size_t i = size / 2; i > 0; --i) {
      fix_down(i);
    }
  }

  // i is the ONE based index, not zero
  void fix_down(size_t i) {
    while (true) {
      size_t l = i << 1; 
      size_t r = l + 1;

      if (l > size) return;

      size_t candidate = (r <= size && arr[l - 1] < arr[r - 1]) ? r : l;

      if (arr[i - 1] < arr[candidate - 1]) {
        std::swap(arr[i - 1], arr[candidate - 1]);
        i = candidate;
      }
      else {
        return;
      }
    }
  }

  T& top() {
    return arr[0];
  }
};
