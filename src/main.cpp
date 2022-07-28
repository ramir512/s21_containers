#include <list>
#include <iostream>

using namespace std;
int main() {
    list<int> a(4);
    for (int i:a) {
       cout << i << "lol" << endl;
    }
}