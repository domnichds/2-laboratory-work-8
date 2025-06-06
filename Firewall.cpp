#include "Firewall.hpp"
#include <string>
#include <iostream>

void Firewall::print() {
	std::cout << "Name: " << name << " | Security level: " << securityClass << std::endl;
}