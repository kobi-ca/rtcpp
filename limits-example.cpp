//
// Created by kobi on 9/24/23.
//

#include <limits>
#include <cassert>

// how many digits? , sign not included
constexpr int num_int_dig = std::numeric_limits<int>::digits;
static_assert(num_int_dig == 31, "Unexpected number of digits");

unsigned int some_uint = 1000;
auto func() {
    assert(std::numeric_limits<int>::max() <= some_uint);
    auto casted = static_cast<int>(some_uint);
    return casted;
}
