#include <cstdlib>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>

int main () {
    std::vector<int> v_0(10);//Erstellt neuen Vektor mit 10 ints
    for(auto& v : v_0) {
        v = std::rand();
        } //zufaellige Zuweisung von Zahlen in den Vektor
    

std::copy(std::cbegin(v_0), std::cend(v_0), //cbegin const_begin
std::ostream_iterator<int>(std::cout, "\n")); //an die Konsole schicken (kopieren)

std::list<int> l_0(std::cbegin(v_0), std::cend(v_0)); //Liste l0 erstellen mit Werten von v_0
std::list<int> l_1(std::cbegin(l_0), std::cend(l_0)); //Liste l1 erstellen mit Werten von l_0

std::reverse(std::begin(l_1), std::end(l_1)); // dreht Reihenfolge um
std::copy(std::cbegin(l_1), std::cend(l_1), 
std::ostream_iterator<int>(std::cout, "\n")); //an die Konsole schicken (kopieren)

l_1.sort();  //sortieren von l_1
std::copy(   
    l_1.cbegin(),
    l_1.cend(),
    std::ostream_iterator<int>(std::cout, "\n")); //an die Konsole schicken (kopieren)


std::generate(std::begin(v_0), std::end(v_0), std::rand); //neue Zufallszahlen in v_0
std::copy(v_0.crbegin(), v_0.crend(),
std::ostream_iterator<int>(std::cout, "\n")); //an die Konsole schicken (kopieren)

return 0;

}

