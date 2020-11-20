#include <iostream>
#include "List.h"
int main(int, char**) {
    std::cout << "Hello, world!\n";
    List<int> list1;
    list1.remove(6);
    list1.insertStart(1);
    list1.remove(1);
    list1.insertStart(1);
    list1.insertStart(2);
    list1.insertStart(3);
    list1.remove(2);
    list1.remove(1);
}
