#define Catch_CONFIG_RUNNER
#include "vec2.hpp"

#include <iostream>

//Aufgabe 2.2
Vec2::Vec2()
    : x_{0}, y_{0} {}

Vec2::Vec2(float vec_x, float vec_y)
    : x_{vec_x}, y_{vec_y} {} 

//Aufgabe 2.3
Vec2&
Vec2::operator+=(Vec2 const& v) {
    x_ += v.x_;
    y_ += v.y_;
    return *this;
}

Vec2&
Vec2::operator-=(Vec2 const& v) {
    x_ -= v.x_;
    y_ -= v.y_;
    return *this;
}

Vec2&
Vec2::operator*=(float s) {
    x_ *= s;
    y_ *= s;
    return *this;
}

Vec2&
Vec2::operator/=(float s) {
    if (s != 0) {
     x_ /= s;
     y_ /= s;
    } else {
        std :: cout << "Teilen durch Null fuehrt zum Weltuntergang \n";
    }
    return *this;
}

//Aufgabe 2.4
Vec2 operator+(Vec2 const& u, Vec2 const& v){
    Vec2 vec_test;
    vec_test.x_ = (u.x_ + v.x_);
    vec_test.y_ = (u.y_ + v.y_);
    return vec_test;
} 

Vec2 operator-(Vec2 const& u, Vec2 const& v){
    Vec2 vec_test;
    vec_test.x_ = (u.x_ - v.x_);
    vec_test.y_ = (u.y_ - v.y_);
    return vec_test;
} 

Vec2 operator*(Vec2 const& v, float s) {
    Vec2 vec_test{v};
    vec_test*=s;
    return vec_test;
}

Vec2 operator/(Vec2 const& v, float s) {
    Vec2 vec_test{v};
    vec_test /= s;
    return vec_test;
}

Vec2 operator*(float s, Vec2 const& v) {
    return v*s;
}

bool operator==(Vec2 const& u, Vec2 const& v) {
    return ((u.x_ == v.x_) && (v.y_ == u.y_))?true:false;
}

std::ostream& operator<<(std::ostream &strm, const Vec2 &vec) {
  return strm << "{" << vec.x_ << "," << vec.y_ << "}";
}

Vec2::~Vec2(){} // Wird benötigt, wenn das Objekt Ressourcen anfordert. Zerstörbt Objekt nach Benutzung und gibt Ressourcen frei. Hier nicht zwingend notwendig.
