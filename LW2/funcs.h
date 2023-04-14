#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#define DAY_FILE_NAME "day.txt"
#define NIGHT_FILE_NAME "night.txt"
#define MAXSIZE 256

using namespace std;

struct Teleconversation
{
	char phone_number[MAXSIZE];
	int begin_h,
		begin_m,
		end_h,
		end_m;
};

string enterNameOfInputFile();

string chooseOpenModeStream();

void enterInputFile(string input_file_name, string file_mode);

bool checkInput(int h, int m);
bool checkTime(int h, int m);

void writeInOutputFile(string input_file_name);

void outputText(string input_file_name);

void printTitle(string title_name, string input_file_name);
void printLine(string title);