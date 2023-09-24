//
// Created by kobi on 9/23/23.
//

#include <type_traits>
#include <string>

namespace simple {

    template<typename T>
    T add(const T &t1, const T &t2) {
        return t1 + t2;
    }
}

namespace with_traits {
    template<typename T>
    T add(const T &t1, const T &t2) {
        static_assert(std::is_integral_v<T>, "Must be integral");
        return t1 + t2;
    }
}

int main(int, char *[]) {
    const auto r1 = simple::add(1, 2);
    const auto r2 = simple::add(1.2, 2.3);
    using namespace std::string_literals;
    const auto r3 = simple::add("hello"s, "world"s);

    // const auto r4 = with_traits::add("hello", "world");
}
