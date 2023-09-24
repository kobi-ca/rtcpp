//
// Created by kobi on 9/23/23.
//

struct S{};

namespace {
    S* s; // namespace scope, default initialized to nullptr.
}

void func(S *p) {
    if (p == nullptr) {
        // ...
    }
}
