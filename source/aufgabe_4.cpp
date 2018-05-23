#include "circle.hpp"
#include <set>
#include <algorithm>
using namespace std;

bool exists(set<Circle>& Circles, string& name){ //TESTEN, KLAPPT NICHT
    for (auto& element : Circles) {
        if (element.get_name()== name) {
           cout << "This name is in use already. Restarting...." << "\n"; 
           return false;
        } 
    }
    return true;
}



int main() {
     
    int go_on = 1;
    set<Circle> Circles;

    while (go_on == 1) {
    
    string circle_name;
    cout << "Please enter a name for the circle you want to create" << "\n";
    cin >> circle_name;
    if(exists(Circles, circle_name) == true) {
        Circle c1(circle_name);
        Circles.insert(c1);
        cout << "here is your: " << c1 << " \n";
        cout << "Would you like to create another fancy circle? Enter 1 for yes, any other key will quit the programm " << "\n";
        cin >> go_on;
    } else {
        go_on = 1;
    }

    }

    
}

