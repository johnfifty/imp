#pragma once

#include <iostream>

namespace imp {

template <typename T>
class unique_ptr
{
  T* ptr = nullptr;

public:
  unique_ptr() = default;
  unique_ptr(std::nullptr_t) noexcept {}
  unique_ptr& operator=(std::nullptr_t) noexcept
  {
    ptr = nullptr;
    return *this;
  }

  explicit unique_ptr(T* ptr_) noexcept
    : ptr{ ptr_ }
  {
    std::cout << "copy\n";
  }

  unique_ptr(unique_ptr const& a) = delete;
  unique_ptr& operator=(unique_ptr const& a) = delete;

  unique_ptr(unique_ptr&& second) noexcept
  {
    if (ptr != nullptr) {
      delete ptr;
    }
    ptr = second.ptr;
    second = nullptr;
    std::cout << "move constructor\n";
  }

  ~unique_ptr()
  {
    std::cout << "destruct\n";
    delete ptr;
  }

  T* get() const noexcept { return ptr; }

  T& operator*() const { return *ptr; }
};

template <typename T>
bool
operator==(unique_ptr<T> const& x, std::nullptr_t) noexcept
{
  return x.get() == nullptr;
}

} // namespace imp
