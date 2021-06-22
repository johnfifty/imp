#pragma once

#include <utility>

namespace imp {

template <typename T>
class unique_ptr
{
  T* ptr = nullptr;

public:
  unique_ptr() noexcept = default;
  explicit unique_ptr(T* arg) noexcept
    : ptr{ arg }
  {}

  unique_ptr(unique_ptr const&) = delete;
  unique_ptr& operator=(unique_ptr const&) = delete;

  unique_ptr(unique_ptr&& arg) noexcept
    : ptr{ std::move(arg.ptr) }
  {
    arg.ptr = nullptr;
  }
  unique_ptr& operator=(unique_ptr&& arg) noexcept
  {
    delete ptr;
    ptr = std::move(arg.ptr);
    arg.ptr = nullptr;
    return *this;
  }

  unique_ptr(std::nullptr_t) noexcept {}
  unique_ptr& operator=(std::nullptr_t) noexcept
  {
    delete ptr;
    ptr = nullptr;
    return *this;
  }

  ~unique_ptr() { delete ptr; }

  [[nodiscard]] T* get() const noexcept { return ptr; }
  T& operator*() const { return *ptr; }

  explicit operator bool() const noexcept { return ptr != nullptr; }
};

template <typename T>
bool
operator==(unique_ptr<T> const& x, std::nullptr_t) noexcept
{
  return x.get() == nullptr;
}

} // namespace imp
