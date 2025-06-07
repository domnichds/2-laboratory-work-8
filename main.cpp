#include "Firewall.hpp"
#include "MyUnique.hpp"
#include <iostream>
#include <memory>

int main() {
    auto ptr1 = Make_MyUnique<Firewall>("Test", 4);
    ptr1->print();

    MyUnique<int> ptr2(new int(100));
    std::cout << "Int value: " << *ptr2 << "\n";

    MyUnique<int> ptr3 = std::move(ptr2);
    if (!ptr2.get()) {
        std::cout << "ptr2 is now empty\n";
    }
    std::cout << "ptr3 value: " << *ptr3 << "\n";
}