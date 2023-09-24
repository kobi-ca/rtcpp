//
// Created by kobi on 9/22/23.
//

#include <cstdint>

struct point {

    // start with taking a struct into a class.
    // members are public here, but should be private in
    // code iteration n+1
    std::uint8_t x_; // initialize to 0
    std::uint8_t y_; // initialize to 0
};

// Try comment inline and see

// inline is a must
/* inline */ void init(struct point *p,
          const std::uint8_t x,
          const std::uint8_t y) {
    p->x_ = x;
    p->y_ = y;
}

// inline is a must
/* inline */ std::uint16_t squared_euc_dist(struct point *p) {
    const std::uint16_t x2((std::uint16_t) (p->x_) * p->x_);
    const std::uint16_t y2((std::uint16_t) (p->y_) * p->y_);
    return x2 + y2;
}

int main(int, char*[]) {
    struct point p1;
    struct point p2;
    init(&p1, 0, 0);
    init(&p2, 10, 20);
    const auto d1 = squared_euc_dist(&p1);
    const auto d2 = squared_euc_dist(&p2);
    return d1 + d2;
}
