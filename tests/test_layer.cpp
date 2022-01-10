#include <cassert>
#include <iostream>

#include "nnwc/all"

void test_affine_layer_shape() {
    using namespace nnwc;
    Affine affine(100, 30);
    Matrix2D x(50, 100);
    Matrix2D y = affine.forward(x);
    assert(y.height() == 50);
    assert(y.width() == 30);
}

void test_affine_layer_calculation() {
    using namespace nnwc;
    Affine affine = Affine(Matrix2D({
        {1, 4},
        {2, 5},
        {3, 6},
    }));
    Matrix2D x({{1, 2, 3}});
    Matrix2D y = affine.forward(x);
    assert(y[0][0] == 1 * 1 + 2 * 2 + 3 * 3);
    assert(y[0][1] == 1 * 4 + 2 * 5 + 3 * 6);
}

int main() {
    test_affine_layer_shape();
    test_affine_layer_calculation();
    return 0;
}