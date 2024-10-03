#pragma once
#include <map>
#include <string>
#include <fstream>
#include <iostream>
//�� ��� ���� ������ ������ ����� ��������� ����� ������� ���������� �� ������� ������(����� ��� ������������) ��� ��������� ���������
//������ � ��� ������ ���������� � ������������� ������� ����� � �� ������� ���� ����������� ���� ������ ����� ���������� �� ��
class GetDictFrequencies
{
	std::map<char, int> dict;

public:
	GetDictFrequencies(std::string path);

	std::map<char, int>& get_dict_frequencies();
};
