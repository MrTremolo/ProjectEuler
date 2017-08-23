#include <iostream>
#include <vector>

int reverse(int n)
{
	int result = 0;
	while (n != 0)
	{
		result = result * 10 + n % 10;
		n = n / 10;
	}
	return result;
}

bool isPol(int n)
{
	return n == reverse(n);
}
// Based on the fast multiplication algorithm of numbers
// Namely, the division of the multiplied 6-digits number into two halves of 3-digits
// 998 * 976 = (1000-2)*(1000-24) = 1000000 - 2000 - 24000 + 48 = 1000000 - 24000 + 48 = 974000 + 48
// a = 2, b = 24, 974 = 1000 - 24 - 2, 48 = a * b
std::vector<int> pol()
{
	// dif - sum of differences between 1000 and factor (1000 - firstFactor + 1000 - secondFactor)
	// 1800 is for don't looping if function isn't work correctly 
	// 1000 - 100 + 1000 - 100 = 1800 - max sum of differences of two 3-digit numbers
	for (int dif = 2; dif != 1800; dif++)  
	{
		// a - difference between first factor and 1000
		// b - difference between second factor and 1000
		// Go over different factors
		for (int a = 1, b = dif - 1; a <= b; ++a, --b)
		{
			// firstThree - first three digits of multiplied number
			// secondThree - second three digits of multiplied number
			int firstThree = 1000 - a - b;
			int secondThree = a * b;
			if (secondThree > 1000)
				firstThree += secondThree / 1000;

			// Check if this is polyndrom
			if (reverse(secondThree) == firstThree)
				// This is polyndrom
				return std::vector<int>{ 1000 - a, 1000 - b, firstThree * 1000 + secondThree};
		}
	}

	// If function passed all numbers (for bad try)
	return std::vector<int>();
}

int main()
{
	std::vector<int> a = pol();
	if (a.size())
		std::cout << a[0] << " x " << a[1] << " = " << a[2] << std::endl;
}


