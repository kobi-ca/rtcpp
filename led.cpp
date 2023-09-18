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
            //*reinterpret_cast<volatile bitval_type*>(&p_) &= static_cast<bitval_type>(~b_);
            *reinterpret_cast<volatile bitval_type *>(&p_) &= ~b_;
            // vs
//        bitval_type btmp{p};
//        btmp &= ~b_;
//        p_ = btmp;
//
//        // vs
//        p_ &= ~b_;

            // more here as needed
        }

        void toggle() noexcept {
            *reinterpret_cast<volatile bitval_type *>(&p_) ^= b_;
//        // vs
//        bitval_type btmp{p_};
//        btmp &= ~b_;
//        p_ = btmp;
//
//        // vs
//        p_ ^= b_;
        }

    private:
        port_type p_{};
        bitval_type b_{};
    };
}

int main() {
    led led{0x25U, 1UL<<2UL};
    led.toggle();
    return 0;
}
