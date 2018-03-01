#include "Header.h"

int main()
{
	std::string str1, str2;
	std::string filename = cmndlg();
	int lines = countlines(filename);
	std::ifstream check1(filename);
	std::ifstream check2(filename);
	int occurences, bar, temp;
	std::vector<std::string> doubles;
	int vectorlength = 0;
	
	for (int x = 0; x < lines; x++)
	{
		occurences = 0;
		bar = 2;
		temp = 0;
		std::getline(check1, str1);
		for (int y = 0; y < lines; y++)
		{
			std::getline(check2, str2);
			if (str1 == str2)
			{
				occurences++;
			}
			if (occurences = bar)
			{
				if (temp == 0)
				{
					vectorlength++;
					doubles.push_back(str1);
					temp++;
				}
				bar++;
			}
		}
	}

	std::string temp1 = "\\";
	std::string str(filename);
	std::size_t found = str.rfind(temp1);
	std::string outloc = str.substr(0, found + 1);
	outloc = outloc + "output.txt";
	std::ofstream output(outloc);
	for (int x = 0; x < vectorlength; x++)
	{
		output << doubles[x];
	}

	return 0;
}