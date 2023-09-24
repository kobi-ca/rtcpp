//
// Created by kobi on 9/24/23.
//

#include <cassert>
#include <algorithm>
#include <numeric>
#include <array>
#include <cstdint>

namespace {
    constexpr auto NUM = 10U;
    std::array<std::uint32_t, NUM> arr;
    auto func() {
        for (auto i = 0ULL; i < arr.size(); ++i) {
            arr[i] = 17;
        }
        auto sum = 0ULL;
        for (auto i = 0ULL; i < arr.size(); ++i) {
            sum += arr[i];
        }
        return sum;
    }
}

int main() {
    return func();
}
