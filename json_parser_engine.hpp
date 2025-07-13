#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <vector>
#include <unordered_map>


namespace jpeng{

	std::unordered_map<std::string, std::string> parse(std::unordered_map<std::string, std::string>, std::string, const std::regex);
}