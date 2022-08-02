#include <list>
#include <iostream>
#include "sequence_container.h"

//using namespace std;

int main() {
    s21::list<int> a;
    a.insert(a.begin(), 1);
    a.insert(a.begin(), 2);
    a.insert(a.begin(), 3);
    std::cout << "try 2" << std::endl;

    for (auto i:a) {
        std::cout << i << " ";
    }
    

    // s21::list<int> b;
    // b.insert(b.begin(), 1);
    // b.insert(b.end(), 2);
    // b.insert(b.end(), 3);
    // b.insert(b.begin(), 0);
    // for (auto i:b) {
    //     std::cout << i << std::endl;
    // }
}