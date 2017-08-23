#include <iostream>
#include <cmath>

bool isPrime(int n)
{
	if (n==1) return false;
	else if (n < 4) return true;
	else if (n % 2 == 0) return false;
	else if (n < 9) return true;
	else if (n % 3 == 0) return false;
	else
	{
		int r = floor(sqrt(n));
		int f = 5;	
		while (f <= r)
		{
			if (n % f == 0) return false;
			if (n % (f+2) == 0) return false;
			f += 6;
		}
		return true;
	}
}

int main()
{
	int limit = 2000000;
	long int sum = 2;
	int count = 1;
	int candidate = 1;
	for (; candidate <= limit; )
	{
		candidate += 2;
		if (isPrime(candidate)) 
		{
			count++;
			sum += candidate;
//			std::cout << candidate << std::endl;
		}
	}
	std::cout << sum << std::endl;
}
