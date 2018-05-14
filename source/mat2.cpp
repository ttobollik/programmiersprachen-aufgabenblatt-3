#include "mat2.hpp"
#include "vec2.hpp"
#include <cmath>
#include <iostream>


Mat2::Mat2() : 
  arr{{1,0,0,1}} {}

Mat2::Mat2(double a, double b, double c, double d) :
  arr{{a,b,c,d}} {}


Mat2& Mat2 :: operator*=(Mat2 const& m) {
    Mat2 m1{*this};
    arr[0] = ((m1.arr[0] * m.arr[0]) + (m1.arr[1] * m.arr[2]));
    arr[1] = ((m1.arr[0] * m.arr[1]) + (m1.arr[1] * m.arr[3]));
    arr[2] = ((m1.arr[2] * m.arr[0]) + (m1.arr[3] * m.arr[2]));
    arr[3] = ((m1.arr[2] * m.arr[1]) + (m1.arr[3] * m.arr[3]));
    return *this;
}


Mat2 operator*(Mat2 const& m1, Mat2 const& m2) {
    Mat2 sum_multiply{m1};
    sum_multiply*=m2;
    return sum_multiply;
}

Vec2 operator*(Mat2 const& m, Vec2 const& v) {
    Vec2 vec_multiply;
    vec_multiply.x_ = (m.arr[0]*v.x_)+(m.arr[1]*v.y_);
    vec_multiply.y_ = (m.arr[2]*v.x_)+(m.arr[3]*v.y_);
    return vec_multiply;
}

Vec2 operator*(Vec2 const& v, Mat2 const& m){
    Vec2 vec_multiply;
    vec_multiply.x_ = (m.arr[0]*v.x_)+(m.arr[1]*v.y_);
    vec_multiply.y_ = (m.arr[2]*v.x_)+(m.arr[3]*v.y_);
    return vec_multiply;
}

float Mat2::det() const {
  float det = (arr[0]*arr[3])-(arr[2]*arr[1]);
  return det;
}

Mat2 inverse(Mat2 const& m) {
    double det = m.det();
    Mat2 m1{m};
    if (det!= 0) {
        m1.arr[0]= (1/det)*(m.arr[3]);
        m1.arr[1]= (1/det)*(m.arr[1])*(-1);
        m1.arr[2]= (1/det)*(m.arr[2])*(-1);
        m1.arr[3]= (1/det)*(m.arr[0]);
    } else {
        std :: cout << "This Matrix doesn't have an inverse \n";
    }
     return m1;
}

Mat2 transpose(Mat2 const& m) {
    Mat2 mTrans;
    mTrans.arr[0]= (m.arr[0]);
    mTrans.arr[1]= (m.arr[2]);
    mTrans.arr[2]= (m.arr[1]);
    mTrans.arr[3]= (m.arr[3]);
    return mTrans;
}

Mat2 make_rotation_mat2(float phi) {
    Mat2 mRotate;
    mRotate.arr[0]= cos(phi);
    mRotate.arr[1]= -sin(phi);
    mRotate.arr[2]= sin(phi);
    mRotate.arr[3]= cos(phi);
    return mRotate;
}




