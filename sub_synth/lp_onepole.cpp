#include <iostream>
#include <cmath>
using namespace std;


int main () {
    float SR = 44100;
    float ST = 1.  / SR;
    float cutoff = 500;

    float omega = 2. * M_PI * cutoff;	
    float b = 2. - cos (omega * ST);

    float b1 = cos (omega * ST) - 2. +  sqrt ((b * b)  - 1.); // feedback (IIR)
    float a0 = 1. + (b1); // feed forward (FIR)

    cout << "a0 = " << a0 << ", b1 = " << b1 << endl;
}