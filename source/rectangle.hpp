
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"
// #include "window.hpp"

class Rectangle {
  private:
   Vec2 min_;
   Vec2 max_;
   Color color_;

  public:
    Rectangle();
    Rectangle(Vec2 v1, Vec2 v2);
    Rectangle(Color color);
    Vec2 get_min(); // CONST NICHT VERGESSEN
    Vec2 get_max();
    double get_length();
    double get_height();
    float circumference_;
    float circumference();
    Color get_color() const;
    // void draw(Window& window);
    // void draw(Window& window, Color color);
    bool is_inside(Vec2 v1);
};

#endif