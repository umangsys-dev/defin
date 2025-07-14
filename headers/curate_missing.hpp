#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <vector>
#include "tiny-process-library/process.hpp"
#include <iomanip>

namespace tiny = TinyProcessLib;

std::vector<std::string> get_missing_OR_present(std::vector<std::string>, std::unordered_map<std::string, std::unordered_map<std::string, std::string>>, std::string distro_name, std::string flag);