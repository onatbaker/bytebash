#pragma once
#include <vector>
#include <sstream>

std::vector<std::string> parseCommand(const std::string& input)
{
	std::vector<std::string> tokens;
	std::stringstream ss(input);
	std::string token;

	while (ss >> token)
	{
		tokens.push_back(token);
	}

	return tokens;
}

// this header file is excluded.