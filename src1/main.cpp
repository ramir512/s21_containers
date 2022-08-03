#include <list>
#include <iostream>
#include "sequence_container.h"

//using namespace std;

int main() {
    

    s21::list<int> nmy({1, 2, 3, 4});

    s21::list<int> my(nmy);
    nmy.pop_back();
    for (auto i:my) {
        std::cout << i << " ";
    }
    // for (auto i:nmy) {
    //     std::cout << i << " ";
    // }

    // s21::list<int> b;
    // b.insert(b.begin(), 1);
    // b.insert(b.end(), 2);
    // b.insert(b.end(), 3);
    // b.insert(b.begin(), 0);
    // for (auto i:b) {
    //     std::cout << i << std::endl;
    // }
}


// 17:00 - 21:00
// 
//