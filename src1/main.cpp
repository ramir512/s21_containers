#include <list>
#include <iostream>
#include "sequence_container.h"


int main() {
    std::list<int> a(4);
    for (auto i:a) {
       a.erase(a.begin());
       std::cout << i << "lol" << std::endl;
    }

    s21::list<int> b;
    b.insert(b.begin(), 1);
    b.insert(b.end(), 2);
    b.insert(b.end(), 3);
    b.insert(b.begin(), 0);
    for (auto i:b) {
        std::cout << i << std::endl;
    }
}