//
// Created by kobi on 9/23/23.
//

constexpr unsigned int version = 17U;
constexpr char hello1[] = "Hello world";
constexpr const char * const hello2 = "Hello world";

#include <array>

constexpr auto get2x(std::array<int, 3U> arr) {
    return arr.size() * 2;
}

struct S {
    static constexpr auto sz = get2x(std::array{1, 2, 3});
};
