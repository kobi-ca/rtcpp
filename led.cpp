#include <cstdint>
#include <cstring>

// https://godbolt.org/z/h7PboMq1P
namespace rtcpp {

    class led final {
    public:
        using port_type = std::uint8_t;
        using bitval_type = std::uint8_t;

        explicit led(const port_type p, const bitval_type b) : p_{p}, b_{b} {
            // low level access to registers and memory.
            *reinterpret_cast<volatile bitval_type *>(p_) &= ~b_;
            const port_type  pdir = p_ - 1U;
            *reinterpret_cast<volatile bitval_type *>(pdir) |= b;
        }

        void toggle() const noexcept {
            *reinterpret_cast<volatile bitval_type *>(p_) ^= b_;
        }

    private:
        port_type p_{};
        bitval_type b_{};
    };
}

int main() {
    rtcpp::led led{0x25U, 1UL<<2UL};
    led.toggle();
    return 0;
}
