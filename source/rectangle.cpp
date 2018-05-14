#define Catch_CONFIG_RUNNER
#include "rectangle.hpp"
#include <iostream>
#include <algorithm>
#include "vec2.hpp"
using namespace std;

Rectangle::Rectangle() : min_{0,0}, max_{1,1}, color_{0.0, 0.0, 0.0} {}

Rectangle::Rectangle(Vec2 v1, Vec2 v2) :
    min_{min(v1.x_,v2.x_),min(v1.y_,v2.y_)}, //nimmt minimum-X bzw. Y von beiden Zahlen als min
    max_{max(v1.x_,v2.x_),max(v1.y_,v2.y_)}, //nimmt minimum-X bzw. Y von beiden Zahlen als min
    color_{0.0, 0.0, 0.0} {}

Rectangle::Rectangle(Color color) : min_{0,0}, max_{1,1}, color_{color} {}

Vec2 Rectangle::get_min() {
    return min_;
}

Vec2 Rectangle::get_max() {
    return max_;
}

Color Rectangle::get_color() const{
    return color_;
}

double Rectangle::get_length(){
    double length;
    length = (max_.x_ - min_.x_);
    return length;
}

double Rectangle::get_height(){
    double height;
    height = (max_.y_ - min_.y_);
    return height;
}

float Rectangle::circumference() {
    float length = get_length();
    float height = get_height();
    circumference_ = (2*length + 2*height);
    return circumference_;
}

void Rectangle::draw(Window& window) {
    window.draw_line(min_.x_, min_.y_, min_.x_, max_.y_, color_.r, color_.g, color_.b);
    window.draw_line(min_.x_, max_.y_, max_.x_, max_.y_, color_.r, color_.g, color_.b);
    window.draw_line(max_.x_, max_.y_, max_.x_, min_.y_, color_.r, color_.g, color_.b);
    window.draw_line(min_.x_, min_.y_, max_.x_, min_.y_, color_.r, color_.g, color_.b);
}

void Rectangle::draw(Window& window, Color color) {
    window.draw_line(min_.x_, min_.y_, min_.x_, max_.y_, color.r, color.g, color.b);
    window.draw_line(min_.x_, max_.y_, max_.x_, max_.y_, color.r, color.g, color.b);
    window.draw_line(max_.x_, max_.y_, max_.x_, min_.y_, color.r, color.g, color.b);
    window.draw_line(min_.x_, min_.y_, max_.x_, min_.y_, color.r, color.g, color.b);
}

 bool Rectangle::is_inside(Vec2 v1) {
        bool response;
        if((v1.x_ < max_.x_) && (v1.x_ > min_.x_) && (v1.y_ < max_.y_) && (v1.y_ > min_.y_)) {
            response = true;
        } else {
            response = false;
        }
        return response;
    }