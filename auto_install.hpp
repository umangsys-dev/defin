#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <filesystem>
#include <sstream>
#include "tiny-process-library/process.hpp"

namespace tiny = TinyProcessLib;

std::vector<std::string> install(std::vector<std::string>, std::unordered_map<std::string, std::unordered_map<std::string, std::string>>, std::string);