#pragma once
#include <map>
#include <string>
#include <fstream>
#include <iostream>
//ок это было быстро теперь нужно построить класс который высчитывал бы словарь частот(помни про элегантность) для алгоритма хаффимана
//кстати я еще хотела поработать с изображениями поэтому класс а не функция пока ограничимся этим важнее потом переписать на си
class GetDictFrequencies
{
	std::map<char, int> dict;

public:
	GetDictFrequencies(std::string path);

	std::map<char, int>& get_dict_frequencies();
};
