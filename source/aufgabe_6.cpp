// #define CATCH_CONFIG_RUNNER
// #include <catch.hpp>
#include "color.hpp"
#include "circle.hpp"
#include <algorithm>
#include <vector>
#include <iostream>



//Aufgabe 3.8

// struct smaller_then {
//     bool operator() (Circle c1, Circle c2) {
//         return c1.get_radius() < c2.get_radius();
//     }
// };

struct Rectangle{
    float radius_;
    std::string name_;
};

int main(int argc, char *argv[])
{

//Aufgabe 3.6
  std::vector<Circle> sorted_circles;
  Circle moon(1, "moon");
  sorted_circles.push_back(moon);
  Circle saturn(2, "saturn");
  sorted_circles.push_back(saturn);
  Circle mars(3, "mars");
  sorted_circles.push_back(mars);


  std::swap(moon, saturn);
//  auto comparator = [](Circle const& c1, Circle const& c2) -> bool { return c1.radius_ < c2.radius_;};

  //std::sort(sorted_circles.begin(), sorted_circles.end(), comparator);

//   return Catch::Session().run(argc, argv);
    return 0;
//Aufgabe 3.7
  //sort(sorted_circles.begin(), sorted_circles.end(), [](Circle c1, Circle c2){c1.get_radius() > c2.get_radius()});

//Aufgabe 3.8
 //smaller_then fn;
 //sort(sorted_circles.begin(), sorted_circles.end(), smaller_then());

}
