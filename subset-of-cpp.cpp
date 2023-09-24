//
// Created by kobi on 9/22/23.
//

// declare variable close to where it is being used
bool getStatus();

namespace wrong {
    void do_something1() {
        bool result;

        // ...

        result = getStatus();
    }
}

namespace right {
    void do_something1() {
        auto result = getStatus();
        // ...
    }
}

// know your integral type
#include <cstdint>
// exactly 16 bit signed.
constexpr std::int16_t v16 = INT16_C(0x7FFF);

// at last 32 bit
constexpr std::uint_least32_t  v32 = UINT32_C(1'123'123'123);

// Macros in cstdint will be using literal suffix and much more
// maintainable compared to bare U, L, UL, LL, ULL etc...

// imagine
#include <cstdint>

// U means unsigned int, non-portable if int is 16, or even 8
// so unsigned int (U) us not large enough to hold 10M.
constexpr std::uint32_t num_664999 = 10'006'721U;

// a Better approach - UINT32_C macto which is portable
constexpr std::uint32_t num664999 = UINT32_C(10'006'721);
// macro UINT32_C will handle 0...4,294,967,295

// bool type for ternary operator
bool valid();
bool success();
const bool result = valid() && success();

// using namespaces
namespace outer {
    void f(); // in outer
    namespace inner1 {
        void g(); // in inner1
    }
    namespace inner2 {
        void f();
        void g();
    }
}

// using
void func() {
    outer::f();
    outer::inner1::g();
    using outer::inner2::f;
    f(); // of inner2
}

namespace outer::inner1 {
    void more_func();
}

namespace {
    void like_static_func(); // like static
    static int like_static_var;
}
