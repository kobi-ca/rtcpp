//
// Created by kobi on 9/24/23.
//

#include <array>

constexpr auto NUM = 10U;
void func(std::array<int, NUM> in); // by value, no decay
void func(const std::array<int, NUM>& in); // by reference
std::array<int, NUM> func(); // return by value, copy semantic
// C++20 std::to_array
const auto arr = std::to_array(1, 2, 3, 4);

#include <experimental/array>
const auto mkarry = std::experimental::make_array(1, 2, 3, 4);
constexpr auto arr = std::array{1, 2, 3, 4};
