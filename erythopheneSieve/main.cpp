#include <iostream>
#include <cmath>

int main()
{
	const int limit = 1001;
	int sqrtLimit = ceil(sqrt(limit));
	bool arr[limit] = { false };
	arr[0] = true;
	for (int i = 2; i < sqrtLimit; i++)
	{
		if (!arr[i])
			for (int j = i; j*i <= limit; j++)
				arr[j*i] = true;
	}
	for (int i = 0; i < limit; i++)
		if (!arr[i])
			std::cout << "prime: " << i << std::endl;
}
