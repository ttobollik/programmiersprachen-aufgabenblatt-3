#include <list> 
#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {

// Liste erstellen und mit Zufallszahlen fuellen    
list<unsigned int> numbers(100);

list<unsigned int>::iterator i = numbers.begin();

for(numbers.begin(); i != numbers.end(); ++i) {
    *i = rand() % 100 + 1; 
}

//Zahlen von 0-100 ins Set
set<unsigned int> leftover_numbers;
for(int j = 0; j <= 100; ++j) {
    leftover_numbers.insert(j);
}

//Set mit allen Zahlen, die in der Liste sind
set<unsigned int> list_numbers; //In diesem Set wird jedes existierende Element einmal gespeichert, kein Null-Pointer
for(auto& element: numbers) {
    list_numbers.insert(element);
}

//Element loeschen, wenn es in der Liste gefunden ist
for(auto& element: list_numbers) {
    leftover_numbers.erase(leftover_numbers.find(element)); 
}

//Ausgaben
for(set<unsigned int>::iterator i = leftover_numbers.begin(); i != leftover_numbers.end(); ++i) {
    cout << *i << ", ";
}

cout << "Die Liste enthaelt: " << list_numbers.size() << " Elemente";

//3.3 map erstellen und füllen
map<int, int> occurence;

for(auto& element: list_numbers){
    occurence[element] = 0;
}

for(auto& element: numbers) {
    occurence[element]+=1;
}

for(auto& element: occurence) {
    cout << element.first << " : " << element.second << ". \n";
}

return 0;
}