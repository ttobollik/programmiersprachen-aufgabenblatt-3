#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>
// TEST_CASE("filter alle vielfache von drei", "[erase]") {
// // ihre Loesung : // ...
// REQUIRE(std::all_of(v.begin(), v.end(), is_multiple_of_3)); }

bool is_multiple_of_3(int i){
    return (i % 3) != 0;
}

int main(int argc, char* argv[]) {

std::vector<unsigned int> no_three(100);
for(auto& i : no_three) {
    i = rand() % 100;
}

no_three.erase(std::remove_if( no_three.begin(), no_three.end(), is_multiple_of_3), no_three.end() ); 

for(auto& i : no_three) {
    std::cout << i << ",";
}

return Catch::Session().run(argc, argv);

}