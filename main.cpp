#include <iostream>

#include "nnwc/all"

int main() {
    nnwc::Matrix2D mat({{3, 3},
                        {2, 2}});
    std::cout << mat[0][0] << std::endl;
    return 0;
}