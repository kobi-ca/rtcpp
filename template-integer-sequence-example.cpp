//
// Created by kobi on 10/1/23.
//

// Sum example

#include <utility>

template <typename INT_TYPE,
        const INT_TYPE ... I>
constexpr INT_TYPE sequence_accumulate(std::integer_sequence<INT_TYPE, I ...>) {
    INT_TYPE sum{};
    for (const INT_TYPE i : {I ...}) {
        sum += i;
    }
    return sum;
}

int main(int, char*[]) {
    constexpr std::integer_sequence<unsigned int, 1U, 3U, 5U, 7U> int_seq;
    constexpr auto sum = sequence_accumulate(int_seq);
    static_assert(16U == sum);
}
