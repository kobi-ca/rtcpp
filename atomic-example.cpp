//
// Created by kobi on 9/24/23.
//

#include <atomic>

namespace {
    volatile std::atomic<std::uint32_t> system_tick;
}

std::uint32_t get() {
    // 32-bit consistency on 8-bit CPU
    return std::atomic_load(&system_tick);
}
