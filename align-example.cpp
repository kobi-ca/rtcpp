//
// Created by kobi on 9/30/23.
//

#include <cstdint>
#include <memory> // addressof
#include <cassert>

auto v1 = alignof(short); // 2? 4?
auto v2 = alignof(int); // 2? 4?
auto v3 = alignof(long); // 4? 8?
auto v4 = alignof(long long); // 8?

// Align to 128 bytes
struct alignas(128) some_aligned final {
    std::uint32_t v1{};
    std::uint32_t v2{};
};

struct some_not_aligned final {
    std::uint32_t v1{};
    std::uint32_t v2{};
};

int main() {

    some_aligned aligned;
    some_not_aligned not_aligned;
    const auto is_aligned = reinterpret_cast<std::uintptr_t >(std::addressof(aligned)) % 128 == 0;
    const auto is_not_aligned = reinterpret_cast<std::uintptr_t >(std::addressof(not_aligned)) % 128 !=
                                0; // ? might be accidentally aligned
    assert(is_aligned);
    assert(is_not_aligned);
};
