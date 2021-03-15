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
	float fx = 440;

	// calcoli
	int NSAMP = dur * SR;
	float fn = SR / N;

	float incr = fx / fn;

	vector<float> x (N);

	for (int i = 0; i < N; i = i + 1) {
		x[i] = sin (2. * M_PI * ((float) i / N)); // sin (2pi*f)
	}	

	ofstream out ("osc.pcm");

	float phi = 0;
	for (int i = 0; i < NSAMP; i = i + 1) {
		// x[phi] = x[0] = 0
		// phi = phi + incr
		// x[incr + phi] = x[1] = .2
		float s = x[(int) phi];
		 cout << s << endl;
		 out.write ((char*) &s, sizeof (float)); // 32 bit
		 phi = phi + incr;
		 if (phi > N) phi = phi - N; // wrap di fase
	}
    return 0;
}
