#include <cassert>
#include <iostream>

#include "nnwc/all"

void test_matrix_initialization() {
    using namespace nnwc;
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
}

void test_matrix_calculation() {
    using namespace nnwc;
    // (3, 3)
    Matrix2D mat = Matrix2D(3);
    mat += 2;
    assert(mat == Val2D({{2, 2, 2}, {2, 2, 2}, {2, 2, 2}}));

    mat -= 3;
    assert(mat == Val2D({{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}}));

    mat *= -6;
    assert(mat == Val2D({{6, 6, 6}, {6, 6, 6}, {6, 6, 6}}));

    mat /= 3;
    assert(mat == Val2D({{2, 2, 2}, {2, 2, 2}, {2, 2, 2}}));

    Matrix2D l({{1, 2},
                {3, 4}});
    Matrix2D r({{2, 4},
                {3, 3}});
    mat = l;
    assert(mat == l);

    Matrix2D res = l * r;
    Matrix2D expected({{1 * 2 + 2 * 3, 1 * 4 + 2 * 3},
                       {3 * 2 + 4 * 3, 3 * 4 + 4 * 3}});
    assert(res == expected);

    res = l + r;
    expected = Val2D({{1 + 2, 2 + 4},
                      {3 + 3, 4 + 3}});
    assert(res == expected);

    res = l - r;
    expected = Val2D({{1 - 2, 2 - 4},
                      {3 - 3, 4 - 3}});
    assert(res == expected);
}

int main() {
    test_matrix_initialization();
    test_matrix_calculation();
    return 0;
}