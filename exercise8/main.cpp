#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<double> v1 = {-9.3, -7.4, -3.8, -0.4, 1.3, 3.9, 5.4, 8.2};
    sort(v1.begin(), v1.end(), [](int a, int b){return abs(a) < abs(b);});
    for (auto i: v1) {
        std::cout << i << ", ";
    }
    return 0;
}