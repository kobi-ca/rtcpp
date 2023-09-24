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
    void func() {
        std::fill(arr.begin(), arr.end(), 17);
        // {17, ...}
        const auto sum = std::accumulate(arr.cbegin(), arr.cend(), 0U);
        assert(sum == 17 * arr.size());
        const auto is_zero([](const auto v){ return v == 0; });
        const auto res = std::none_of(arr.cbegin(), arr.cend(), is_zero);
        assert(res);
    }
}

int main() {
    func();
}
