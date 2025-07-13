#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <vector>
#include "tiny-process-library/process.hpp"

namespace tiny = TinyProcessLib;

std::string get_pm(std::unordered_map<std::string, std::unordered_map<std::string, std::string>>);