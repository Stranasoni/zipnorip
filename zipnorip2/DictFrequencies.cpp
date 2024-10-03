#include "DictFrequencies.h"

std::map<char, int>& GetDictFrequencies::get_dict_frequencies()
{
	return dict;
}

GetDictFrequencies::GetDictFrequencies(std::string path)
{
	std::ifstream f(path);
	if (f.is_open())
	{
		char ch;
		while (f.get(ch))
		{
			++dict[ch];
		}
	}
	f.close();
}

