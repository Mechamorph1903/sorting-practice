#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include "header.h"
using namespace std;

int main() {
    cout << "Bubble Sort Result: " << endl;
    Bubble(100);
    Bubble(250);
    Bubble(500);
    Bubble(1000);
    Bubble(2500);
    Bubble(5000);
    Bubble(10000);
    Bubble(25000);
    Bubble(50000);
    Bubble(100000);


    
    cout << endl;

    cout << "Quick Sort Results: " << endl;
    Quick(100);
    Quick(250);
    Quick(500);
    Quick(1000);
    Quick(2500);
    Quick(5000);
    Quick(10000);
    Quick(25000);
    Quick(50000);
    Quick(100000);
   
    return 0;

}



