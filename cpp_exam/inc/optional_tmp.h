#ifndef OPTIONAL_TMP_H
#define OPTIONAL_TMP_H

#include <utility>
#include <iostream>

template<class T>
class optional {
    bool _isValid;
    T _value;
    public:
    optional(): _isValid(false){}
    optional(T v):_value(v), _isValid(true){}
    bool isValid() const { return _isValid; }
    T value() const { return _value; }
};

template<class T>
optional<T> identity(T x) {
    return optional<T>(x);
}

template<class A, class B, class C>
std::function<optional<C>(A)> compose(std::function<optional<B>(A)> f, std::function<optional<C>(B)> g) {
    return [f, g](A x) {
        auto o1 = f(x);
        if (!o1.isValid()) {
            return optional<C>();
        }
        else {
            return g(o1.value());
        }
    };
}

#endif
