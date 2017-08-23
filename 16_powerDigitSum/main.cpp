#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec;
	vec.push_back(2);
	for (int i = 1; i < 1000; i++)
	{
		int carry = 0;
		int limit = vec.size();
		for (int j = 0; j < limit; j++)
		{
			int prod = vec[j] * 2;
			vec[j] = prod % 10;
			if (carry)
			{
				++vec[j];
				carry = 0;
			}
			if (prod >= 10)
				if (j == limit-1)	
					vec.push_back(1);	
				else
					carry = 1;
		}
	}
	int sum = 0;
	std::cout << "number: ";
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i];
		sum += vec[i];
	}
	std::cout << "\n" << sum << std::endl;
}
