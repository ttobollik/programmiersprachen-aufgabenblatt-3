#define Catch_CONFIG_RUNNER
#include "circle.hpp"
#include <iostream>
#include <cmath>

    Circle::Circle() : radius_{1.0f}, center_{0.0,0.0}, color_{0.0, 0.0, 0.0}, name_{"my_circle"}{}

    Circle::Circle(float radius) : radius_{radius}, center_{0.0,0.0}, color_{0.0, 0.0, 0.0}, name_{"my_circle"}{}

    Circle::Circle(std::string const& name_) : radius_{1.0f}, center_{0.0,0.0}, color_{0.0, 0.0, 0.0}, name_{name_}{}

    Circle::Circle(float radius, float x, float y, std::string const& name_): radius_{radius}, center_{x,y}, color_{0.0, 0.0, 0.0}, name_{name_} {}

    Circle::Circle(float radius, std::string const& name_) : radius_{radius}, center_{0.0,0.0},color_{0.0, 0.0, 0.0}, name_{name_} {}

    Circle::Circle(float radius, Color const& color, std::string const& name_) : radius_{radius}, center_{0.0,0.0}, color_{color}, name_{name_} {}

    Circle::Circle(Color const& color, std::string const& name_) : radius_{1.0f}, center_{0.0,0.0}, color_{color}, name_{name_} {}

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

    bool Circle::is_inside(Vec2 const& v1) const{
        bool response;
        if(((v1.x_ - center_.x_)*(v1.x_ - center_.x_)+(v1.y_ - center_.y_)*(v1.y_ - center_.y_)) < (radius_ * radius_)) {
            response = true;
        } else {
            response = false;
        }
        return response;
    }


//Aufgabenblatt 3 

//Aufgabe 3.4
    std::ostream& operator<<(std::ostream& os, Circle const& c) {
        c.print(os);
      return os;
    }

    std::ostream& Circle::print(std::ostream& os) const {
        os << "Kreisinformation:" << radius_ << "\n Color: (" << color_.r << ", " << color_.g <<  ", " << color_.b << ")\n Position: (" << center_ << ")\n Name: " << name_ << "\n" ;
        return os;
    }

    std::string const& Circle::get_name() const {
        return name_;
    }

//Operatoren ueberladen
    bool operator<(Circle const& c1, Circle const& c2) {
        return c1.get_radius()< c2.get_radius();
    }

    bool operator>(Circle const& c1, Circle const& c2) {
        return c1.get_radius()> c2.get_radius();
    }

    bool operator==(Circle const& c1, Circle const& c2) {
        if(c1.get_radius() == c2.get_radius()) {
            return true;
        } else {
            return false;
        }
    }


