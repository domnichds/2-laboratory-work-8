#ifndef MYSHARED
#define MYSHARED

#include <cstddef>

template <typename T>
class MyShared {
private:
    T* p = nullptr;
    std::size_t* count = nullptr;
public:
    explicit MyShared(T* ptr) : p(ptr), count(new std::size_t(1)) {}

    MyShared(const MyShared& other) : p(other.p), count(other.count) {
        if (count) ++(*count);
    }

    MyShared(MyShared&& other) noexcept : p(other.p), count(other.count) {
        other.p = nullptr;
        other.count = nullptr;
    }

    MyShared& operator=(const MyShared& other) {
        if (this != &other) {
            release();
            p = other.p;
            count = other.count;
            if (count) ++(*count);
        }
        return *this;
    }

    MyShared& operator=(MyShared&& other) noexcept {
        if (this != &other) {
            release();
            p = other.p;
            count = other.count;
            other.p = nullptr;
            other.count = nullptr;
        }
        return *this;
    }

    ~MyShared() {
        release();
    }

    void release() {
        if (count) {
            --(*count);
            if (*count == 0) {
                delete p;
                delete count;
            }
            p = nullptr;
            count = nullptr;
        }
    }

    T* get() const { return p; }
    T& operator*() const { return *p; }
    T* operator->() const { return p; }
    std::size_t use_count() const { return count ? *count : 0; }
};

template<class T, typename... Args>
MyShared<T> Make_MyShared(Args&&... args) {
    return MyShared<T>(new T(std::forward<Args>(args)...));
}

#endif