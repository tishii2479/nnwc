#include <cassert>
#include <iostream>

#include "nn-cpp/math/math"

void test_matrix_calculation() {
    using namespace nn_cpp;
    // (5, 5)
    Matrix2D mat(5);
    assert(mat.height() == 5);
    assert(mat.width() == 5);
    mat[3][2] = 2;
    assert(mat[3][2] == 2);

    // (4, 3)
    mat = Matrix2D(4, 3);
    assert(mat.height() == 4);
    assert(mat.width() == 3);
    mat[2][1] = 3;
    assert(mat[2][1] == 3);

    // (3, 3)
    mat = Matrix2D(3);
    mat += 2;
    assert(mat[0][0] == 2);
    assert(mat[2][1] == 2);

    mat -= 3;
    assert(mat[0][0] == -1);
    assert(mat[1][2] == -1);

    mat *= -6;
    assert(mat[0][0] == 6);
    assert(mat[1][2] == 6);

    mat /= 3;
    assert(mat[0][0] == 2);
    assert(mat[1][2] == 2);

    Matrix2D l({{1, 2},
                {3, 4}});
    Matrix2D r({{2, 4},
                {3, 3}});
    mat = l;
    assert(mat[0][0] == 1);
    assert(mat[1][1] == 4);

    Matrix2D res = l * r;
    assert(res[0][0] == (1 * 2 + 2 * 3));
    assert(res[0][1] == (1 * 4 + 2 * 3));

    res = l + r;
    assert(res[0][0] == (1 + 2));
    assert(res[0][1] == (2 + 4));

    res = l - r;
    assert(res[0][0] == (1 - 2));
    assert(res[0][1] == (2 - 4));
}

int main() {
    test_matrix_calculation();

    std::cout << "Test passed!" << std::endl;
    return 0;
}