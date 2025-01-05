#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool is_vampire(int n, int& fang1, int& fang2) {
    for (int i = 10; i < 100; i++) {
        if (n % i == 0) {
            int j = n / i;
            if (to_string(j).size() == 2) {
                string num1 = to_string(i) + to_string(j);
                string num2 = to_string(n);

                sort(num1.begin(), num1.end());
                sort(num2.begin(), num2.end());

                if (num1 == num2) {
                    fang1 = i;
                    fang2 = j;
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    cout << "Vampire numbers between 1,000 and 10,000:" << endl;
	int amount = 1;
	
    for (int i = 1000; i < 10000; i++) {
        int fang1 = 0, fang2 = 0;
        if (is_vampire(i, fang1, fang2)) {
            cout << amount << ") " << i << ": " << fang1 << " * " << fang2 << endl;
        	amount++;
        }
    }

    return 0;
}
