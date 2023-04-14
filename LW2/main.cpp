#include <iostream>
#include "funcs.h"

int main(void)
{
	string input_file_name = enterNameOfInputFile();

	string file_mode = chooseOpenModeStream();

	enterInputFile(input_file_name, file_mode);
	writeInOutputFile(input_file_name);
	outputText(input_file_name);

	return 0;
}