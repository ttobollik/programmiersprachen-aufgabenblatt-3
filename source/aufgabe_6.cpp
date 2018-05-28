#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "color.hpp"
#include "circle.hpp"
#include <algorithm>
#include <vector>
#include <iostream>



//Aufgabe 3.8

struct smaller_then {
    bool operator() (Circle const& c1, Circle const& c2) {
        return c1.get_radius() < c2.get_radius();
    }
};


//Aufgabe 3.6

//Kreiserstellung  
  Circle moon(1, "moon");
  Circle saturn(2, "saturn");
  Circle mars(3, "mars");
  std::vector<Circle> sorted_circles{moon, saturn, mars};


TEST_CASE("sortierte Zahlen", "[sort]") {
REQUIRE(std::is_sorted(sorted_circles.begin(), sorted_circles.end()));
}

int main(int argc, char *argv[])
{ 

 std::sort(sorted_circles.begin(), sorted_circles.end());

 //Aufgabe 3.7 - Lambda
  auto comparator = [](Circle const& c1, Circle const& c2) -> bool { return c1.get_radius() < c2.get_radius();};
  sort(sorted_circles.begin(), sorted_circles.end(), comparator);

//Aufgabe 3.8 - Funktor
 smaller_then fn;
 sort(sorted_circles.begin(), sorted_circles.end(), smaller_then());

return Catch::Session().run(argc, argv);

}
