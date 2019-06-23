#include "writer_tmp.h"
#include <vector>
#include <utility>
#include <iostream>


std::vector<std::string> words(std::string x) {
    return std::vector<std::string>{"a", "b"};
}

Writer<std::string> toUpper(std::string x) {
    return std::make_pair(x, "ToUpper");
}

Writer<std::vector<std::string>> toWord(std::string x) {
    return std::make_pair(words(x), "ToWord");
}

Writer<std::vector<std::string>> process(std::string x) {
    return compose<std::string, std::string, std::vector<std::string>>(toUpper, toWord)(x);
}

int writer_exam() {
    std::string name("WinChua");
    for(auto i : process(name).first) {
        std::cout << i << std::endl;
    }
}

int main() {
    writer_exam();
    return 0;
}
