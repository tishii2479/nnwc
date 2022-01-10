#pragma once

#include <cassert>
#include <iostream>
#include <vector>

namespace nnwc {
struct Matrix2D {
    std::vector<std::vector<float>> val;

    Matrix2D() {}
    Matrix2D(int n) : Matrix2D(n, n) {}
    Matrix2D(int h, int w) {
        val.resize(h);
        for (int i = 0; i < h; i++) val[i].resize(w);
    }
    Matrix2D(std::vector<std::vector<float>> v) : val(v) {}

    int height() const {
        return (val.size());
    }

    int width() const {
        return (val[0].size());
    }

    Matrix2D &operator+=(Matrix2D &rhs) {
        assert((*this).width() == rhs.width() && (*this).height() == rhs.height());
        for (int i = 0; i < (*this).height(); i++)
            for (int j = 0; j < rhs.width(); j++)
                (*this)[i][j] += rhs[i][j];
        return *this;
    }
    Matrix2D &operator-=(Matrix2D &rhs) {
        assert((*this).width() == rhs.width() && (*this).height() == rhs.height());
        for (int i = 0; i < (*this).height(); i++)
            for (int j = 0; j < rhs.width(); j++)
                (*this)[i][j] -= rhs[i][j];
        return *this;
    }
    Matrix2D &operator*=(Matrix2D &rhs) {
        assert((*this).width() == rhs.height());
        std::vector<std::vector<float>> ret((*this).height(), std::vector<float>(rhs.width()));
        for (int i = 0; i < (*this).height(); i++)
            for (int j = 0; j < rhs.width(); j++)
                for (int k = 0; k < (*this).width(); k++)
                    ret[i][j] += (*this)[i][k] * rhs[k][j];
        val.swap(ret);
        return *this;
    }
    Matrix2D &operator+=(float rhs) {
        for (int i = 0; i < height(); i++)
            for (int j = 0; j < width(); j++)
                (*this)[i][j] += rhs;
        return *this;
    }
    Matrix2D &operator-=(float rhs) {
        for (int i = 0; i < height(); i++)
            for (int j = 0; j < width(); j++)
                (*this)[i][j] -= rhs;
        return *this;
    }
    Matrix2D &operator*=(float rhs) {
        for (int i = 0; i < height(); i++)
            for (int j = 0; j < width(); j++)
                (*this)[i][j] *= rhs;
        return *this;
    }
    Matrix2D &operator/=(float rhs) {
        for (int i = 0; i < height(); i++)
            for (int j = 0; j < width(); j++)
                (*this)[i][j] /= rhs;
        return *this;
    }

    std::vector<float> &operator[](int i) {
        assert(0 <= i && i < (int)val.size());
        return val[i];
    }

    friend std::ostream &operator<<(std::ostream &os, Matrix2D &mat) {
        for (int i = 0; i < mat.height(); i++) {
            os << "[";
            for (int j = 0; j < mat.width(); j++) {
                os << mat[i][j] << (j + 1 == mat.width() ? "]\n" : ",");
            }
        }
        return (os);
    }
};

Matrix2D operator+(Matrix2D &lhs, Matrix2D &rhs) {
    return Matrix2D(lhs) += rhs;
}
Matrix2D operator-(Matrix2D &lhs, Matrix2D &rhs) {
    return Matrix2D(lhs) -= rhs;
}
Matrix2D operator*(Matrix2D &lhs, Matrix2D &rhs) {
    return Matrix2D(lhs) *= rhs;
}
Matrix2D operator+(Matrix2D &lhs, float rhs) {
    return Matrix2D(lhs) += rhs;
}
Matrix2D operator-(Matrix2D &lhs, float rhs) {
    return Matrix2D(lhs) -= rhs;
}
Matrix2D operator*(Matrix2D &lhs, float rhs) {
    return Matrix2D(lhs) *= rhs;
}
Matrix2D operator/(Matrix2D &lhs, float rhs) {
    return Matrix2D(lhs) /= rhs;
}
bool operator==(Matrix2D &lhs, Matrix2D &rhs) {
    if (lhs.height() != rhs.height() || lhs.width() != rhs.width())
        return false;
    float eps = 1e-5;
    for (int i = 0; i < lhs.height(); i++)
        for (int j = 0; j < lhs.width(); j++)
            if (std::abs(lhs[i][j] - rhs[i][j]) > eps) return false;
    return true;
}
bool operator==(Matrix2D &lhs, std::vector<std::vector<float>> &rhs) {
    auto m = Matrix2D(rhs);
    return lhs == m;
}
}  // namespace nnwc