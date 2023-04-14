#include "funcs.h"

using namespace std;

string enterNameOfInputFile()
{
	string input_file_name;
	cout << "Enter name of input file: ";
	cin >> input_file_name;

	return input_file_name;
}

string chooseOpenModeStream()
{
	string file_mode;
	cout << "Choose mode for open file[enter \"a\" or \"w\"]: ";
	cin >> file_mode;

	while (file_mode != "w" && file_mode != "a")
	{
		cout << "You entered incorrect mode. Try again.[enter \"a\" or \"w\"]: ";
		cin >> file_mode;
		cout << "file_mode == " << file_mode;
	}

	return file_mode;
}

void enterInputFile(string input_file_name , string file_mode)
{
	ofstream input_file;
	if (file_mode == "w")
		input_file.open(input_file_name, ios::binary);
	else
	{
		input_file.open(input_file_name, ios::app, ios::binary);

		if (!input_file)
		{
			cout << "Can`t open file!\n";
			return;
		}
	}

	Teleconversation list;

	cin.ignore();

	for (int i = 0; i < MAXSIZE; i++)
	{
		cout << "Enter phone number: ";
		fgets(list.phone_number, MAXSIZE, stdin);

		if (list.phone_number[0] == '\n' || list.phone_number[1] == '\0')
			break;

		list.phone_number[strlen(list.phone_number) - 1] = '\0';
		do
		{
			cout << "Enter begin time[HH:MM]: ";
			scanf_s("%d:%d", &list.begin_h, &list.begin_m);
		} while (!checkInput(list.begin_h, list.begin_m));

		do
		{
			cout << "Enter end time[HH:MM]: ";
			scanf_s("%d:%d", &list.end_h, &list.end_m);

		} while (!checkInput(list.end_h, list.end_m));
		input_file.write((char*)&list, sizeof(Teleconversation));
		cin.ignore();
	}

	input_file.close();
}

bool checkInput(int h, int m)
{
	if (!checkTime(h, m))
	{
		return false;
	}

	return true;
}

bool checkTime(int h, int m)
{
	if (h < 0 || h > 24)
	{
		cout << "You entered incorrect hours! Try again." << endl << endl;
		return false;
	}
	if (m < 0 || m > 59)
	{
		cout << "You entered incorrect minutes! Try again." << endl << endl;
		return false;
	}

	return true;
}

void writeInOutputFile(string input_file_name)
{
	ifstream input_file(input_file_name, ios::binary);

	if (!input_file)
	{
		cout << "Can`t open file!\n";
		return;
	}

	ofstream day_file(DAY_FILE_NAME, ios::binary);
	ofstream night_file(NIGHT_FILE_NAME, ios::binary);

	Teleconversation list;

	while (input_file.read((char*)&list, sizeof(Teleconversation)))
	{
		if (list.begin_h >= 6 && list.begin_h <= 19)
		{
			day_file.write((char*)&list, sizeof(Teleconversation));
		}
		else
		{
			night_file.write((char*)&list, sizeof(Teleconversation));
		}
	}

	night_file.close();
	day_file.close();
	input_file.close();
}

void outputText(string input_file_name)
{
	ifstream input_file(input_file_name, ios::binary);
	if (!input_file)
	{
		cout << "Can`t open file!\n";
		return;
	}
	ifstream day_file(DAY_FILE_NAME, ios::binary);
	if (!input_file)
	{
		cout << "Can`t open file!\n";
		return;
	}
	ifstream night_file(NIGHT_FILE_NAME, ios::binary);
	if (!input_file)
	{
		cout << "Can`t open file!\n";
		return;
	}

	Teleconversation list;

	printTitle("INPUT FILE - ", input_file_name);

	while (input_file.read((char*)&list, sizeof(Teleconversation)))
	{
		cout << list.phone_number << "  " << setw(2) << setfill('0') << list.begin_h << ":" <<setw(2) << setfill('0') << list.begin_m 
			<< "-" << setw(2) << setfill('0') << list.end_h << ":" << setw(2) << setfill('0') << list.end_m << endl;
	}
	cout << endl;

	printTitle("DAY FILE - ", DAY_FILE_NAME);

	while (day_file.read((char*)&list, sizeof(Teleconversation)))
	{
		cout << list.phone_number << "  " << setw(2) << setfill('0') << list.begin_h << ":" << setw(2) << setfill('0') << list.begin_m
			<< "-" << setw(2) << setfill('0') << list.end_h << ":" << setw(2) << setfill('0') << list.end_m << endl;
	}
	cout << endl;

	printTitle("NIGHT FILE - ", NIGHT_FILE_NAME);

	while (night_file.read((char*)&list, sizeof(Teleconversation)))
	{
		cout << list.phone_number << "  " << setw(2) << setfill('0') << list.begin_h << ":" << setw(2) << setfill('0') << list.begin_m
			<< "-" << setw(2) << setfill('0') << list.end_h << ":" << setw(2) << setfill('0') << list.end_m << endl;
	}
	cout << endl;

	night_file.close();
	day_file.close();
	input_file.close();
}

void printTitle(string title_name ,string input_file_name)
{
	string title = title_name + input_file_name;

	printLine(title);
	cout << endl << title << endl;
	printLine(title);
	cout << endl;
}

void printLine(string title)
{
	for (int i = 0; i < title.length(); i++)
		cout << "-";
}












//bool checkColon(char c)
//{
//	if (c != ':')
//	{
//		cout << "You enetered withot \':\'-symbol! Try again." << endl << endl;
//		return false;
//	}
//
//	return true;
//}


	/*int h, m;
	char c;
	string s;*/


	//while (true)
	//{
	//	cout << "Enter phone number: ";
	//	input_file << arr[];
	//	//getline(cin, s);
	//	cout << "Enter  number: ";
	//	input_file << s;

	//	if (s == "\0")
	//		break;

	//	input_file << s << endl;
	//}
