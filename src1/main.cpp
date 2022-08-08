#include <list>
#include <iostream>
#include "sequence_container.h"

//using namespace std;

int main() {
    

    s21::list<int> nmy({1, 33, 150, 151, 169, 1000, 1001});
    s21::list<int> my({5, 6, 7, 8, 152, 153, 1000, 1001, 1002});
    std::cout << "starting" << std::endl;
    auto myi = nmy.begin();
    myi++;
    myi++;
    nmy.splice(nmy.begin(), my);

    std::list<int> original_1({1, 2, 3});
    std::list<int> original_2({4, 5, 6});
    original_1.splice(original_1.begin(), original_2);


    std::cout << "nmy here:";
    for (auto i:nmy) {
        std::cout << i << " ";
    }
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