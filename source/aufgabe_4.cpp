#include "circle.hpp"
#include <set>
#include <algorithm>
using namespace std;

bool exists(set<Circle>& Circles, string& name){ //Prueft ob der Name schon existiert
bool answer = true;
    for (auto& element : Circles) {
        if (element.get_name()== name) {
           cout << "This name is in use already. Restarting...." << "\n"; 
           answer = false;
        } 
    }
    return answer;
}



int main() {
     
    int go_on = 1;
    set<Circle> Circles;

    while (go_on == 1) { //Schleife um das Programm wiederholt ausfuehren zu lassen
    
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

