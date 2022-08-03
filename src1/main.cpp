#include <list>
#include <iostream>
#include "sequence_container.h"

//using namespace std;

int main() {
    s21::list<char> my;
    my.insert(my.begin(), 'a');
    my.insert(my.begin(), 'b');
    my.insert(my.begin(), 'd');
    my.insert(my.begin(), 'c');
    my.insert(my.end(), 'e');
    auto my_iter = my.begin();
    ++my_iter;
    ++my_iter;
    ++my_iter;
    ++my_iter;
    my.insert(my_iter, 'X');
    my.clear();
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


// i've got 8 hours
// ALL containers finish goal.
// this hour (1:20 pm - 2:30 pm) - finish off list. 