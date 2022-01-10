#pragma once

#include "nnwc/matrix.hpp"
namespace nnwc {
class Layer {
   public:
    virtual ~Layer() {}
    virtual Matrix2D forward(Matrix2D x) = 0;
    virtual Matrix2D backward(Matrix2D d_out) = 0;
};

class Affine : public Layer {
   private:
    Matrix2D w;

   public:
    Affine(int in_dim, int out_dim) {
        // TODO: Init Random
        w = Matrix2D(in_dim, out_dim);
    }
    Affine(Matrix2D _w) : w(_w) {}

    Matrix2D forward(Matrix2D x) override {
        assert(x.width() == w.height());
        Matrix2D y = x * w;
        return y;
    }

    Matrix2D backward(Matrix2D d_out) override {
        return w;
    }
};
};  // namespace nnwc