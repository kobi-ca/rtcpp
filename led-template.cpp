#include <cstdint>
#include <cstring>

namespace rtcpp {

    // different arch? no prob
    // PT - port type
    // BVT - bit val type
    template<typename PT,
            typename BVT,
            const PT port,
            const BVT bval>
    class led final {
    public:

        explicit led() {
            // low level access to registers and memory.
            *reinterpret_cast<volatile BVT *>(port) &= ~bval;
            *reinterpret_cast<volatile BVT *>(pdir) |= bval;
        }

        void toggle() const noexcept {
            *reinterpret_cast<volatile BVT *>(port) ^= bval;
        }

    private:
        static constexpr PT pdir = port - 1U;
    };
}
int main() {
    rtcpp::led<uint8_t, uint8_t, 0x25U, 1UL<<2UL> led;
    led.toggle();
    return 0;
}
