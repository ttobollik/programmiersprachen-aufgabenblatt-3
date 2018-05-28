#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>

//neuer Vektor
std::vector<unsigned int> all_three(100);


//Methode fuer Test
bool is_multiple_of_3(int i){
    return (i % 3) == 0;
}

//Methode fuer Aufruf
bool is_not_multiple_of_3(int i){
    return (i % 3) != 0;
}

TEST_CASE("filter alle vielfache von drei", "[erase]") {

REQUIRE(std::all_of(all_three.begin(), all_three.end(), is_multiple_of_3)); }



int main(int argc, char* argv[]) {

//neuer Vektor mit Zufallszahlen
std::vector<unsigned int> no_three(100);
for(auto& i : no_three) {
    i = rand() % 100;
}

//Loeschen von Elementen, die durch drei teilbar sind
no_three.erase(std::remove_if( no_three.begin(), no_three.end(), is_not_multiple_of_3), no_three.end() ); 

for(auto& i : no_three) {
    std::cout << i << ",";
}

//Loeschen von Elementen, die nicht durch drei teilbar sind
for(auto& i : all_three) {
    i = rand() % 100;
}
all_three.erase(std::remove_if( all_three.begin(), all_three.end(), is_not_multiple_of_3), all_three.end() );

return Catch::Session().run(argc, argv);

}

