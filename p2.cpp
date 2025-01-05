#include <iostream>
#include <math.h>
using namespace std;

bool is_prime(int num) {
	
	for (int i=2; i<=sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	
	for (int i=101; i <= 997; i+=2) {
		
		if (is_prime(i) && is_prime(i+2)) {
			cout << "(" << i << ", " << i+2 << ")  ";
		}
	}
	
	return 0;
}