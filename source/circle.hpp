
#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include <set>
#include <iostream>
#include <string>


class Circle {
  private:
    float radius_;
    Vec2 center_;
    Color color_;
    std::string name_;
  
  public:
    float circumference_;
    Circle();
    Circle(std::string const& name_);
    Circle(float radius);
    Circle(float radius, float x, float y, std::string const& name_);
    Circle(float radius, std::string const& name_);
    Circle(float radius, Color const& color, std::string const& name_);
    Circle(Color const& color, std::string const& name_);
    
    float get_radius() const;
    Vec2 get_center() const;
    float circumference();
    Color get_color() const;
    bool is_inside(Vec2 const& v1) const;
    std::ostream& print(std::ostream& os) const;
    std::string const& get_name() const;
    //bool operator<(const Circle& c1) const;
};

std::ostream& operator<<(std::ostream& os, Circle const& c);
bool operator<(Circle const& c1, Circle const& c2); //Operatoren ueberladen
bool operator>(Circle const& c1, Circle const& c2); //Operatoren ueberladen
bool operator==(Circle const& c1, Circle const& c2); //Operatoren ueberladen



#endif