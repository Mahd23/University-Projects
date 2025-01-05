#include <iostream>
#include <vector>
#include <string>
using namespace std;

string factorial(int);

int main()
{
	int number;
	cout << "Enter a number to calculate factorial: ";
	cin >> number;

	while (number < 0)
	{
		cout << endl
			 << "Your number must be a non-negative integer...\nTry again:  ";
		cin >> number;
	}

	// Calculate the factorial once
	string result = factorial(number);

	// Display the result and the number of digits
	cout << "\n" << "Factorial of " << number << ": " << result << "\n\n";
	cout << "Number of digits: " << result.size() << "\n";

	return 0;
}

// ———————— Functions ————————

string factorial(int number)
{
	if (number == 0) return "1";
	
	vector<int> result(1, 1);

	for (int num = 2; num <= number; num++)
	{
		int overflow = 0;

		for (int i = 0; i < result.size(); i++)
		{
			int multiplicationResult = (result[i] * num) + overflow;
			result[i] = multiplicationResult % 10;
			overflow = multiplicationResult / 10;
		}

		while (overflow)
		{
			result.push_back(overflow % 10);
			overflow /= 10;
		}
	}

	// Convert the result vector to string in reverse order
	string factorial_result = "";
	for (int j = result.size() - 1; j >= 0; j--)
	{
		factorial_result += to_string(result[j]);
	}

	return factorial_result;
}
