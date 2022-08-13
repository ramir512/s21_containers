#include <list>
#include <iostream>
#include "sequence_container.h"

//using namespace std;

int main() {

    s21::list<int> my({100, 12, 1231, 23, -134, 0, 33, 2, 7, 6, 5, 5, 5, 5, 4, 3, 2, 1});
    my.sort();
    std::cout << "my here:";
    for (auto i:my) {
        
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


// 17:00 - 21:00
// 
//