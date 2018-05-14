#ifndef MAT2_HPP
#define MAT2_HPP
#include <array>
#include "vec2.hpp"

struct Mat2 { 
    std::array<double, 4> arr;
    Mat2();
    Mat2(double first, double second, double third, double fourth);
    Mat2& operator*=(Mat2 const& m);
    float det() const;

};

Mat2 operator*(Mat2 const& m1, Mat2 const& m2);

Vec2 operator*(Mat2 const& m, Vec2 const& v);
Vec2 operator*(Vec2 const& v, Mat2 const& m);
Mat2 inverse(Mat2 const& m);
Mat2 transpose(Mat2 const& m);
Mat2 make_rotation_mat2(float phi);

#endif