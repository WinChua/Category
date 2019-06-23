#include "optional_tmp.h"
#include <iostream>
#include <math.h>

optional<double> safe_sqrt(double x) {
    if(x < 0) return optional<double>(sqrt(x));
    else return optional<double>();
}

optional<double> add_ont(double x) {
    return optional<double>(x + 1);
}
int optional_exam() {
    auto f = compose<double, double, double>(safe_sqrt, add_ont);
    f(-1);
    return 0;
}

int main() {
    optional_exam();
}

