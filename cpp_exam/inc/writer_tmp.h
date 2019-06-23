#ifndef WRITER_TMP_H
#define WRITER_TMP_H

#include <iostream>
#include <string>

template<class T>
using Writer = std::pair<T, std::string>;

template<class T>
Writer<T> identity(T x) {
    return Writer<T>(x, "");
}

template<class A, class B, class C>
std::function<Writer<C>(A)> compose(std::function<Writer<B>(A)> f, std::function<Writer<C>(B)> g) { 
    return [f, g](A x) {
        auto p1 = f(x);
        auto p2 = g(p1.first);
        return make_pair(p2.first, p1.second + p2.second);
    };
}

#endif
