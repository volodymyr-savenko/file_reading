// File_read.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>

using std::cout;
using std::cin;


int _tmain(int argc, _TCHAR* argv[])
{
	std::ifstream ifs("data_out.txt");
	std::ofstream ofs("out_data.txt");
	ifs >> std::noskipws;
	std::istream_iterator<char> in_char_iter(ifs);
	std::istream_iterator<char> eos;
	std::ostream_iterator<char> out_file_iter(ofs);
	std::ostream_iterator<char> out_iter(cout);
	std::vector<char> dest_vec;

	if (ifs)
	{
		transform(in_char_iter, eos, out_file_iter, [](const char& ch){
			return toupper(ch);
		});
	}
	else
	{
		cout << "File stream wasn't initialized/n";
	}

	ofs.close();
	ifs.close();

	for_each(dest_vec.begin(), dest_vec.end(), [](char& ch)
	{
		cout << ch;
	});

	std::ifstream ifs2("out_data.txt");

	std::istream_iterator<char> iter2(ifs2);
	std::istream_iterator<char> eos2;
	std::ostream_iterator<char> out(cout);

	if (ifs2)
	{
	  std::copy(iter2, eos2, out);
	}
	else
	{
		cout << "There is a failure of ifs2 initialization\n";
	}
	cout << '\n';
	return 0;
}

