#include "nn-cpp/math/math"
namespace nn_cpp {
struct Layer {
    virtual Matrix2D forward();
    virtual Matrix2D backward();
};
};  // namespace nn_cpp