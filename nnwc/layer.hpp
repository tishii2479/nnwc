#pragma once

#include "nnwc/matrix.hpp"
namespace nnwc {
struct Layer {
    virtual Matrix2D forward();
    virtual Matrix2D backward();
};

struct Affine : Layer {
    Matrix2D forward() override {
    }

    Matrix2D backward() override {
    }
};
};  // namespace nnwc