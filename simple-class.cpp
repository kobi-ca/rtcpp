//
// Created by kobi on 9/22/23.
//

#include <cstdint>

class point final {
public:
    // start with taking a struct into a class.
    // members are public here, but should be private in
    // code iteration n+1
    std::uint8_t x_{}; // initialize to 0
    std::uint8_t y_{}; // initialize to 0

    // explicit to prevent accidental conversion
    explicit point(const std::uint8_t x = UINT8_C(0),
                   const std::uint8_t y = UINT8_C(0)) : x_{x}, y_{y} {}

    [[nodiscard]]
    // originally was std::uint16_t, but this is ... int
    auto squared_euc_dist() const noexcept {
        const std::uint16_t x2(static_cast<std::uint16_t>(x_) * x_);
        const std::uint16_t y2(static_cast<std::uint16_t>(y_) * y_);
        return x2 + y2;
    }
};

int main(int, char*[]) {
    const point p1;
    const point p2 {UINT8_C(10), UINT8_C(20)};
    const auto d1 = p1.squared_euc_dist();
    const auto d2 = p2.squared_euc_dist();
    return d1 + d2;
}
