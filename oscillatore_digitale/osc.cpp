#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

int main () {

	// input
	int N = 4096;
	float SR = 44100;
	float dur = 5;
	float fxi = 440;
	float fxe = 880;

	// calcoli
	int NSAMP = dur * SR;
	float fn = SR / N;
	float incri = fxi / fn;
	float incre = fxe / fn;
	float incrincr = (incre - incri) / NSAMP;
	float incr = incri;

	cout << "fn = " << fn << endl;
	cout << "incri = " << incri << endl;
	cout << "incre = " << incre << endl;

	vector<float> x (N + 1);

	for (int i = 0; i < N; i = i + 1) {
		x[i] = sin (2. * M_PI * ((float) i / N)); // sin (2pi*f)
	}	
	x[N] = x[0]; // guard point

	ofstream out ("osc.pcm");

	float phi = 0;
	for (int i = 0; i < NSAMP; i = i + 1) {
		//float s = x[(int) phi];
		int index = (int) phi; // parte intera
		float frac = phi - index; // parte frazionaria
		float s = (1. - frac) * x[index] + frac * x[index + 1]; // interpolazione
		out.write ((char*) &s, sizeof (float)); // 32 bit
		phi = phi + incr;
		incr = incr + incrincr;
		// cout << i << " " << incr << endl;
		if (phi > N) phi = phi - N; // wrap di fase
	}
    return 0;
}
