#include <iostream>

#include "nn-cpp/math/math"

int main() {
    nn_cpp::Matrix2D mat({{3, 3},
                          {2, 2}});
    std::cout << mat[0][0] << std::endl;
    return 0;
}