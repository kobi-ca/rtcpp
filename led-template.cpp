#include <cstdint>
#include <cstring>

namespace rtcpp {

// different arch? no prob
    template<typename PT = std::uint8_t, typename BVT = std::uint8_t>
    class led final {
    public:

        explicit led(const PT p, const BVT b) : p_{p}, b_{b} {
            // low level access to registers and memory.
            //*reinterpret_cast<volatile bitval_type*>(&p_) &= static_cast<bitval_type>(~b_);
            *reinterpret_cast<volatile BVT *>(&p_) &= ~b_;
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
        PT p_{};
        BVT b_{};
    };
}
int main() {
    led led{0x25U, 1UL<<2UL};
    led.toggle();
    return 0;
}
