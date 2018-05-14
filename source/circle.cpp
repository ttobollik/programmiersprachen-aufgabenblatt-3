#define Catch_CONFIG_RUNNER
#include "circle.hpp"
#include <iostream>
#include <cmath>

    Circle::Circle() : radius_{1.0f}, center_{0.0,0.0}, color_{0.0, 0.0, 0.0}{}

    Circle::Circle(float radius, float x, float y): radius_{radius}, center_{x,y}, color_{0.0, 0.0, 0.0} {}

    Circle::Circle(float radius) : radius_{radius}, center_{0.0,0.0},color_{0.0, 0.0, 0.0} {}

    Circle::Circle(float radius, Color color) : radius_{radius}, center_{0.0,0.0}, color_{color} {}

    Circle::Circle(Color color) : radius_{1.0f}, center_{0.0,0.0}, color_{color} {}

    float Circle::get_radius() const{
        return radius_;
    }

    Vec2 Circle::get_center() const{
        return center_;
    }

    Color Circle::get_color() const{
        return color_;
    }

    float Circle::circumference() {
        circumference_ = (2*M_PI*radius_);
        return circumference_;
    }

    void Circle::draw(Window& window) {
        float start_point = center_.x_ - radius_;
        float end_point = center_.x_ + radius_;
        float y = 0.0f;
        for(float x = start_point; x <= end_point; x += 0.1f) {
            //Formel zur Kreisberechnung: (x-center_x)^2+(y-center_y)^2=r^2 
            y = sqrt((radius_ * radius_) - ((x - center_.x_) * (x - center_.x_))); 
            window.draw_point(x,y + center_.y_,color_.r, color_.g, color_.b);
            window.draw_point(x,-y + center_.y_,color_.r, color_.g, color_.b);
        }
    }

    void Circle::draw(Window& window, Color color) {
        float start_point = center_.x_ - radius_;
        float end_point = center_.x_ + radius_;
        float y = 0.0f;
        for(float x = start_point; x <= end_point; x += 0.1f) {
            //Formel zur Kreisberechnung: (x-center_x)^2+(y-center_y)^2=r^2 
            y = sqrt((radius_ * radius_) - ((x - center_.x_) * (x - center_.x_))); 
            window.draw_point(x,y + center_.y_,color.r, color.g, color.b);
            window.draw_point(x,-y + center_.y_,color.r, color.g, color.b);
        }
    }

    bool Circle::is_inside(Vec2 v1) const{
        bool response;
        if(((v1.x_ - center_.x_)*(v1.x_ - center_.x_)+(v1.y_ - center_.y_)*(v1.y_ - center_.y_)) < (radius_ * radius_)) {
            response = true;
        } else {
            response = false;
        }
        return response;
    }