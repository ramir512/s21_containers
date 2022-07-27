#include <list>
#include <iostream>
int Max(int x, int y) {
   return (x > y)? x : y;
}
using namespace std;
inline int counter = 8;
int main() {
cout << "Max (20,10): " << Max(20,10) << endl;
   cout << "Max (0,200): " << Max(0,200) << endl;
   cout << "Max (100,1010): " << Max(100,1010) << endl;
   extern int counter;
   counter++;
   cout << endl << counter;
   counter++;
   cout << endl << counter;
}