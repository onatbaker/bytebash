#include <iostream>
#include "Executor.h"

int main()
{
	std::string command;

	while (true)
	{
		std::cout << "bytebash >> ";
		std::cin >> command;

		if (command == "exit")
		{
			break;
		}
		else
			executeCommand(command);
	}
	return 0;
}