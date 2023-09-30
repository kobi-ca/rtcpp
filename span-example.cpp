//
// Created by kobi on 9/30/23.
//

#include <span>
#include <cstdint>
#include <numeric>
#include <cassert>

void op_on_buf(std::span<std::byte> b) {
    for(auto& v : b) {
        v = UINT8_C(std::byte{0});
    }
}

int main(int, char*[]) {
    constexpr auto LEN = 64ULL;
    std::byte buf[LEN] = {std::byte{1}, std::byte{2}, std::byte{3}};
    op_on_buf(buf);
    assert(buf[0] == std::byte{0});
}
