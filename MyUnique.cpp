#include "MyUnique.hpp"

template <class T>
MyUnique<T>::MyUnique(T* ptr) : p(ptr) {};

template <class T>
MyUnique<T>::~MyUnique() {
	delete p;
}

template <class T>
MyUnique<T>::MyUnique(MyUnique&& other) noexcept : p(other.p) {
	other.p = nullptr;
}

template <class T>
MyUnique<T>& MyUnique<T>::operator=(MyUnique&& other) noexcept {
	if (this != &other) {
		delete p;
		p = other.p;
		other.p = nullptr;
	}
	return *this;
}

template <class T>
T& MyUnique<T>::operator*() const {
	return *p;
}

template <class T>
T* MyUnique<T>::operator->() const {
	return p;
}