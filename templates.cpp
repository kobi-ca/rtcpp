//
// Created by kobi on 9/23/23.
//

template <typename T>
T add(const T& t1, const T& t2) {
    return t1 + t2;
}

int main(int, char *[]) {
    const auto r1 = add(1, 2);
    const auto r2 = add(1.2, 2.3);
}
