#ifndef MYUNIQUE
#define MYUNIQUE

template <typename T>
class MyUnique {
private:
    T* p = nullptr;
public:
    explicit MyUnique(T* p) : p(p) {}
    ~MyUnique() { delete p; }

    MyUnique(const MyUnique&) = delete;
    MyUnique& operator=(const MyUnique&) = delete;

    MyUnique(MyUnique&& other) noexcept : p(other.p) {
        other.p = nullptr;
    }

    MyUnique& operator=(MyUnique&& other) noexcept {
        if (this != &other) {
            delete p;
            p = other.p;
            other.p = nullptr;
        }
        return *this;
    }

    T* get() const { return p; }
    T& operator*() const { return *p; }
    T* operator->() const { return p; }
};

template<class T, typename... Args>
MyUnique<T> Make_MyUnique(Args... args) {
    return MyUnique<T>(new T(args...));
}

#endif