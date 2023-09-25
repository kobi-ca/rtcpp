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
        std::fill(arr.begin(), arr.end(), 17);
        // {17, ...}
        return std::accumulate(arr.cbegin(), arr.cend(), 0U);
    }
}

int main() {
    return func();
}
