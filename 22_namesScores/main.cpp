#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

int main()
{
	std::string str;	
	std::vector<std::string> vec;
	std::ifstream fin;
	fin.open("p022_names.txt");
	char c;
	bool b = false;

	while (true)
	{
		c = fin.get();	
		if (!b)
		{
			if (c == EOF)
			{
				break;
			}
			else if (c == '"')
			{
				b = true;
			}
		}
		else 
		{
			if (c == EOF)
			{
				vec.push_back(str);
				str.clear();
				break;
			}
			else if (c == '"')
			{
				vec.push_back(str);	
				str.clear();
				b = false;
			}
			else 
			{
				str += c;		
			}
		}
	}

//	fin >> str;	
	fin.close();
//	for (int i = 0; str[i];)
//	{
//		++i;
//		int k = str.find_first_of('"', i);
//		vec.push_back(str.substr(i, k-i));
//		i += k-i+2;
//	}
	std::sort(vec.begin(), vec.end());
	int globalSum = 0;
	auto iter = vec.begin();
	for (int i = 0; iter != vec.end() ; i++, iter++)
	{
		for (int j = 0; j < iter->size(); j++)
		{
			globalSum += ((*iter)[j] - 'A' + 1) * (i+1);
		}
	}
	std::cout << globalSum << std::endl;
}
