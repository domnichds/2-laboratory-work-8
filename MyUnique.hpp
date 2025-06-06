#ifndef MYUNIQUE
#define MYUNIQUE

template <typename T>
class MyUnique {
private:
	T* p = nullptr;
public:
	explicit MyUnique(T* p);
	~MyUnique();

	// Запрет копирования
	MyUnique(const MyUnique&) = delete;
	MyUnique& operator=(const MyUnique&) = delete;

	// Перемещение
	MyUnique(MyUnique&& other) noexcept;
	MyUnique& operator=(MyUnique&& other) noexcept;

	// Методы доступа
	T* get() const;
	T& operator*() const;
	T* operator->() const;
};

template<class T, typename... Args>
MyUnique<T> Make_MyUnique(Args... args) {
	return MyUnique<T>(new T(args...));
}
#endif