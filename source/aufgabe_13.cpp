#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <iterator>


template <typename T, typename F>
T filter(T const& obj1, F booleanF) {
   T result; 
   //std::copy_if(obj1.begin(), obj1.end(), result.begin(), booleanF); ADRIAN FRAGEN-- warum?
   for(auto& i : obj1) {
       if (booleanF(i) == true) {
           result.push_back(i);
       }
   }
   return result;
}

bool is_even(int n) {
    return n % 2 == 0;
    }
    
std::vector<int> v{1,2,3,4,5,6};
std::vector<int> all_even = filter(v, is_even);

TEST_CASE("filter alle geraden Zahlen", "[even]") {

REQUIRE(std::all_of(all_even.begin(), all_even.end(), is_even));
}


int main(int argc, char* argv[]) {
     for(auto& i : all_even) {
        std::cout << i << ", ";
    }
    
    return Catch::Session().run(argc, argv);

   

}


