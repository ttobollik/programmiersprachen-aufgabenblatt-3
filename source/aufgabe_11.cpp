#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>


std::vector<unsigned int> all_three(100);

bool is_multiple_of_3(int i){
    return (i % 3) == 0;
}

bool is_not_multiple_of_3(int i){
    return (i % 3) != 0;
}

TEST_CASE("filter alle vielfache von drei", "[erase]") {

REQUIRE(std::all_of(all_three.begin(), all_three.end(), is_multiple_of_3)); }



int main(int argc, char* argv[]) {

std::vector<unsigned int> no_three(100);
for(auto& i : no_three) {
    i = rand() % 100;
}

no_three.erase(std::remove_if( no_three.begin(), no_three.end(), is_not_multiple_of_3), no_three.end() ); 

for(auto& i : no_three) {
    std::cout << i << ",";
}

//
for(auto& i : all_three) {
    i = rand() % 100;
}
all_three.erase(std::remove_if( all_three.begin(), all_three.end(), is_not_multiple_of_3), all_three.end() );
 
return Catch::Session().run(argc, argv);

}