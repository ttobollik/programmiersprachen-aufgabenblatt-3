#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "circle.hpp"
#include <algorithm>




    std::vector<Circle> circles{{5.0f},{3.0f},{8.0f},{1.0f},{5.0f}};
    auto three = [] (Circle const& i) -> bool {return i.get_radius() > 3;};

    auto four = [] (Circle const& i) -> bool {return i.get_radius() >= 4;};
    std::vector <Circle>sorted_vec;
    std::copy_if(circles.begin(), circles.end(), sorted_vec.begin(), four);

    TEST_CASE("filter Zahlen größer drei", "[even]") {

        REQUIRE(std::all_of(sorted_vec.begin(), sorted_vec.end(), three));
    }

int main(int argc, char* argv[]) {





    return Catch::Session().run(argc, argv);
}


