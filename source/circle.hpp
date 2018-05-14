
#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle {
  private:
    const float radius_;
    const Vec2 center_;
    Color color_;
    

  
  public:
    float circumference_;
    Circle();
    Circle(float radius, float x, float y);
    Circle(float radius);
    Circle(float radius, Color color);
    Circle(Color color);
    float get_radius() const;
    Vec2 get_center() const;
    float circumference();
    Color get_color() const;
    void draw(Window& window);
    void draw(Window& window, Color color);
    bool is_inside(Vec2 v1) const;

    

};



#endif