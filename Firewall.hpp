#ifndef FIREWALL
#define FIREWALL

#include <string>

class Firewall {
private:
	std::string name;
	unsigned short securityClass;
public:
	Firewall(std::string name, unsigned short securityClass) : name(name), securityClass(securityClass) {};
	void print();
};

#endif