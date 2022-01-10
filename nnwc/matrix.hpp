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
    Matrix2D operator+(Matrix2D &rhs) {
        return (Matrix2D(*this) += rhs);
    }
    Matrix2D operator-(Matrix2D &rhs) {
        return (Matrix2D(*this) -= rhs);
    }
    Matrix2D operator*(Matrix2D &rhs) {
        return (Matrix2D(*this) *= rhs);
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
    Matrix2D operator+(float rhs) {
        return (Matrix2D(*this) += rhs);
    }
    Matrix2D operator-(float rhs) {
        return (Matrix2D(*this) -= rhs);
    }
    Matrix2D operator*(float rhs) {
        return (Matrix2D(*this) *= rhs);
    }
    Matrix2D operator/(float rhs) {
        return (Matrix2D(*this) /= rhs);
    }

    std::vector<float> &operator[](int i) {
        assert(0 <= i && i < (int)val.size());
        return val[i];
    }
};
}  // namespace nnwc