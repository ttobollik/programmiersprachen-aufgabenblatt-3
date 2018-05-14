#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "rectangle.hpp"
#include "circle.hpp"
#include "vec2.hpp"
#include "color.hpp"


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};
  

  //red examples
  Vec2 v1{60,85};
  Vec2 v2{30,53};
  Rectangle rec{v1, v2};
  Circle circ{100.0f, 400.0f, 400.0f};

  //color example
  Color col{0.0f, 0.5f, 0.5f};
  Vec2 v3{140,200};
  Vec2 v4{40,52};
  Rectangle rec1{v3, v4};
  Circle circ1{300.0f, 300.0f, 300.0f};
  

  Circle clock{50, 600, 600};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1{400 + 380 * std::sin(t)};
    float y1{400 + 380 * std::cos(t)};

    float x2{400 + 380 * std::sin(2.0f*t)};
    float y2{400 + 380 * std::cos(2.0f*t)};

    float x3{400 + 380 * std::sin(t-10.f)};
    float y3{400 + 380 * std::cos(t-10.f)};

    win.draw_point(x1, y1,
        1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto m = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30, 30, // from
          m.first, m.second, // to
          1.0,0.0,0.0);
    }

    win.draw_line(0, m.second, 10, m.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, m.second, win.window_size().second, m.second, 0.0, 0.0, 0.0);

    win.draw_line(m.first, 0, m.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(m.first, win.window_size().second - 10, m.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string text = "mouse position: (" + std::to_string(m.first) + ", " + std::to_string(m.second) + ")";
    win.draw_text(10, 5, 35.0f, text);

    rec.draw(win);
    circ.draw(win);

    //Color col{float(m.first/800.0), float((m.first + m.second)/1600.0), float(m.second/800.0)};

    
    
    Color blue(0.0, 0.0, 1.0);
    Vec2 mouse_pos;
    mouse_pos.x_ = float(m.first);
    mouse_pos.y_ = float(m.second);

    if(rec1.is_inside(mouse_pos) == true) {
      rec1.draw(win, blue);
    } else {
      rec1.draw(win, col);
    }
    if(circ1.is_inside(mouse_pos) == true) {
      circ1.draw(win, blue);
    } else {
      circ1.draw(win, col);
    }
   
    clock.draw(win);
    win.draw_line(clock.get_center().x_, clock.get_center().y_, clock.get_center().x_ + 40 * std::sin(t * M_PI / 30), clock.get_center().y_ + 40 * -std::cos(t * M_PI / 30), 1.0, 0.0, 0.0);
    win.draw_line(clock.get_center().x_, clock.get_center().y_, clock.get_center().x_ + 30 * std::sin(t * M_PI / 1800), clock.get_center().y_ + 30 * -std::cos(t * M_PI / 1800), 1.0, 0.5, 0.0);
    win.draw_line(clock.get_center().x_, clock.get_center().y_, clock.get_center().x_ + 20 * std::sin(t* M_PI / 21600), clock.get_center().y_ + 20 * -std::cos(t/21600), 0.8, 0.8, 0.0);


    std::string time = "Vergangene Zeit (" + std::to_string(t) + ")";
    win.draw_text(50, 500, 35.0f, time);
    
    win.update();
  }

  return 0;
}
