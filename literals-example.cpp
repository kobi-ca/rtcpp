//
// Created by kobi on 9/24/23.
//

#include <cstdint>

// Binary literals
constexpr std::uint8_t one = UINT8_C(0b1);
constexpr std::uint8_t seven = UINT8_C(0b0000'0111);

// from metric system to imperial
inline constexpr float
operator"" _inch(long double inches) {
    return static_cast<float>(inches * 0.0254L);
}

inline constexpr float
operator"" _foot(long double feet) {
    return static_cast<float>(feet * 0.294L);
}

inline constexpr float
operator"" _yard(long double yards) {
    return static_cast<float>(yards * 0.9144L);
}

struct Foo final {
    unsigned long long int value_{};
};

inline constexpr auto
operator"" _foo( unsigned long long int v) {
    return Foo{v};
}

int main(int, char*[]) {
    constexpr auto one_foot = 12.0_inch; // 0.308m
    constexpr auto some_height = 7.0_foot; // 2.058m
    constexpr auto field = 100.0_yard; // 91.44m

    const auto myfoo = 100_foo;
    return myfoo.value_;
}
