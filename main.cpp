#include "Firewall.hpp"
#include "MyUnique.hpp"
#include "MyShared.hpp"
#include <iostream>

int main() {
    std::cout << "MyUnique\n";
    auto uniquePtr1 = Make_MyUnique<Firewall>("UniqueFirewall", 5);
    uniquePtr1->print();

    MyUnique<int> uniquePtr2(new int(123));
    std::cout << "Unique int value: " << *uniquePtr2 << "\n";

    MyUnique<int> uniquePtr3 = std::move(uniquePtr2);
    if (!uniquePtr2.get()) std::cout << "uniquePtr2 is now empty after move\n";
    std::cout << "uniquePtr3 value: " << *uniquePtr3 << "\n";

    std::cout << "MyShared\n";
    auto sharedPtr1 = Make_MyShared<Firewall>("SharedFirewall", 2);
    std::cout << "sharedPtr1 use_count: " << sharedPtr1.use_count() << "\n";
    sharedPtr1->print();

    auto sharedPtr2 = sharedPtr1;
    std::cout << "sharedPtr2 (copy) use_count: " << sharedPtr2.use_count() << "\n";
    sharedPtr2->print();

    auto sharedPtr3 = std::move(sharedPtr2);
    std::cout << "sharedPtr3 (move) use_count: " << sharedPtr3.use_count() << "\n";
    if (!sharedPtr2.get()) std::cout << "sharedPtr2 is now empty after move\n";
    sharedPtr3->print();

    std::cout << "sharedPtr1 use_count after scope: " << sharedPtr1.use_count() << "\n";

    return 0;
}