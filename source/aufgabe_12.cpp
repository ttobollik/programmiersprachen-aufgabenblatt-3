#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>

    std::vector<int> v_1{1,2,3,4,5,6,7,8,9};
    std::vector<int> v_2{9,8,7,6,5,4,3,2,1};
    std::vector<int> v_3(9);

    bool is_ten(int i) {
        return i == 10;
    }

TEST_CASE("Addition", "[add]") 
{
REQUIRE(std::all_of(v_3.begin(), v_3.end(), is_ten)); 
}

int main(int argc, char* argv[]) {

    auto plus = [](int i, int y) -> int {return i+y;};
    std::transform(v_1.begin(), v_1.end(), v_2.begin(), v_3.begin(), plus);

    for(auto& i : v_3) {
        std::cout << i << "\n";
    }

    return Catch::Session().run(argc, argv);

}