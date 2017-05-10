#include <thread>
#include <iostream>
#include <vector>
#include "parallel_protector.h"

int a, b, c, d, e;

void loop() {
    for (size_t i = 0; i < 100000; i++) {
        a = 1*e;
        b = 2*a;
        c = 3*b;
        d = 4*c;
        e = 5*d;
    }
}

int main() {
    std::vector<std::thread> v;
    for (size_t i = 0; i < 1000; i++) {
        v.emplace_back(loop);
    }
    for (auto& i : v) {
        i.join();
    }
}
