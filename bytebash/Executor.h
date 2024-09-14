#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <direct.h>
#include <unordered_map>

void cdCommand(const std::string& path)
{
	if (_chdir(path.c_str()) != 0) // This turned to be more C oriented than C++ tbh...
	{
		std::cerr << "Directory not found!" << std::endl;
	}
}

void lsCommand(const std::string&)
{
	system("dir");
}

void pwdCommand(const std::string&)
{
	char cwd[1024];
	if (_getcwd(cwd, sizeof(cwd)) != NULL)
	{
		std::cout << "current working directory: " << cwd << std::endl;
	}
	else
		std::cerr << "specified directory not found!" << std::endl;
}

void helpCommand(const std::string&)
{
	std::cout << "cd - changes directory" << std::endl;
	std::cout << "ls - lists all the files in directory" << std::endl;
	std::cout << "pwd - prints current working director" << std::endl;
	std::cout << "clear - clears the terminal screen" << std::endl;
	std::cout << "exit - exits the shell" << std::endl;
}

void clearCommand(const std::string&)
{
	system("cls");
}

std::unordered_map<std::string, void(*)(const std::string&)> commandMap = // Only a fool would try to implement a thousand (or five) commands using if statements
{
	{"cd", cdCommand},
	{"ls", lsCommand},
	{"pwd", pwdCommand},
	{"help", helpCommand},
	{"clear", clearCommand}
};

void executeCommand(const std::string& input)
{
	std::stringstream ss(input);
	std::string command;
	std::string argument;

	ss >> command;
	std::getline(ss, argument);


	if (!argument.empty() && argument[0] == ' ')
	{
		argument.erase(0, 1);
	}

	auto it = commandMap.find(command);
	if (it != commandMap.end())
	{
		it->second(argument);
	}
	else
		system(input.c_str());
}
