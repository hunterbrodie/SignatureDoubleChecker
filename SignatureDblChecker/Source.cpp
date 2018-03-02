#include "Header.h"

int main()
{
	std::string str;
	std::string filename = comdlg();
	std::ifstream xfilestrm(filename);
	std::vector<std::string> doubles, xfiles;
	std::vector<int> amnt;
	int length = 0;
	int check, checkbar;
	bool check2 = true;
	int dblength = 0;
	doubles.push_back("Names that were there twice");

	for (int x = 0; x < 10000; x++)
	{
		amnt.push_back(0);
	}
	if (xfilestrm.is_open())
	{
		while (xfilestrm.good())
		{
			std::getline(xfilestrm, str);
			xfiles.push_back(str);
			length++;
		}
	}
	for (int x = 0; x < length; x++)
	{
		check = 0;
		check2 = true;
		for (int y = 0; y < length; y++)
		{
			if (xfiles[x] == xfiles[y])
			{
				check++;
			}
		}
		if (check > 1)
		{
			for (int z = 0; z < dblength; z++)
			{
				if (doubles[z] == xfiles[x])
				{
					amnt[z] = check;
					check2 = false;
				}
			}
			if (check2)
			{
				doubles.push_back(xfiles[x]);
				dblength++;
				amnt[dblength] = check;
			}
		}
	}

	std::string temp = "\\";
	std::string str1(filename);
	std::size_t found = str1.rfind(temp);
	std::string outloc = str1.substr(0, found + 1);
	outloc = outloc + "output.txt";
	std::ofstream output(outloc);
	output << doubles[0] << "\n";
	for (int x = 1; x < dblength; x++)
	{
		output << doubles[x] << " " << amnt[x] << "\n";
	}
	output << "There were " << length << " amount of lines.";

	return 0;
}